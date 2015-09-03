/*
Given 2 binary arrays A and B i.e. containing only 0s and 1s each of size N. 
Find indices i,j such that Sum of elements from i to j in both arrays is equal and j-i (i.e. the length of the set i,j) is the maximum possible value.
*/

/*
This is same as finding the longest subarray with sum zero in the array C[i] = A[i] - B[i]. 

Prefix sums + hashtable should give it.

- Anonymous 2 years ago | Flag Reply
-1
of 1 vote
C[i] = A[i] - B[i].?? 

This won't work. The contiguous subarray sum of A and B might be equal, but C[i] need not be zero. Consider the case:
A = 0101
B = 1010 

Then C would be -11-11. C is not zero here, but you still have got a subarrays in A and B whose sums are equal
*/

int maxLength( int a[], int n ) {
  unordered_map<int,int> m;
  m[0] = 0;
  int sum = 0;
  int maxDiff = 0;
  for(int i=0;i<n;i++) {
    sum += a[i];
    if( m.find(sum) != m.end() ) {
      maxDiff = max( maxDiff, i - m[sum] );
    } else 
      m [ sum ] = i+1;
  }
  
  return (i+1);
}
