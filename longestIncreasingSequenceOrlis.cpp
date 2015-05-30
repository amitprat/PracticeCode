#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
/* lis() returns the length of the longest increasing subsequence in
    arr[] of size n */
int lis( int a[], int n )
{
    int lis[n];
    for(int i=0;i<n;i++) lis[i] = 1;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++)
            if(a[j] >= a[i])
                lis[j] = max(lis[j],lis[i]+1);
    }
    int max = -1;
    for(int i=0;i<n;i++)
        if(lis[i] > max)
            max = lis[i];
    return max;
}


int rec(int a[],int n,int pos,int prev,int &max1) {
    if(pos == n)    return 0;
    int size = 0,maxsize = 0;
    for(int i=pos;i<n;i++) {
        if(a[i] >= prev)
            size = 1 + rec(a,n,i+1,a[i],max1);
        if(size > maxsize)
            maxsize = size;
    }
    if(maxsize > max1)
        max1 = maxsize;
    return maxsize;
}

int ceil(int a[],int l,int r,int x) {
    if(l<r) {
        int m = (l+r)/2;
        if(a[m] >= x) return ceil(a,l,m,x);
        else return ceil(a,m+1,r,x);
    }
    return r;
}
int nlgn(int a[],int n)
{
    int table[n];
    table[0] = a[0];
    int pos = 1;
    for(int i=1;i<n;i++) {
        if(a[i] < table[0])
            table[0] = a[i];
        else if(a[i] > table[pos-1])
            table[pos++] = a[i];
        else
            table[ ceil(a,0,pos-1,a[i]) ] = a[i];
    }
    return pos;
}
/* Driver program to test above function */
int main()
{
  int arr[] = { 10, 4, 9, 12,23,13,14,15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LIS [using n^2 DP method ] is %d\n", lis( arr, n ) );
  int max1 = -1;
  rec(arr,n,0,-1,max1);
  cout<<"Length of LIS [ using 2^n REC method ] is "<<max1<<endl;
  cout<<"Length of LIS [ using nlgn DP method ] is "<<nlgn(arr,n)<<endl;
  getchar();
  return 0;
}
