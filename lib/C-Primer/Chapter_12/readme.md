# Dynamic Memory

Parts of memory

1. Static (static variables, strings)
2. Stack (local variables)
3. Heap (dynamically allocate)

## Dynamic memory & Smart pointer

In general, dynamic memory is used with a pair of key words: `new` & `delete`.
Dynamic memory is useful in deed. However, a large amount of problems are caused by it. So, in new standard of c++, some more advance tools are developed to deal with the *annoying* problem.

```c++
#include <memory>
std::shared_ptr<int> pint;
std::unique_ptr<char> pchar;
std::weak_ptr<int> pint_r;
```

## Class share_ptr

## Class unique_ptr
