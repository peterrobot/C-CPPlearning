# C++11 Library Design

[Source](https://www.youtube.com/watch?v=zgOF4NrQllo)
***Lessons from Boost and the Standard Library***

Goals of the talk: Interface Design Best Practices.

## Function Interface Design

The best way of getting data into and out of function.

---

First, back to C++98

Category|C++98 Recommendation
:--|:--
Input|
small|Pass by value
large|Pass by const ref
Output|
small|Return by value
large|Pass by (non-const) ref
Input/Output|Pass by non-const ref

---

Then, C++11 has changed our strategy and the main reason why we has changed is the move semantics.

Two types of argument passed to a function.

1. *Read-only*
2. *Sink*

Guideline 1: Continue taking *read-only* value by *const ref*(except small ones)
Guideline 2: Take sink arguments *by value*
Guideline 3: Encapsulate an algorithm's state in an object that implements the algorithm.

Category|C++11 Recommendation
:-------|-------
Input|
small & "sink"|Pass by value
all others|Pass by const ref
Output|Return by value
Input/Output|Use a stateful algorithm object(*)
> (*) Initial state is a **sink** argument to the constructor

Perfect Forwarding Pattern

## Class Design

1. Language Features
    i. Copy, assign, move, range-base for, etc.
    ii. Composes with other types
    iii. Can be use anywhere(heap, stack, static storage, inconstant expression, etc.)
2. Library Features
    i. Well-behaved in generic algorithm
    ii. Well-behaved in containers

### Regular Type

Guideline 4: Make you class regular (if possible)
Guideline 5: Make your types' move operation `noexcept` (if possible)

Guideline 6: The moved-from state must be part of a class's invariant
Guideline 7: If Guideline 6 doesn't make sense, the type isn't movable
Corollary: Every movable type must have a cheap(er)-to-construct, *valid* default state

## "Module" Design

### Evolving A Library

New library version with interface-breaking changing.

Target:

1. New class layout
2. New argument/return
3. New overload

Tools:

`inline namespace`

Guideline 8: Put all interface elements in a versioning namespace ***from day one***.
Guideline 9: Make the current version namespace `inline`

### Preventing Name Hijacking

Name Hijacking: Unintentional ADL finds the wrong overload.

Solutions

1. Use a non-inline ADL-blocking namespace
2. Use global function objects instead of free functions
3. Variable template (c++14 only)

```c++
// An example of function object
template <typename _Arg, typename _Ret = _Arg>
struct funcObj{
    _Ret operator()(_Arg arg1, _Arg arg2){
        return arg1+arg2;
    }
}func;

// New feature in c++14, variable templates
template <typename O>
struct personal_cast_fn{
    template <typename T>
    O operator()(T const &t) const { ... }
};

template <typename T>
constexpr personal_case_fn<T> personal_cast{};
```

**Ode to** *object variables*:

1. They are never found by ADL
2. If phrase 1 lookup funds an object instead of a function, ADL is disabled
3. They are first class objects
    i. easy to bind
    ii. easy to pass to higher-order functions like `std::accumulate`

> **First-class-object**: In general, it refers to a kind of object that grants all the privilege, in another word, there are no restrictions when using them.

Guideline 10: Put type definition in ADL_blocking(non-inline!) namespaces and export then with a using declaration
Guideline 11: Prefer global `constexpr` function objects over named free functions(except for documented customization points)
