// Quick sort for any object（need to fix a few fuction according to your object）

#include<iostream>
using namespace std;

template <class T>
class Sort
{
public:
    /*
    two functions you need to modify according to your object
    */
    void swap(T arr[], int a, int b) //define proper swap function for your object
    {
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    bool less(T a, T b) //define proper compare function (here means <) for your object
    {
        return a.x < b.x;
    }
    /****************
        Quick sort 
    *****************/
    void quicksort(T arr[], int len)
    {
        sort(arr, 0, len - 1);
    }
    void sort(T arr[], int lo, int hi)
    {
        if(lo >= hi)
            return ;
        int j = partition(arr, lo, hi);
        sort(arr, lo, j - 1);
        sort(arr, j + 1, hi);
    }
    int partition(T arr[], int lo, int hi)
    {
        T v = arr[lo];
        int i = lo, j = hi + 1;
        while(true)
        {
            while(less(arr[++i], v))if(i == hi)break;
            while(less(v, arr[--j]))if(j == lo)break; // actually "if(j == lo)break" is redundant;
            if(i >= j)break;
            swap(arr, i, j);
        }
        swap(arr, lo, j);
        return j;
    }
};

// A simple example
class Comparable
{
public:
    int x;
    char a;
    friend ostream & operator<<( ostream & os,const Comparable & c);
    friend istream & operator>>( istream & is,Comparable & c);
};
istream & operator>>(istream & in,Comparable & c)
{
    in >> c.a >> c.x;
    return in;
}
ostream & operator<<(ostream & out,const Comparable & c)
{
    out << c.a << ' ' << c.x;
    return out;
}



int main()
{
    int n;
    cin >> n;
    Comparable a[n];
    Sort<Comparable> com;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    com.quicksort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}