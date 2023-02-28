# Generic Algorithm

[TOC]

## Brief Introduction

Generic algorithms only operate the **iterator** instead of operating the **data structure** itself.
In order to understand the usage of a specific algorithm, the aspect given below may be of benefit --- whether the algorithm **read**, **change** or **reallocate** the *elements*.

## Some kinds of algorithm

### Read-only algorithm

Some examples

```c++
#include <algorithm>
container::iterator find(iterator begin, iterator end, val key);
// Find the target value in the given range.
ptrdiff_t count(iterator begin, iterator end, val key);
// Count how many times dose the target value appear in the given range.

#include <numeric>
val accumulate(iterator begin, iterator end, val initial_value);
// Sum up the value in the given range, the third value decide the start-up value, 
// which in turn indicates "origin variable" and "val" is "addable". (operator+ is defined)

#include <algorithm>
bool equal(iterator begin1, iterator end1, iterator begin2);
/*
    Check whether the values in "1" are identically equal to the values in "2".
    By the way, when using this function, we implicitly assume the range of "1" and "2" is the same.
    As accumulate(), this function requires an operator, or to be more specific, operator==, must be defined.
*/
```

### Write algorithm

Some examples

```c++
#include <algorithm>
container::iterator fill(iterator begin, iterator end, val key);
// Fill the range with the given key value.
container::iterator fill_n(iterator begin, unsigned step, val key);
/*  
    Be careful, "write" is completely different from "insert".
    That's to say, "write" does not allocate new memory but only changes the value.
    As a sault, writing with a "STEP" can easily go out of range, causing a disaster.
*/
```

Commonly, generic algorithm **DO NOT** change the container itself(size), so it is commonplace to see *"out-of-range"* problem.
In order to deal with the "out-of-range" problem, the insert iterator is defined.

```c++
#include <iterator>
std::back_insert_iterator<container> back_inserter(&container ref);
// Return the "back inserter" of the given container.
container::iterator fill_n(back_inserter(contain), unsigned step, val key);
// Completely safe.
```

#### Copy algorithm

Some examples

```c++
#include <algorithm>
container::iterator copy(iterator begin1, iterator end1, iterator begin2);
// Copy the value in val1(in specific range) to val2. (The later one's size needs to be larger)
// The return value is the "end iterator" of copy range.
void replace(iterator begin, iterator end, val key, val replace);
// Replace the val "key" with val "replace" the result is in the input container.
void replace_copy(iterator begin1, iterator end1, iterator target, val key, val replace);
// The same as above, but place the result in the second given container.
```

### Reallocate algorithm

Some examples

```c++
#include <algorithm>
void sort(iterator begin, iterator end);
// Sort the elements with "operator <".
iterator unique(iterator begin, iterator end);
/*
    Reallocate the element, putting the nearby repeated element to the end of the container.
    Return the iterator "pointing to" the first repeated element.
    That"s to say, as we mentioned above, this function, as a genetic algorithm, DO NOT delete the repeated element.
    To accomplish our goal, the "erase()" is needed.
*/
iterator erase(iterator begin, iterator end);
// Delete the element in the given range.
// Return the iterator pointing to next to the last deleted element.
```

## Custom operation

Sometimes, we can pass a function to generic algorithm to make it more "specific". For example:

```c++
#include <algorithm>
#include <vector>
std::vector<int> vectorInt;
bool func(val a, val b) { return a > b; } // Personal comparison function
std::sort(std::begin(vectorInt), std::end(vectorInt)); //Sort with default "operator <".
std::sort(std::begin(vectorInt), std::end(vectorInt), func); //Sort with personal function "func", in this case, "operator >" specifically.

void std::stable_sort(iterator begin, iterator end);
// Function like "void std::sort()", but this function will keep the origin order in each group.
// Stable hum...?
```

Here we see the function "func()", it has two arguments and its return value is bool. It really makes sense for sort function. By the way, most of the functions we are proposed to pass to the generic algorithms are like this guy.
To make our statement more "pro", let's introduce a fancy new word.

### Predicate

> predicate: Function that returns a type that can be converted to bool. Often used by the generic algorithms to test elements. Predicates used by the library are either unary (taking one argument) or binary (taking two).

### Lambda expressions

As we see, the **type** of a function is made up of two parts --- *return type* and *arguments list* --- and in this case, the **type** of the function we pass to the generic algorithm is fixed. It sounds like it doesn't matter at all, but the problem is that sometimes the function we want to pass has some **extra argument**, making the type does not match.
To deal with this question, we simply have two answers. Let's focus on the **Lambda Expressions** which deal with this problem with the capture list.
Before we moving on, it's a good idea to jump out of our original problem and have a quick glance at **Lambda Expressions** itself first.

#### Brief Introduction To Lambda

This concept, like most of the concept in CS, it originates in math. The following information comes mainly from Wiki page. [See More](./Lambda%20calculus%20-%20Wikipedia.html)
> Lambda calculus: is a formal system in mathematical logic for expressing computation based on function abstraction and application using variable binding and substitution. It is a universal model of computation that can be used to simulate any Turing machine. It was introduced by the mathematician Alonzo Church in the 1930s as part of his research into the foundations of mathematics.

In general **Lambda Expression** has a form like this:
> [*capture list*] (*parameter list*) -> *return type* { *function body* }
In Lambda, *parameter list* and *return type* is **omittable**, so the simplest form may like this:
> [*capture list*] { *function body* }

Next, let's take a closer look at Lambda part by part.

#### Parameter List

#### Capture List

#### Return Type

### Parameter Bind

## More about iterator

## Structure of Generic Algorithms

## Container-specific Algorithms
