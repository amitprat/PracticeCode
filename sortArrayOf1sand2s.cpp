#include <iostream>

using namespace std;

void sort(int a[],int n)
{
  int i = 0, j = n-1;
  while(i < j) {
    switch(a[i]) {
      case 1:
        i++;
        break;
      case 2:
        swap(a[i],a[j--]);
        break;
    }
  }
}

void sort1(int a[],int n)
{
  int i = 0, j = 0;
  while(j<n) {
      if(a[j] == 1)
        swap(a[i++],a[j++]);
      else
        j++;
  }
}
int main()
{
   cout << "Hello World" << endl; 
   int a[] = {2,1,1,2,2,1,1,1,1};
   int n = 9;
   sort1(a,n);
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
   cout<<endl;
   return 0;
}

