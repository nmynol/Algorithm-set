
/*
    能用于任何对象的map（二叉搜索树实现）
*/

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
        return a == b;
    }
    bst()                                                                   // 构造函数
    {
        root = nullptr;
    }
    int size();                                                             // 返回树的结点数
    int size(Node<Key, Value> *p);                                          // 返回以这个结点为根结点的子树的结点数
    Value get(Key key);                                                     // 返回键对应的值
    Value get(Node<Key, Value> *root, Key key); 
    void put(Key key, Value val);                                           // 插入键值对
    Node<Key, Value>* put(Node<Key, Value> *root, Key key, Value val);
    Key min();                                                              // 返回最小键
    Node<Key, Value>* min(Node<Key, Value>* root);
    Key max();                                                              // 返回最大键
    Node<Key, Value>* max(Node<Key, Value>* root);
    Key floor(Key key);                                                     // 小于等于键的最大键
    Node<Key, Value>* floor(Node<Key, Value>* root, Key key);
    Key ceiling(Key key);                                                   // 大于等于键的最小键
    Node<Key, Value>* ceiling(Node<Key, Value>* root, Key key);
    Key select(int k);                                                      // 返回排名为k的键（有k-1个键小于他）
    Node<Key, Value>* select(Node<Key, Value>* root, int k);
    int rank(Key key);                                                      // 返回排名为k的键（有k-1个键小于他）
    int rank(Node<Key, Value>* root, Key key);
    void deleteMin();                                                       // 删除最小键的结点
    Node<Key, Value>* deleteMin(Node<Key, Value>* root);
    void deleteMax();                                                       // 删除最大键的结点
    Node<Key, Value>* deleteMax(Node<Key, Value>* root);
    void Delete(Key key);                                                   // 删除指定结点
    Node<Key, Value>* Delete(Node<Key, Value>* root, Key key);
    void search();                                                          // 按顺序打印所有键值
    void search(Key lo, Key hi);                                            // 按顺序打印指定范围内的键值
    void search(Node<Key, Value>* root, Key lo, Key hi);
    void xianxu()
    {
        xianxu(root);
    }
    void xianxu(Node<Key, Value> *root)
    {
        if(root == nullptr) return;
        cout << root->key << ' ' << root->val << endl;
        xianxu(root->left);
        xianxu(root->right);
    }
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
template<class Key, class Value>
Key bst<Key, Value>::min()
{
    return min(root)->key;
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::min(Node<Key, Value>* root)
{
    if(root->left == nullptr) return root;
    return min(root->left);
}
template<class Key, class Value>
Key bst<Key, Value>::max()
{
    return max(root)->key;
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::max(Node<Key, Value>* root)
{
    if(root->right == nullptr) return root;
    return max(root->right);
}
template<class Key, class Value>
Key bst<Key, Value>::floor(Key key)
{
    Node<Key, Value>* x = floor(root, key);
    if(!x) 
    {
        cout << "can't find" << endl;
        return NULL;
    }
    return x->key;
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::floor(Node<Key, Value>* root, Key key)
{
    if(!root) return nullptr;
    if(equal(root->key, key))return root;
    else if(more(root->key, key))return floor(root->left, key);
    Node<Key, Value>* t = floor(root->right, key);
    if(t) return t;
    else return root;
}
template<class Key, class Value>
Key bst<Key, Value>::ceiling(Key key)
{
    Node<Key, Value>* x = ceiling(root, key);
    if(!x) 
    {
        cout << "can't find" << endl;
        return NULL;
    }
    return x->key;
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::ceiling(Node<Key, Value>* root, Key key)
{
    if(!root) return nullptr;
    if(equal(root->key, key))return root;
    else if(less(root->key, key))return ceiling(root->right, key);
    Node<Key, Value>* t = ceiling(root->left, key);
    if(t) return t;
    else return root;
}
template<class Key, class Value>
Key bst<Key, Value>::select(int k)
{
    Node<Key, Value>* x = select(root, k - 1);
    return x->key;
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::select(Node<Key, Value>* root, int k)
{
    if(!root) return NULL;
    int t = size(root->left);
    if(t > k) return select(root->left, k);
    else if(t < k) return select(root->right, k - t - 1);
    else return root;
}
template<class Key, class Value>
int bst<Key, Value>::rank(Key key)
{
    return rank(root, key) + 1;
}
template<class Key, class Value>
int bst<Key, Value>::rank(Node<Key, Value>* root, Key key)
{
    if(!root) return 0;
    if(less(key, root->key)) return rank(root->left, key);
    else if(more(key, root->key)) return 1 + size(root->left) + rank(root->right, key);
    else return size(root->left);
}
template<class Key, class Value>
void bst<Key, Value>::deleteMin()
{
    root = deleteMin(root);
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::deleteMin(Node<Key, Value>* root)
{
    if(root->left == nullptr) return root->right;
    root->left = deleteMin(root->left);
    root->N = size(root->left) + size(root->right) + 1;
    return root;
}
template<class Key, class Value>
void bst<Key, Value>::deleteMax()
{
    root = deleteMax(root);
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::deleteMax(Node<Key, Value>* root)
{
    if(root->right == nullptr) return root->left;
    root->right = deleteMax(root->right);
    root->N = size(root->left) + size(root->right) + 1;
    return root;
}
template<class Key, class Value>
void bst<Key, Value>::Delete(Key key)
{
    root = Delete(root, key);
}
template<class Key, class Value>
Node<Key, Value>* bst<Key, Value>::Delete(Node<Key, Value>* root, Key key)
{
    if(!root) return nullptr;
    if(less(key, root->key)) root->left = Delete(root->left, key);
    else if(more(key, root->key)) root->right = Delete(root->right, key);
    else
    {
        if(root->left == nullptr) return root->right;
        if(root->right == nullptr) return root->left;
        Node<Key, Value>* t = root;
        root = min(root->right);
        root->right = deleteMin(root->right);
        root->left = t->left;
    }
    root->N = size(root->left) + size(root->right) + 1;
    return root;
}
template<class Key, class Value>
void bst<Key, Value>::search()
{
    search(min(), max());
}
template<class Key, class Value>
void bst<Key, Value>::search(Key lo, Key hi)
{
    search(root, lo, hi);
}
template<class Key, class Value>
void bst<Key, Value>::search(Node<Key, Value>* root, Key lo, Key hi)
{
    if(!root) return ;
    if(less(lo, root->key)) search(root->left, lo, hi);
    if((less(lo, root->key) || equal(lo, root->key)) && (more(hi, root->key) || equal(hi, root->key)))
        cout << root->key << ' ' << root->val << endl;
    if(more(hi, root->key)) search(root->right, lo, hi);
}
int main()
{
    bst<char, int> tree;
    tree.put('b', 34);
    tree.put('d', 1);
    tree.put('g', 1);
    tree.put('c', 1);
    tree.put('e', 1);
    tree.search();
    tree.Delete('b');
    tree.search();
    return 0;
}