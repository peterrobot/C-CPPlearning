# Synchronizing Concurrent Operations

## Waiting for other thread

1. shared flag with mutex
2. shared flag with interval check
3. condition variables

```c++
bool flag;
std::mutex mu;
// shared flag with mutex - possible implementation
void wait_mutex()
{
    while(!flag)
    {
        std::lock_guard lk(mu);
    }
}
// shared flag with interval check - possible implementation
void wait_for_flag()
{
    std::lock_guard lk(mu);
    while(!flag)
    {
        lk.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        lk.lock();
    }
}
```

### Condition Variable

There are two implementations of condition variable in C++ Standard Library, `std::condition_variable` and `std::condition_variable_any`, both of which is declared in `<condition_variable>`. Both of these condition variables should be used cooperating with `mutex`. While `std::condition_variable` can only work with `std::mutex`, `std::condition_variable_any`, as its suffix *_any* suggests, can work with all *mutex-like* object.
