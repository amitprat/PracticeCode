#include    <iostream>
using namespace std;

int hoare(int a[],int l,int r,int e) {  /*This method doesn't work fine for this scenerio*/
    int x = (e == -1 ? a[r] : e);
    int i = l-1;
    int j = r+1;
    while(true) {
        do {j--; } while( a[j] > x);
        do {i++; } while( a[i] < x);
        if(i < j) swap(a[i],a[j]);
        else return j;
    }
}
int lomuto(int a[],int l,int r) {
    int j = l-1;
    int x = a[r];
    for(int i=l;i<r;i++) {
        if(a[i] <= x)
            swap(a[i],a[++j]);
    }
    swap(a[j+1],a[r]);
    return j+1;
}
int find(int a[],int l,int r,int k)
{
    if(l > r)   return -1;
    int p = lomuto(a,l,r);
    int q = p-l+1;
    if (q == k) return p;
    else if ( q < k ) return find(a,p+1,r,k-q);
    else return find(a,l,p-1,k);
}
int main()
{
    int a[] = {2,4,5,1,2};
    int k = 3;
    int n = sizeof(a)/sizeof(a[0]);
    int kthElem = find(a,0,n-1,k);
    cout<<a[kthElem]<<endl;
    swap(a[kthElem],a[n-1]);
    int p = lomuto(a,0,n-1);
    for(int i=0;i<=p;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
