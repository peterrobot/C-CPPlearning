#include "dynamic_memory.h"
#include <stdexcept>
#include <iostream>
#include <stdlib.h>

// Definations of StrBlob's member functions

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)){}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if(i >= data->size())
        throw std::out_of_range(msg);
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}
std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
const ConstStrBlobPtr StrBlob::cbegin() const
{
    return ConstStrBlobPtr(*this, (std::size_t)0);
}
const ConstStrBlobPtr StrBlob::cend() const
{
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

// Definations of StrBlobPtr's member functions

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw std::out_of_range("msg");
    return ret;
}
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// Definations of ConstStrBlobPtr's member functions

const std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw std::out_of_range("msg");
    return ret;
}
const std::string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
bool ConstStrBlobPtr::operator!=(ConstStrBlobPtr& comp) const
{
    if(this->wptr.lock() != comp.wptr.lock()) std::runtime_error("compare iterator from two StrBlob with Ptr");
    return this->curr != comp.curr;
}
const std::string& ConstStrBlobPtr::operator*() const
{
    return deref();
}
ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
    return incr();
}

// Answer for P411-Practice12.6
std::vector<int>* dynamicAllocateVector() { return new std::vector<int>; }
std::vector<int>* assignVector(std::vector<int>* pveci)
{
    int temp;
    while(std::cin >> temp) pveci->push_back(temp);
    return pveci;
}
void printVector(std::vector<int>* pveci)
{
    for(auto i : *pveci) std::cout << i << std::endl;
    delete pveci;
}

// Answer for P411-Practice12.7
std::shared_ptr<std::vector<int>>
smartDynamicAllocateVector() { return std::make_shared<std::vector<int>>(); }
std::shared_ptr<std::vector<int>>
smartAssignVector(std::shared_ptr<std::vector<int>> pveci)
{
    int temp;
    while(std::cin >> temp) pveci->push_back(temp);
    return pveci;
}
void smartPrintVector(std::shared_ptr<std::vector<int>> pveci)
{
    for(auto i : *pveci) std::cout << i << std::endl;
}

// Answer for P422-Practice12.20
void storeStrBlob(StrBlob& ref, std::istream is)
{
    std::string temp;
    while(is >> temp) ref.push_back(temp);
    auto b = ref.cbegin();
    auto e = ref.cend();
    while(b != e)
    {
        std::cout << *b << std::endl;
        ++b;
    }
}

// Answer for P426-Practice12.23
char* linkCstrings(const char* a1, const char* a2, const size_t s1, const size_t s2)
{
    char* str = new char[s1+s2-1];
    str = str + s1 - 1;
    memcpy(str,a2,s2);
    str = str - s1 + 1;
    memcpy(str,a1,s1);
    return str;
}
std::string linkCPPstrings(const std::string& s1, const std::string& s2)
{
    return s1+s2;
}

//

void dynamic_memory_test()
{
    int *const p1 = new int[10];
    int * p2 = p1;
    ++(*p2);
}