#pragma once

namespace stack
{
    template <typename T>
    struct Node
    {
        T _element;
        Node* NEXT;
    };
    
    template <typename T>
    class StackWithChain
    {
    public:
        StackWithChain()
        {
            Head = new Node<T>;
            _poped = new Node<T>;
            Head->NEXT = nullptr;
            _poped->NEXT = nullptr;
        }
        ~StackWithChain()
        {
            Node<T>* p = Head, j;
            while (p)
            {
                j = p->NEXT;
                delete p;
                p = j;
            }
        }

        void Push(T &element)
        {
            Node<T>* p;
            if(_poped->NEXT)
            {
                p = new Node<T>;
            }
            else
            {
                p = _poped->NEXT;
                _poped->NEXT = p->NEXT;
            }
            p->_element = element;
            p->NEXT = Head->NEXT;
            Head->NEXT = p;
        }
        T Pop()
        {
            if (Head->NEXT)
            {
                std::cerr << "Error: The Stack is Empty when pop!";
                return;
            }
            Node<T>* p = Head->NEXT;
            Head->NEXT = p->NEXT;
            p->NEXT = _poped->NEXT;
            _poped->NEXT = p;
            return p->_element;
        }
        void ClearEmpty()
        {
            Node<T>* p = _poped->NEXT, j;
            while (p)
            {
                j = p->NEXT;
                delete p;
                p = j;
            }
        }

    private:
        Node<T>* Head;
        Node<T>* _poped;
    };

    template <typename T>
    class StackWithArray
    {
    public:
        StackWithArray(unsigned size) : _size(size), is_empty(true) { _content = new T[size]; }
        ~StackWithArray() { delete[_size] _content}

        void Push(T&);
        T Pop();

        bool IsEmpty() { return is_empty; }

    private:
        const unsigned _size;
        unsigned _top_of_stack;
        bool is_empty;
        T* _content;
    };
}

void testStack();