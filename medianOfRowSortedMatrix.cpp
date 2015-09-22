/*
Find median of row-sor  ted matrix
You are given a matrix n rows, m columns where each row is sorted in increasing order. Find median of the overall elements. What is the time complexity?


Do a merge operation (as we do in the merge phase of merge sort) on each row successively. Then median is the m*n/2 the element id m*n is odd or if its even the media is the average of (m*n/2-1, m*n/2+1)th element. Complexity of this solution is O(nmlg(n)). 

There is a better way to achieve this. We can find the kth smallest element from the 2D array by using a min heap. Then median will be n/2th smallest element. (or avg of n/2-1 and n/2+1 th). 

For example, we can start with building a min heap by inserting first column of the 2D array in O(nlgn) time. Now, at each iteration extract min from the heap and insert the next element from the row of the element extracted (if the min is at the end of the row then no insert). This ensures we are traversing in ascending order. That is , the extracted element at kth iteration will be the kth smallest element. The complexity for such traversal is O(klgn) if k>n.
*/

int median(int mat[][N]) {
  Minheap<Node> heap;
  int t = (N&1)?(n/2):(n/2+1);
  for(int i=0;i<N;i++)  heap.insert(mat[i][0]);
  int prev = 0;
  for(count=0;count<t;count++) {
    Node tmp = heap.extractMin();
    prev = a[tmp.idx];
    if(tmp.idx+1 < N)
      heap.insert(mat[tmp.arrIdx][tmp.idx+1]);
    else 
      heap.insert(INT_MAX);
  }
  if(N&1) return heap.top();
  return (prev+heap.top())/2;
}
