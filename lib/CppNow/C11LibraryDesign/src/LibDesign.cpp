#include "LibDesign.h"
#include <iostream>
#include <string>
#include <cassert>
#include <ranges>

/*
    Library stuff
*/
namespace lib
{
    /*
    template <typename _Ty>
    void print(_Ty _Arg)
    {
        std::cout << _Arg << std::endl;
    }
    */
    inline namespace V1
    {
        template <typename _Ty>
        void print(_Ty _Arg)
        {
            std::cout << _Arg << std::endl;
        }
    }
    namespace V2
    {
        template <typename _Ty>
        void print(_Ty _Arg)
        {
            std::endl << _Arg << std::endl;
        }
    }
    template <>
    void print<int>(int i)
    {
        std::cout << "Int is: " << i << std::endl;
    }

    template <>
    void V2::print<int>(int i)
    {
        std::cout << "V2: Int is: " << i << std::endl;
    }
}

/*
    Name Hijacking Problem
*/

namespace tasks
{
    // An example of function objectc
    constexpr struct funcObj{
        template <typename _Arg,typename _Ret = _Arg >
        _Ret operator()(_Arg &arg1, _Arg &arg2) const {
            return arg1+arg2;
        }
    }funcAdd{};
    
    // Origin function with template
    template <class Tasklike>
    void begin( Tasklike &&t)
    {
        t.Begin();
    }

    // Origin function written by function object
    constexpr struct Task
    {
        template <typename Tasklike>
        void begin_temp_fn(Tasklike &&t) const
        {
            t.Begin();
        }
    }begin_temp{};

    template <typename T>
    struct lexical_cast_fn
    {
        template <typename U>
        T operator()(U const u) const{}
    };
}

template <typename T>
constexpr tasks::lexical_cast_fn<T> lexical_cast{};

/*
    Problems about moveconstructor
*/
template <typename T>
class not_null_unique_ptr
{
private:
    T * ptr_;
    std::string str_;
public:
    not_null_unique_ptr() : ptr_(new T{}) {}
    not_null_unique_ptr(T *p) : ptr_(p) {assert(p);}
    T* Get() { return ptr_; }
    not_null_unique_ptr(T &&p) noexcept
        : ptr_(p.ptr_)
    {
        std::cout << "Move constructor called\n";
        p.ptr_ = nullptr;
    }
};

void test_of_move()
{
    not_null_unique_ptr<int> pint1(new int(10));
    not_null_unique_ptr<int> pint2(std::move(pint1));
    std::cout << pint1.Get() << std::endl << pint2.Get() << std::endl;
}