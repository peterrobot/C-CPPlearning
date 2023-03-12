#include <thread>
#include <iostream>

void hello(int i)
{
    std::cout << '[' << i << "] Hello concurrency!\n";
}

void helloConcurrency()
{
    std::thread t1(hello, 1);
    std::thread t2(hello, 2);
    std::thread t3(hello, 3);

    t1.join();
    t2.join();
    t3.join();
}