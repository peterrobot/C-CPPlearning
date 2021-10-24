# Associative Container

[TOC]

Associative containers support high efficient key-words search and access. There are eight kinds of associative containers in the std-lib, among which the **map** and **set** are most fundamental. That's to say, all of the other classes are inherited from one of them. To briefly conclude, there are three dimensions to differ the Associative-containers.

1. *set* or *map*
2. *repeatable* or not - prefix **multi-**
3. *ordered* or not - prefix **unordered_-**

|    \     |    base     | multi
| :------- |    :--:     | :--:
|ordered   |     set     |multiset
|          |     map     |multimap
|unordered |unordered_set|unordered_multiset
|          |unordered_map|unordered_multimap

## Basic usage

Sometimes, container *map* is called the **associative array**, which means the container has two connected elements. To be more specific, it is possible to use one of the elements to access another one. On the contrary, container *set* is simply a set of elements that is somehow like a "*flexible enum*" with a built-in ability to search.
When using *map*, to get that certain ***value*** connected with the ***key***, we can simply use the overridden **subscript operator** like `map_variable[key]`. It may be confusing that there is no need to initialize the ***key*** while the function will automatically complete this task. So, use `map_variable[key_first_added]` is fine. When ergodic the map-container, we got a special data structure containing the two values, call the member element **first** as ***key*** and **second** as ***value***.

To check whether certain value exist in the *set*, we can just use member function *find()*, the detail usage see below:

```c++
#include <set>
std::set<type>::iterator find(type key);
// Return the iterator of element equal to "key", return end-iterator if have not find the "key".
```

## Brief introduction

Associate containers support all basic operations of the other containers, except what is related to sequence and what has just one argument about value. By the way, associate containers support more operations. They have the reverse iterator, too.

To initialize a *map*, two types --- ***key*** and ***value*** --- are needed while only one type --- ***key*** --- is needed for *set*.

### Initialize

```c++
std::map<std::string, size_t> map1; // Create empty as default
std::map<int, float> map2 = {{1, 1f},{2,2f},{3,3f}}; // Initialize with initialize list, two values needed for std::map
```

As its name, "***multi families***" can have several elements which has the same value whether at initialize moment or by use time.

### Key type requirements

Ordered containers as they are, the ***key type*** must be able to ordered. In default, `operator<` is used. So, usually, we can just use a data structure that defines this function. However, as other generic template, it is acceptable to pass a personal function which define a **strict weak ordering** at the ***key type***.

>Strict weak ordering
>
>1. k1 < k2 --> k2 !<= k1 (no mutual smaller)
>2. k1 < k2, k2 < k3 --> k1 < k3 (order can be passed)
>3. k1 !< k2 & k2 !< k2 <--> k1 == k2 (mutual not smaller is equal), k1 == k2, k2 == k3 --> k1 == k3 (equality can be passed)

When using personal compare function, the initialize step is a bit different. As you may see below, that type of function needs to ba a part of the template, and the pointer of function needs to be passed to the construct function.

```c++
bool compare(const type&, const type&)
std::set<type, decltype(compare) *> newElement(compare);
// The decltype() is used here to simplify the code. But don't forget that "*" which indicates the type is pointer.
```

### Type pair

```c++
#include <utility>
std::pair<type1, type2> _pair;
std::pair<int, float> i_f_pair = {1, 1f};
// std::pair use value-initialized by default. That's to say, pass the value to each of the construct function. Of cause, zero for default value.
make_pair(1, 1f);
// A swift way to initialize an anonymous pair variable.
```

We can initialize a anonymous "pair" with initialize field when the type has been decided by the context. For example `return {1, 1f} //Return type is std::pair<int, float>`.

## Associative Container operation

1. key_type
2. mapped_type
3. value_type

The types above can be used directly to initialize a variable like: `std::Set<int>::key_type t;`. Be cautious, this "type name" is not stored as a class member.

### Iterator

When dereference a iterator of **std::map**, we get a *pair* variable whose first element is the **key value** and the second element is the **mapped value**. In general, the **key value** is const and the **map value** can be changed.
By the way, as **std::set** is a list of *key words*, so the elements are read-only with iterator.

### Add elements

### Delete elements

### Subscript operation

### Access elements

## Unordered container
