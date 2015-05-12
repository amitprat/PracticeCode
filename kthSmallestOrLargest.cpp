/*
selection algorithm
Kth smallest
Kth largest
*/

int util(int a[],int l,int r,int k)
{
  if(l > r) return -1;
  int p = partition(a,l,r);
  int q = p-l+1;  //number of elements on left side of pivot including pivot element
  if(q == k) // if it is equal then pivot is kth smallest
    return a[p];
  else if(q > k ) //number of elements on left side of pivot are greater than kth smallest we are seraching for
    return util(a,l,p-1,k); //it can be found on left half, search it here
  else
    return util(a,p+1,r,k-q); //remove q smallest element on left side of pivot and search in right half
}
int kthsmallest(int a[[],int n,int k) //1st smallest is smallest element
{
  return util(a,0,n-1,k);
}
int kthsmallest(int a[[],int n,int k) //1st largest is largest element means nth smallest
{
  return util(a,0,n-1,n-k+1);
}
