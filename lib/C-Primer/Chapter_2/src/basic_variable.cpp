#include "basic_variable.h"
#include <iostream>

void show_size()
{
    using std::cout;
}

void test_of_convert()
{
    bool b = 42;
    int i = b;
    i = 3.14;
    double pi = i;
    float p = 3.14;
    p = 3.14;
    p = 3.14f;
    pi = 3.14f;
    pi = 3.14;
    unsigned char uc = -256;
    signed char sc = -256;
    unsigned int un = 256;
    signed int sn = -256;
    uc = un;
    sc = sn;
}

void test_of_variables()
{
    test_of_convert();
}