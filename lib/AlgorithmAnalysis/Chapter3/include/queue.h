#pragma once

namespace queue
{
    template <typename T>
    struct Node
    {
        T _element;
        Node* NEXT;
    };

    template <typename T>
    class Queue
    {
    public:
        Queue()
        {
            Head = new Node<T>;
            Back = new Node<T>;
            Head->NEXT = Back;
            Back->NEXT = nullptr;
        }
        ~Queue()
        {
            Node<T>* p = Head, *j;
            while (p)
            {
                j = p->NEXT;
                delete p;
                p = j;
            }
        }

        void Enqueue(T &element)
        {
            Node<T>* p;
            if(Back->NEXT)
            {
                p = Back->NEXT;
            }
            else
            {
                p = new Node<T>;
                Back->NEXT = p;
            }
            p->_element = element;
            Back = p;
        }
        
        T Dequeue()
        {
            if (Head->NEXT == Back)
            {
                std::cerr << "Error: The Stack is empty";
                return;
            }
            Node<T>* p = Head->NEXT;
            Head->NEXT = p->NEXT;
            Back->NEXT = p;
            return p->_element;
        }
        void ClearEmpty()
        {
            Node<T>* p = Back->NEXT, *j;
            while (p)
            {
                j = p->NEXT;
                delete p;
                p = j;
            }
        }
        
    private:
        Node<T>* Head;
        Node<T>* Back;
    };
}

void testQueue();