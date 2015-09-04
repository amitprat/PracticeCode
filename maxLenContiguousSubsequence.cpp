/*
Taken from geeksforgeeks.org
Longest Consecutive Subsequence
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples

Input: arr[] = {1, 9, 3, 10, 4, 20, 2};
Output: 4
The subsequence 1, 3, 4, 2 is the longest subsequence
of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
The subsequence 36, 35, 33, 34, 32 is the longest subsequence
of consecutive elements. 

1) Create an empty hash.
2) Insert all array elements to hash.
3) Do following for every element arr[i]
....a) Check if this element is the starting point of a 
       subsequence.  To check this, we simply look for
       arr[i] - 1 in hash, if not found, then this is
       the first element a subsequence.  
    
       If this element is a first element, then count 
       number of elements in the consecutive starting 
       with this element.

       If count is more than current res, then update    
       res.
       
*/

int findLongest( char *word )  {
  unordered_set<char> s;
  int n  = strlen(word);
  for(int i=0;i<n;i++)  s.insert( word[i] );
  int mxSz = 0;
  for(int i = 0;i<n;i++) {
    //if this is the starting element of new sequence, only then count for seq
    if( s.find( word[i] - 1) == s.end() ) {
      char j = word[i];
      int sz = 0;
      while(s.find(j) != s.end() ) {
        j++;
        sz++;
      }
      if(sz > maxSz)  maxSz = sz;
    }
  }
  return maxSz;
}
