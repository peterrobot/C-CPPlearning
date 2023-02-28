#pragma once
#include <iostream>

template <class T>
class MyStack
{
public:
    MyStack(size_t s):kSize(s),m_head_(0),m_base_(new T[kSize]){}
    void Push(T& in)
    {
        if(m_head_==kSize-1)
        {
            std::cerr << "The stack is full already\n";
            return;
        }
        m_base_[++m_head_] = in;
    }
    T& Front()
    {
        if(isEmpty()) std::cerr << "Try to front an empty stack\n";
        return m_base_[m_head_];
    }
    void Pop()
    {
        if(isEmpty()) std::cerr << "Try to pop an empty stack\n";
        --m_head_;
    }
    bool isEmpty(){ return m_head_; }
    ~MyStack()
    {
        delete[] m_base_;
    }
private:
    const size_t kSize;
    size_t m_head_;
    T* m_base_;
};