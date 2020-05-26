// 可以套在任何对象上的快速排序（需要自己修改Comparable对象类）
#include<iostream>
using namespace std;

class Comparable
{
    int x;
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
    os << c.x;
    return os;
}
istream & operator>>( istream & is,Comparable & c)
{
    is >> c.x;  
    return is;
}

class compare
{
public:
    void swap(Comparable arr[], int a, int b)
    {
        Comparable temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    int partition(Comparable arr[], int lo, int hi)
    {
        Comparable v = arr[lo];
        int i = lo, j = hi + 1;
        while(true)
        {
            while(arr[++i] < v)if(i == hi)break;
            while(arr[--j] > v)if(j == lo)break;
            if(i >= j)break;
            swap(arr, i, j);
        }
        swap(arr, lo, j);
        return j;
    }
    void quicksort(Comparable arr[], int lo, int hi)
    {
        if(lo >= hi)
            return ;
        int j = partition(arr, lo, hi);
        quicksort(arr, lo, j - 1);
        quicksort(arr, j + 1, hi);
    }
    void sort(Comparable arr[], int len)
    {
        quicksort(arr, 0, len - 1);
    }
};


int main()
{
    int n;
    cin >> n;
    Comparable a[n];
    compare com;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    com.sort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}