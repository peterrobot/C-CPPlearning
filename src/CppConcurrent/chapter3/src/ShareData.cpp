#include "ShareData.h"
#include <thread>
#include <vector>
#include <iostream>

const char *empty_stack::what() const throw()
{
    return "empty stack";
}

const char *full_stack::what() const throw()
{
    return "full stack";
}

template <typename T>
void testStack(ThreadSafetyStack<T>& stack, const T* src_data, const uint32_t size)
{
    for(uint32_t i  = 0; i < size; i++)
    {
        stack.Push(src_data[i]);
    }
}

template <typename T>
void showStack(ThreadSafetyStack<T>& stack)
{
    while (!stack.Empty())
    {
        std::cout << stack.Pop() << std::endl;
    }
}

void testShareData()
{
    ThreadSafetyStack<int> stack(100);

    int data1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int data2[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int data3[10] = { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

    std::vector<std::thread> thread_list;
    thread_list.emplace_back(testStack<int>, std::ref(stack), data1, 5);
    thread_list.emplace_back(testStack<int>, std::ref(stack), data1 + 5, 5);
    thread_list.emplace_back(testStack<int>, std::ref(stack), data2, 5);
    thread_list.emplace_back(testStack<int>, std::ref(stack), data2 + 5, 5);
    thread_list.emplace_back(testStack<int>, std::ref(stack), data3, 10);
    thread_list.emplace_back(testStack<int>, std::ref(stack), data3 + 5, 5);

    for(auto& thread : thread_list)
    {
        if(thread.joinable())
            thread.join();
    }

    showStack(stack);
}
