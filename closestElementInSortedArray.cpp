/*find closest in sorted array, nearest element in sorted array, least difference element in sorted array, minimum difference elemnt in sorted array*/
#include    <iostream>
#include    <cmath>
using namespace std;

int findClosest(int a[],int n,int x)
{
    int l = 0, r = n-1;
    while(l < r) {
        int m = (l+r)/2;
        int d1 = abs(a[m]-x);
        int d2 = abs(a[m+1]-x);
        if(d2 < d1)
            l = m+1;
        else
            r = m;
    }
    return a[r];
}
int findClosestAlt(int a[],int n,int x)
{
    int l=0,r=n-1;
    while(r-l>1) {
        int m = (l+r)/2;
        if(a[m]==x) return x;
        if(a[m]<x)  l = m;
        else    r=m;
    }
    return (abs(a[r]-x)<abs(a[l]-x))?a[r]:a[l];
}
int main()
{
    int a[] = {2, 7, 9, 10, 13, 16};
    int n = 6;
    int x = 12;
    cout<< findClosestAlt(a,n,x)<<endl;
    return 0;
}
