#pragma once

namespace tree
{
    template <typename T>
    struct Node
    {
        T _element;
        Node* P[2];
    };

    template <typename T>
    class MultiTree
    {
    public:
        MultiTree();
        ~MultiTree();
    protected:
        Node<T>* Root;

        enum Multi{brother=0, child=1};
    };

    template <typename T>
    class BinaryTree
    {
    public:
        BinaryTree();
        ~BinaryTree();
    protected:
        Node<T>* Root;

        enum Binary{right=0,left=1};
    };

    template <typename T>
    class ALVtree : public BinaryTree<T>
    {
    public:
        ALVtree();
        ~ALVtree();
    };
}

namespace t
{
    class BinaryNode
    {
    public:
        typedef BinaryNode* Node;
        typedef bool (*compare)(int,int);

        static bool bigger(int a,int b) {return a > b;}
        static bool smaller(int a,int b) {return a < b;}
    public:
        BinaryNode(int in) : _content(in) , right(nullptr) ,left(nullptr)  {}

        void Add(int, compare);
        void Add(Node);
        void Print();
        bool Find(int, compare);
        void Delete(int);

    private:
        void Search(int, compare, bool*);

        int _content;
        Node right;
        Node left;
    };

    class BinaryTree
    {
    public:
        struct node
        {
            int _content;
            node* left;
            node* right;
            node(int in) : _content(in) , left(nullptr) , right(nullptr){}
            void Print() const;
            void Add(node*, bool (*)(int,int));
        };
        
        typedef node* Node;
        typedef bool (*compare)(int,int);

        static bool bigger(int,int);
        static bool smaller(int,int);

    public:
        BinaryTree(int in, compare f = &bigger) :
            root(new node(in)) , _pf(f) {}
        ~BinaryTree();
        void Add(int);
        void Delete(int);

        Node Find(int) const;
        
        void Print() const;
    private:
        void DeleteTree(Node);
    private:
        Node root;
        compare _pf;
    };
}

void treeTest();