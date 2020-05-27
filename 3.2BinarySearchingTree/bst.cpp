#include<iostream>
using namespace std;

template<class Key, class Value>
class Node
{
public:
    Key key;
    Value val;
    Node *left, *right;
    int N;
    Node(Key key, Value val, int N)
    {
        this->key = key;
        this->val = val;
        this->N = N;
        left = nullptr;
        right = nullptr;
    }
};

template<class Key, class Value>
class bst
{
    Node<Key, Value> *root;
public:
    /*
        需要修改的用于比较的三个函数
    */
    bool less(Key a, Key b)
    {
        return a < b;
    }
    bool more(Key a, Key b)
    {
        return a > b;
    }
    bool equal(Key a, Key b)
    {
        return a = b;
    }
    bst()                                                                   //构造函数
    {
        root = nullptr;
    }
    int size();                                                             //返回树的结点数
    int size(Node<Key, Value> *p);                                          //返回以这个结点为根结点的子树的结点数
    Value get(Key key);                                                     //返回键对应的值
    Value get(Node<Key, Value> *root, Key key); 
    void put(Key key, Value val);                                           //插入键值对
    Node<Key, Value>* put(Node<Key, Value> *root, Key key, Value val);
    // void xianxu()
    // {
    //     xianxu(root);
    // }
    // void xianxu(Node<Key, Value> *root)
    // {
    //     if(root == nullptr) return;
    //     cout << root->key << ' ' << root->val << endl;
    //     xianxu(root->left);
    //     xianxu(root->right);
    // }
};
template<class Key, class Value>
int bst<Key, Value>::size()
{
    return root->size();
}
template<class Key, class Value>
int bst<Key, Value>::size(Node<Key, Value> *p)
{
    if(p == nullptr) return 0;
    else return p->N;
}
template<class Key, class Value>
Value bst<Key, Value>::get(Key key)
{
    return get(root, key);
}
template<class Key, class Value>
Value bst<Key, Value>::get(Node<Key, Value> *root, Key key)
{
    if(root == nullptr) return -1;
    if(less(key, root->key)) return get(root->left, key);
    else if(more(key, root->key)) return get(root->right, key);
    else return root->val;
}
template<class Key, class Value>
void bst<Key, Value>::put(Key key, Value val)
{
    root = put(root, key, val);
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::put(Node<Key, Value> *root, Key key, Value val)
{
    if(root == nullptr) return new Node<Key, Value>(key, val, 1);
    if(less(key, root->key)) root->left = put(root->left, key, val);
    else if(more(key, root->key)) root->right = put(root->right, key, val);
    else if(equal(key, root->key)) root->val = val;
    root->N = size(root->left) + size(root->right) + 1;
    return root;
}


int main()
{
    bst<char, int> tree;
    tree.put('b', 34);
    tree.put('d', 1);
    tree.put('a', 1);
    tree.put('c', 1);
    tree.put('e', 1);
    // tree.xianxu();
    cout << tree.get('a');
    return 0;
}