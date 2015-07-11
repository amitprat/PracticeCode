/*taken fron nootcoder blog*/
private int findConsecutive(HashSet<Integer> set, int num, int step) {  
   int len = 0;  
   while (set.contains(num)) {  
     ++len;  
     set.remove(num);  
     num += step;  
   }  
   return len;  
 }  
   
 public int longestConsecutive(int[] nums) {  
   HashSet<Integer> set = new HashSet<Integer>();  
   // find all   
   for (int num : nums) {  
     set.add(num);  
   }  
   // find longest seq  
   int maxLen = 0;  
   for (int num : nums) {  
     if (set.contains(num)) {  
       set.remove(num);  
       int len = 1 + findConsecutive(set, num-1, -1);  
       len += findConsecutive(set, num+1, 1);  
       maxLen = Math.max(maxLen, len);  
     }  
   }  
   return maxLen;  
 }  
