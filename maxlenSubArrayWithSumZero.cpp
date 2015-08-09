/*
Given an array of Integers, find the Maximum length subarray with sum equal to zero.  Solved by constructing Prefix sum array for the given array. In prefix sum array, any number repeating more than once, implies subarray between those indices is 0, so store length of this subarray, check for other repeated values too. ( careful coding required to eliminate bugs) Additionally had used a HashMap(java) to do this solution time efficiently. {code it}
*/

int findMaxLen(int a[],int n) {
  int sum = 0;
  int maxlen = 0;
  unordered_map<int,int, map;
  for(int i=0;i<n;i++) {
    sum += a[i];
    if(a[i] == 0 || sum == 0 || map.find(sum) != map.end() ) {
      if(a[i] == 0) maxlen = max(maxlen,1);
      if(map.find(sum) != map.end() ) maxlen = max(maxlen, i-map[sum]+1);
      if(sum==0)  maxlen = i+1;
    } else 
      map[sum] = i;
  }
  return maxlen;
}
