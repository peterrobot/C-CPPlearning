#include "tree.h"
#include <stdio.h>
#include <random>

void t::BinaryNode::Add(const int in, const compare f)
{
    if(f(in, _content))
    {
        if(left == nullptr)
        {
            left = new BinaryNode(in);
            return;
        }
        else left->Add(in, f);
    }
    else
    {
        if(right == nullptr)
        {
            right = new BinaryNode(in);
            return;
        }
        else right->Add(in, f);
    }
}

void t::BinaryNode::Print()
{
    if(left != nullptr) left->Print();
    printf("%d\n", _content);
    if(right != nullptr) right->Print();
}

void t::BinaryNode::Search(const int key, compare f, bool* b)
{
    if(f(_content, key))
    {
        if(left == nullptr) *b = false;
        else left->Search(key, f, b);
    }
    else
    {
        if(_content == key) *b = true;
        else if(right == nullptr) *b = false; 
        else right->Search(key, f, b);
    }
}

bool t::BinaryNode::Find(const int key, const compare f)
{
    bool* b = new bool;
    Search(key, f, b);
    return *b;
}


bool t::BinaryTree::bigger(const int a, const int b)
{
    return a > b;
}

bool t::BinaryTree::smaller(const int a, const int b)
{
    return a < b;
}

void t::BinaryTree::Add(const int in)
{
    Node p = root;
    while(true)
    {
        if(_pf(in, p->_content))
        {
            if(p->left == nullptr)
            {
                p->left = new node(in);
                return;
            }
            p = p->left;
        }
        else
        {
            if(p->right == nullptr)
            {
                p->right = new node(in);
                return;
            }
            p = p->right;
        }
    }
}

t::BinaryTree::Node t::BinaryTree::Find(const int index) const
{
    Node p = root;
    while(true)
    {
        if(_pf(index, p->_content))
        {
            if(p->left == nullptr) return nullptr;
            p = p->left;
        }
        else
        {
            if(index == p->_content) return p;
            if(p->right == nullptr) return nullptr;
            p = p->right;
        }
    }
}

void t::BinaryTree::node::Add(const Node other, compare f)
{
    if(other == nullptr) return;
    Node p = this;
    while(true)
    {
        if(f(other->_content, p->_content))
        {
            if(p->left == nullptr)
            {
                p->left = other;
                return;
            }
            p = p->left;
        }
        else
        {
            if(p->right == nullptr)
            {
                p->right = other;
                return;
            }
            p = p->right;
        }
    }
}


void t::BinaryTree::Delete(const int index)
{
    Node p = root;
    if(p->_content == index)
    {
        root = p->right;
        root->Add(p->left, _pf);
        delete(p);
        return;
    }
    Node fore;
    bool flag;
    while(true)
    {
        if(_pf(index, p->_content))
        {
            if(p->left == nullptr)
            {
                perror("Cannot delete a number that dose not exist!\n");
                return;
            }
            fore = p;
            p = p->left;
            flag = true;
        }
        else
        {
            if(p->_content == index) break;
            if(p->right == nullptr)
            {
                perror("Cannot delete a number that does not exist!\n");
                return;
            }
            fore = p;
            p = p->right;
            flag = false;
        }
    }
    Node r = p->right, l = p->left;
    switch (flag)
    {
    case true:
        fore->left = nullptr;
        break;
    case false:
        fore->right = nullptr;
        break;
    }
    delete(p);
    fore->Add(r,_pf);
    fore->Add(l,_pf);
}

void t::BinaryTree::node::Print() const
{
    if(left != nullptr) left->Print();
    printf("%d\n", _content);
    if(right != nullptr) right->Print();
}

void t::BinaryTree::Print() const
{
    root->Print();
}

void t::BinaryTree::DeleteTree(Node p)
{
    if(p)
    {
        DeleteTree(p->left);
        DeleteTree(p->right);
        delete(p);
    }
}

t::BinaryTree::~BinaryTree()
{
    DeleteTree(root);
}

void treeTest()
{
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(0,100);

    t::BinaryTree a(50);
    for(int i = 0; i<10; ++i)
    {
        a.Add(u(e));
    }

    a.Print();

    auto c = a.Find(20);

    printf_s("Find the number %d\n", c->_content);

    a.Delete(20);

    a.Print();
}