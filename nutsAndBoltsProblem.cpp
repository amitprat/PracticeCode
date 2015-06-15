// T = O(nlgn) in avarage case, T = O(n2) worst case
//normal approach , T = O(n2) in each case

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int partition(char a[],int l,int r,char p)
{
    int i = l-1;
    int j = r+1;
    while(1)
    {
        do { i++; }while(a[i] < p);
        do { j--; }while(a[j] > p);
        if(i < j) swap(a[i],a[j]);
        else return j;
    }
}

void makePairs(char nuts[],char bolts[],int l,int r)
{
    if(l < r) {
        int pivot = partition(nuts,l,r,bolts[r]);
        partition(bolts,l,r,nuts[pivot]);
        
        makePairs(nuts,bolts,l,pivot-1);
        makePairs(nuts,bolts,pivot+1,r);
    }
}
int main()
{
  char nuts[] = {'@', '#', '$', '%', '^', '&'};
  char bolts[] = {'$', '%', '&', '^', '@', '#'};
  int n  = sizeof(nuts)/sizeof(char);
  makePairs(nuts,bolts,0,n-1);
  
  for(int i=0;i<n;i++) {
      cout<<nuts[i]<<" --> "<<bolts[i]<<endl;
  }
  return 0;
}
