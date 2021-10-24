#pragma once
#include <iostream>

namespace chain
{
    template <typename T>
    struct Node_single
    {
        T _element;
        Node_single* NEXT;
    };

    template <typename T>
    class Chain_single
    {
    public:
        Chain_single()
        {
            Head = new Node_single<T>;
            Head->NEXT = nullptr;
        }
        ~Chain_single()
        {
            Node_single<T>* p = Head, *j;
            do
            {
                j = p->NEXT;
                delete p;
                p = j;
            }while (p);
        }
    protected:
        inline Node_single<T>* FindKthNode(unsigned index)
        {
            if(index > _size)
            {
            std::cerr << "Out of size!";
            return;
            }
            Node_single<T>* ptr = Head;
            while(index)
            {
                ptr = ptr->NEXT;
                --index;
            }
            return ptr;
        }

    public:
        void PrintList()
        {
            Node_single<T>* ptr = Head->NEXT;
            while(ptr)
            {
                std::cout << ptr->_element << std::endl;
                ptr = ptr->NEXT;
            }
            std::cout << "The size is " << _size << ".\n";
        }

        bool Find(const T &element);

        
        T FindKth(unsigned index) const
        {
            return FindKthNode(index)->_element;
        }
        T operator[](unsigned index) const
        {
            return FindKthNode(index)->_element;
        }

        void Add(const T &element)
        {
            Node_single<T>* ptr = Head;
            while (ptr->NEXT)
            {
                ptr = ptr->NEXT;
            }
            Node_single<T>* n = new Node_single<T>;
            ptr->NEXT = n;
            n->_element = element;
            n->NEXT = nullptr;
            ++_size;
        }

        void Insert(const T &element, unsigned index)
        {
            Node_single<T>* p = FindKthNode(index);
            Node_single<T>* j = new Node_single<T>;
            j->_element = element;
            j->NEXT = p->NEXT;
            p->NEXT = j;
        }
        void Delete(unsigned index)
        {
            Node_single<T>* p = FindKthNode(index - 1), j;
            j = p->NEXT;
            p->NEXT = j->NEXT;
            delete j;
        }

        unsigned Size()
        {
            return _size;
        }
    protected:
        Node_single<T>* Head;

        unsigned _size = 0;
    };
}

void testChain(int);