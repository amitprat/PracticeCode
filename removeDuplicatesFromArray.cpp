#include      <iostream>
using namespace std;

int removeElem(int a[],int n,int e)
{
    int i =0,j=0;
    while(j<n){
        a[i] = a[j++];
        if(a[i] != e)   i++;
    }
    return i;
}
int removeDups(int a[],int n)
{
    int i = 0,j=1;
    while(j < n)
    {
        while(a[i] == a[j])   j++;
        a[i+1] = a[j++];
        i++;
    }
    return i;
}
int main()
{
    int a[] = {1,1,1,2,2,2,2,3,3,4,4};
    int e = 1;
    int n = 11;
    //n = removeElem(a,n,e);
    n = removeDups(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
