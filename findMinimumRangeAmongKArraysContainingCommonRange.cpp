
/* Problem - 
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists. 

For example, 
List 1: [4, 10, 15, 24, 26] 
List 2: [0, 9, 12, 20] 
List 3: [5, 18, 22, 30] 

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
*/

/*Solution - 
Taken from Careercup-
There are k lists of sorted integers. Make a min heap of size k containing 1 element from each list. Keep track of min and max element and calculate the range. 
In min heap, minimum element is at top. Delete the minimum element and another element instead of that from the same list to which minimum element belong. Repeat the process till any one of the k list gets empty. 
Keep track of minimum range. 

For eg. 
List 1: [4, 10, 15, 24, 26] 
List 2: [0, 9, 12, 20] 
List 3: [5, 18, 22, 30] 

Min heap of size 3. containing 1 element of each list 
Heap [0, 4, 5] 
Range - 6 

Remove 0 and add 9 
Heap [4, 9, 5] 
Range - 6 

Remove 4 and add 10 
Heap [5, 9, 10] 
Range - 6 

and so on.... 
Minheap status - 

0   9   9   9   15  15  15  24  24
4   4   10  10  10  12  20  20  20
5   5   5   18  18  18  18  18  22

Range-
6   6   6   10  9   7   6   7   5

Minimum is 6 ( 20-24)
*/

/*Code*/
typedef pair<int,int> Element;
Range minrange ( vector < vector<int> > v, int n ) {
  Range minRange;
  int len;
  int minLen= INT_MAX;
  int curMin= INT_MAX;
  int curMax = INT_MIN;
  Minheap<Element> heap;  //<array no, element> 
  for(int i=0;i<n;i++) {
    heap.insert( v[i][0] );
    if(v[i][0] < curMin ) curMin = v[i][0];
    if(v[i][0] > curMax ) curMax = v[i][0];
    if(curMax - curMin +1 > minLen) { 
      minLen = curMax - curMin +1;
      minRange = Range(curMin,curMax);
    }
  }
 
  while( 1 ) {
    Element tmp = heap.extractMin();
    if(tmp.elemIndex+1 >= v[tmp.arrIndex].size() ) break;
    heap.insert( make_pair(tmp.arrIndex,tmp.elemIndex+1) ); 
    if( v[tmp.arrIndx][tmp.elemIndex+1] > curMax ) curMax = v[arrIndx][tmp.elemIndex+1];
    curMin = v[heap.top().arrIndex][heap.top().elemIndex];
    if(curMax - curMin +1 > minLen) { 
      minLen = curMax - curMin +1;
      minRange = Range(curMin,curMax);
    }
  }
  
  return minRange;
}
