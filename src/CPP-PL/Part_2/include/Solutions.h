#pragma once
#include <string>

namespace practice
{

/*
Practice in Chapter 7
*/

// Practice 7
struct Tnode
{
    std::string name;
    int count;
    Tnode *left;
    Tnode *right;
    Tnode(std::string n, int i = 1) : name(n),count(i),left(nullptr),right(nullptr){}
};
typedef Tnode* TnodeTree;
void TnodeInsert(TnodeTree,std::string);
void PrintTnode(const Tnode&);
void PrintTnodeTree(TnodeTree);
void PrintTnodeTreeStack(TnodeTree);
}