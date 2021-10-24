#include "sequential_container.h"
#include <vector>
#include <random>
#include <list>
#include <deque>
#include <string>
#include <stdio.h>

void PrintVec(std::vector<int> &v)
{
    for(auto a : v)
        printf("%d ", a);
    printf("From: %0x", v.data());
    puts("");
}

// Answer for P297-Practice9.4
bool find(std::vector<int>::const_iterator head, std::vector<int>::const_iterator end, int key)
{
    while (head != end)
    {
        if (*head == key) return true;
        head++;
    }
    return false;
}

// Answer for P297-Practice9.5
std::vector<int>::const_iterator find_it_bak(std::vector<int>::const_iterator head, std::vector<int>::const_iterator end, int key)
{
    while (head != end)
    {
        if (*head == key) return head;
        head++;
    }
    perror("the element not find!\nReturn end as default.\n");
    return end;
}

// Answer for P309-Practice9.18
std::deque<std::string> FromStringToDeque(const std::vector<std::string> &vecStr)
{
    std::deque<std::string> dq;
    for(auto vs : vecStr)
        dq.emplace_back(vs);
    for(auto d : dq)
        printf("%s",d.data());
    return dq;
}

void test_of_container()
{
    using namespace std;
    const unsigned size = 10;
    vector<int> v;
    for(int i = 0; i < size; i++)
    {
        v.push_back(rand());
    }
    v.pop_back();
    v.push_back(5);
    int b = static_cast<int>(find(v.cbegin(),v.cend(),5));
    printf("The \"5\" is find? %d \n", b);
    vector<int> vint;
    for(int i = 0; i < size; i++)
    {
        vint.push_back(rand()%100);
    }
    PrintVec(vint);
    vector<string> vStr {"Hello ", "World", "!"};
    for(auto vs : vStr)
        printf("%s", vs.data());
    puts("");
    FromStringToDeque(vStr);
}