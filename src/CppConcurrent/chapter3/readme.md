# Sharing data between thread

## One key problem - Data race

Data Race: If multiple threads access the same piece of memory, with any one of them modifying the data, it will cause undefined behaviour. This can lead to data lose, logical error and many other fatal issues.

> Problematic race conditions typically occur where completing an operation requires modification of two or more distinct pieces of data.

### General Solutions

> Wrap your data structure with a protection mechanism to ensure that only the thread performing a modification can see the intermediate states where the invariants are broken.

- mutex

> Modify the design of your data structure and its invariants so that modifications are done as a series of indivisible changes, each of which preserves the invariants.

- lock-free programming

> Handle the updates to the data structure as a transaction, just as updates to a database are done within a transaction.

- STM (software transactional memory)

## Mutex

Mutex(mutual exclusion): A synchronization primitive used to indicate the which thread has the ownership of data. When using it, the active thread **locks** the mutex whenever it's accessing the shared data. While the mechanics of mutex ensures that each mutex *can be and only be locked by once*, it proves the exclusive ownership of the operations within the lock scope.

To use mutex in C++, it's needed to `#include <mutex>`, and mutex is in `std::` namespace.

```c++
#include <mutex>

std::mutex mu1; // declaration of a mutex object
std::mutex mu2;
std::lock_guard<std::mutex> lock(mu1);
// a helper object that automatically manage the life span of a lock.(RAII)
// c11
std::scope_lock guard(mu1, mu2);
// similar to std::lock_guard. locking multiple mutexes at once is permitted.(RAII)
// with class template argument deduction, the type list can be omitted
// c17
```

> Don’t pass pointers and references to protected data outside the scope of the lock, whether by returning them from a function, storing them in externally visible memory, or passing them as arguments to user-supplied functions.

## Data Race Inherent in Interface

Different type of stack interface and the related data race.

```c++

stack s;

// Approach 1 for general interface
if(!s.empty())
{
    auto ele = s.top();
    s.pop();
}

// Approach 2 for capsuled interface
ele_type ele;
if(!s.pop(ele)) // construction of ele may failed and the top element could lose in the meantime.
{
    std::cout << "Failed to get element.\n";
}

// Approach 3 pointer return
auto* ptr = s.pop();

```

In approach 1, `s.empty()` cannot ensure the stack is not empty when `s.top()` is called, because stack may be modified between two function call if multiple threads are accessing the same stack at a time.
Meanwhile, the use of `s.top()` and `s.pop()` can also leads to data race while the 'top' element is not guaranteed to be the 'pop' element.

In approach 2, `top()` and `pop()` is capsuled into one function. Hence, one crucial data race is deducted. However, this approach requires `ele_type` can be *"constructed afterwards"* since the variable passed into `pop()` has to create before function call. As an alternative, if possible, an "default" variable can be a solution, but copying data can be a heavy operation especially when move-constructor is not available.

In approach 3, those two actions are capsuled into one as approach 2, but comparing to a reference, this time a pointer is return and `nullptr` can be used to detect exception and there is no excessive constructor require for `ele_type`. The drawback of this solution is accessing data through pointer can add unnecessary overhead especially for small data like built-in `int`.

## Deadlock

Deadlock can happen whenever several mutexes needed to be locked.

### Avoiding Deadlock

1. Avoid nest lock
2. Avoid calling user-supplied code with holding a lock
3. Acquire locks in a fix order
4. use a lock hierarchy

#### Hierarchy Lock

### std::unique_lock

## Alternative solutions

### Protecting shared data during initialization

Not all shared data should be protected by mutex. For example, in a network connection a socket will not be modified after it's initialized until the connection is closed. In this case, using mutex to protect a read-only data leads to unnecessary overhead.

```c++
std::shared_ptr<T> read_only_data;
std::mutex mu;
void mutex_lock()
{
    std::unique_lock lk(mu);
    if(!read_only_data)
    {
        read_only_data.reset(new T);
    }
    lk.unlock();

    read_only_data->do_something();
}
void undefined_behaviour_with_double_checked_locking()
{
    if(!read_only_data)
    {
        std::unique_lock lk(mu);
        if(!read_only_data)
        {
            read_only_data.reset(new T);
        }
    }

    read_only_data->do_something();
}
```

Advance approach with C++ standard library. `std::call_once` and `std::once_flag` can ensure a function or any callable object will be called only once.

```c++
std::share_data<T> read_only_data;
std::once_flag flag;
void initialize(std::shared_data<T> data)
{
    data.reset(new T);
}
void func()
{
    std::call_once(flag, initialize, read_only_data);
    read_only_data->do_something();
}
```

> Keep in mind that both `std::mutex` and `std::once_flag` can not be copied or moved.

After c11, it is ensured by compiler that the initialization of static object is thread-safe. Using this feature, we can write elegant code to create single global instance. The most famous practice of this hint is probably that thread-safe singleton approach.

```c++
class Singleton
{
private:
    Singleton() = default;
public:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static Singleton& GetInstance() noexcept
    {
        static Singleton instance;
        return instance;
    }
};
```

### Protecting rarely updated data structures

*reader-writer* mutex: allows two access mode: exclusive and shared.

name                    |lowest support version
:-----------------------|:--------------------:
std::mutex              |c++11
std::shared_timed_mutex |c++14
std::shared_mutex       |c++17

```c++
std::share_mutex mu;

// exclusive access
{ std::unique_lock lk(mu); }
{ std::lock_guard lk(mu); }

// shared access
{ std::shared_lock lk(mu); } // since c++14

```

### Recursive locking

`std::recursive_mutex` allows a mutex locking itself multiple times.

> Not recommand.
