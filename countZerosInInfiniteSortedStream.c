#include <stdio.h>


int countzeros(int a[],int l,int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        if(a[mid] == 0 && a[mid+1] == 1)
            return (mid-l+1);
        else if(a[mid-1] == 0 && a[mid] == 1)
            return mid - l;
        else if(a[mid] == 1)
            return countzeros(a,l,mid-1);
        else if(a[mid] == 0)
            return mid-l+1 + countzeros(a,mid+1,r);
    }
    return 0;
}
int main()
{
   int arr[] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1};
   int l = 0;
   while(arr[1<<l]==0)  l++;

   int count = (1<<(l-1)) + countzeros(arr,(1<<(l-1)),1<<l);
   printf("count : %d\n",count);
   return 0;
}
