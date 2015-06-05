/*
Given a function rev(int i) which reverses the segment of array ar[] from 0-i, Implement a function sort() using rev().
pancake sorting
*/
/*T=O(n2) */
void sort(int a[],int n)
{
  for(int i=0;i<n;i++){
    int smallestIndex = find(a,i,n-1);
    if(smallestIndex != i)
      rev(a,i,smallestIndex);
  }
}

/*Assume rev() method takes O(1) time*/
/*T = o(nlgn) method - insertion sort*/
void sort(int a[],int n)
{
  for(int i=1;i<n;i++) {
    int  j = ceil(a,0,i-1,a[i]);
    if(j != -1) {
      rev(a,0,j-1);
      rev(a,0,i-1);
      rev(a,0,i);
      rev(a,0,j);
    }
  }
}
