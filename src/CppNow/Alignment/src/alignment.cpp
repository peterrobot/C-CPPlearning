#include "alignment.h"
#include <iostream>

struct ManuallStruct
{
    int i;
    bool b;
    char c;
};
class ManualClass
{
private:
    int i;
    bool b;
    char c;
public:
    static int si;
};

void test_of_alignment()
{
    enum expEnum {a,b,c,d,e,f};
    constexpr auto int_size = alignof(int);
    constexpr auto longlong_size = alignof(long long);
    constexpr auto ms_size = alignof(ManuallStruct);
    constexpr auto mc_size = alignof(ManualClass);
    constexpr auto enum_size = alignof(expEnum);
    std::cout << "int_size: " << int_size << "\nlonglong_size: " << longlong_size << "\nms_size: " << ms_size
    << "\nmc_size: " << mc_size << "\nenum_size: " << enum_size << "\n";
    std::cout << "size_of int: " << sizeof(int)
    << "\nsize_of longlong: " << sizeof(long long)
    << "\nsize_of ManualStruct: " << sizeof(ManuallStruct)
    << "\nsize_of ManualClass: " << sizeof(ManualClass)
    << "\nsize_of expEnum: " << sizeof(expEnum) << "\n";
}

struct data
{
    std::atomic<uint32_t> count;
    uint32_t max;
};
