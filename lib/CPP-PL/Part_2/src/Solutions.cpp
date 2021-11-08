#include "Solutions.h"
#include "My_Stack.h"
#include <iostream>

#define FOREVER for(;;)

using namespace practice;


// Practice 7.7
void practice::TnodeInsert(TnodeTree head, std::string name)
{
    TnodeTree fore;
    do{
        fore = head;
    } while (head = name < head->name ? head->left : head->right);
    if(fore->name == head->name)
    {
        fore->count++;
        return;
    }
    head = new Tnode(name);
    name < fore->name ? fore->left = head : fore->right = head;
    return;
}
void practice::PrintTnode(const Tnode& node)
{
    std::cout << "The " << node.name << " appears " << node.count << (node.count < 2)? " time.\n" : " times.\n";
}
void practice::PrintTnodeTree(TnodeTree head)
{
    if(head == nullptr) return;
    PrintTnodeTree(head->right);
    PrintTnode(*head);
    PrintTnodeTree(head->left);
}
void practice::PrintTnodeTreeStack(TnodeTree head)
{
    MyStack<TnodeTree> ms(30);
    TnodeTree t = head;
    FOREVER
    {
        if(t==nullptr)
        {
            if(ms.isEmpty()) return;
            t = ms.Front()->right;
            ms.Pop();
        }
        if(t->left)
        {
            ms.Push(t);
            t = t->left;
            continue;
        }
        PrintTnode(*t);
        t = t->right;
    }
}