#include "STL_learn.h"

void STL_learn_test()
{
    std::ostream_iterator<std::string> oo(std::cout);
    std::istream_iterator<std::string> eos;
    *oo = "Hello World!\n";
    int i = 0;
    std::cout << ++i << " " << i++ << std::endl;
}