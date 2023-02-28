# Alignments

[Source](https://www.youtube.com/watch?v=uSZFrmhayIM)

## Definition

***Alignment*** means to prevent "*cross-word*" data. To better understand this, let's introduce the concept of ***word***.

---
The basic unit of memory is called ***word***. However, *word* is not necessary to be the smallest size of variable. For example, on 32bits machine, one word equals to 32bits but one char always equals 16bits.
With the analyse above, it's clear that how variables are stored in memory matters the performace, then for different hardware, the impact of *word* varies.

1. Early CPUs: Only support reading memories per *word*.
2. Modern X86 CPUs: Support arbitrary reading memories. However, reading memory cross *word*s has a cost on performance.
3. X86-64 CPUs: Support arbitrary reading memories and it will not influence the performance.

---
Let's back to *alignment*. We can draw the conclusion that ultimate target of *alignment* is to ensure every data can be directly addressed. The solution to the problem is ***padding***. In another word, is to leave the unused memory of a partly used memory globally unused by filling it with blank data.

## Internal functions & macro

These are rooted in the standard.

### `alignof`

### `alignas`

### `new`

## Library functions

These are part of the implements in the c plus plus standard library.

### `std::alignment_of`

```c++
    std::alignment_of<T>::value == alignof(T);
```

Provides the member constant value equal to the alignment requirement of the type T, as if obtained by an `alignof` expression. If T is an array type, returns the alignment requirements of the element type. If T is a reference type, returns the alignment requirements of the type referred to.

Helper variable template

```c++
template <class T>
inline constexpr std::size_t alignment_of_v = alignment_of<T>::value;
```

### `std::align`

```c++
void* std::align(std::size_t alignment,
                 std::size_t size,
                 void *&ptr,
                 std::size_t &space) noexcept;
```

### `std::aligned_storage`

```c++
template <std::size_t Len,
          std::size_t Alignment>
struct aligned_storage {
    typedef struct {
        alignas(Alignment) unsigned char __data[Len];
    } type;
}
```

## Example usage

### Allocator

## Proposed extension

Dynamic memory allocation for over-aligned data.

Adding alignment to the type system.
alignof
type_align
aligned_ptr
