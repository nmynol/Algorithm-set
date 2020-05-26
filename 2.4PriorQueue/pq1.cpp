// 优先队列的堆实现（最大堆）

#include<iostream>
#include<string>
using namespace std;

#define MAX 100


template <class T>
class PriorQueue
{
    T *pq;
    int N;
public:
    /*
        Two functions need to modify
    */
    bool less(int i, int j)
    {
        return pq[i] < pq[j];
    }
    void swap(int a, int b) 
    {
        T temp = pq[a];
        pq[a] = pq[b];
        pq[b] = temp;
    }

    void swim(int k);   // go up
    void sink(int k);   // go down

    PriorQueue(int maxN) // construct function
    {
        pq = new T [maxN + 1];
        N = 0;
    }
    bool isEmpty() // whether empty or not
    {
        return N == 0;
    }
    int size() // look for size
    {
        return N;
    }
    void insert(T v) // insert a new one
    {
        pq[++N] = v;
        swim(N);
    }
    T delMax() // take the biggest one out
    {
        T max = pq[1];
        swap(1, N--);
        // delete &pq[N + 1] ;
        sink(1);
        return max;
    }
};


template<class T>
void PriorQueue<T>::swim(int k)
{
    while(k > 1 && less(k / 2, k))
    {
        swap(k / 2, k);
        k = k / 2;
    }
}
template<class T>
void PriorQueue<T>::sink(int k)
{
    while(2 * k <= N)
    {
        int j = 2 * k;
        if(j < N && less(j, j + 1)) j++;
        if(!less(k, j)) break;
        swap(k, j);
        k = j;
    }
}

class Comparable
{
    int x;
    string s;
public:
    bool operator < (const Comparable &temp);
    bool operator > (const Comparable &temp);
    friend ostream & operator<<( ostream & os,const Comparable & c);
    friend istream & operator>>( istream & is,Comparable & c);
};
bool Comparable::operator < (const Comparable &temp)
{
    return x < temp.x;
}
bool Comparable::operator > (const Comparable &temp)
{
    return x > temp.x;
}
ostream & operator<<( ostream & os,const Comparable & c)
{
    os << c.s << ' ' << c.x;
    return os;
}
istream & operator>>( istream & is,Comparable & c)
{
    is >> c.s >> c.x;  
    return is;
}

int main()
{
    PriorQueue<Comparable> prior(MAX);
    int n;
    cin >> n;
    Comparable x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        prior.insert(x);
    }
    cout << prior.delMax();
}