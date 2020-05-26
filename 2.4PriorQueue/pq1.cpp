// 优先队列的堆实现（最大堆）

#include<iostream>
#include<string>
using namespace std;

#define MAX 100

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

class PriorQueue
{
    Comparable *pq;
    int N;
public:
    bool less(int i, int j);
    void swap(int a, int b);    
    void swim(int k);   // go up
    void sink(int k);   // go down

    PriorQueue(int maxN)
    {
        pq = new Comparable [maxN + 1];
        N = 0;
    }
    bool isEmpty()
    {
        return N == 0;
    }
    int size()
    {
        return N;
    }
    void insert(Comparable v)
    {
        pq[++N] = v;
        swim(N);
    }
    Comparable delMax() 
    {
        Comparable max = pq[1];
        swap(1, N--);
        // delete &pq[N + 1] ;
        sink(1);
        return max;
    }
};

bool PriorQueue::less(int i, int j)
{
    return pq[i] < pq[j];
}

void PriorQueue::swap(int a, int b)
{
    Comparable temp = pq[a];
    pq[a] = pq[b];
    pq[b] = temp;
}

void PriorQueue::swim(int k)
{
    while(k > 1 && less(k / 2, k))
    {
        swap(k / 2, k);
        k = k / 2;
    }
}

void PriorQueue::sink(int k)
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

int main()
{
    PriorQueue prior(MAX);
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