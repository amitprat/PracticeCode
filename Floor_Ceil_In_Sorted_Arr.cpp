#include <iostream>
using namespace std;

int ceil(int a[],int l,int r,int e)
{
    if(l < r) {
        int m = (l+r)/2; //get lower median
        if(a[m] == e)   return m;
        if(a[m] < e)
            return ceil(a,m+1,r,e);
        return ceil(a,l,m,e);
    }
    return  (a[r] >= e ) ? r : -1;
}
int floor(int a[],int l,int r,int e)
{
    if(l < r) {
        int m = (l+r+1)/2; //get upper median
        if(a[m] == e) return m;
        else if(a[m] > e)
            return floor(a,l,m-1,e);
        return floor(a,m,r,e);
    }
    return (a[l] <= e ) ? l : -1;
}

int main()
{
    int a[] = {1,2,2,2,2,2,4,6,65,67,68,245,359};
    int sz = sizeof(a)/sizeof(int);
    for(int i=-1;i<=100;i++) {
        int fres = floor(a,0,sz-1,i);
        int cres = ceil(a,0,sz-1,i);
        cout<<"For elem : "<<i<<" Floor : "<<( ( fres== -1) ? -1 : a[fres] )<<" , ";
        cout<<" Ceil : "<<( (cres == -1) ? -1 : a[cres] )<<endl;
    }
}
