/* taken from  - http://n00tc0d3r.blogspot.com/2013/06/find-element-that-appears-once.html
Find the element that appears once

Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
Examples:

Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2
Solution

We can sort the elements and then go through the sorted list to find out the number that has no duplicates. It takes O(1) space but runs in O(nlogn) time (There do exist sorting algorithms that have O(n) time complexity but they all requires special elements, e.g. elements are within a small range or have limited digits.).

We can use a hash table to store the occurrences of each element. It takes O(n) time but requires O(n) space.

We cannot use XOR on all elements since all elements occurring odd times (Reminder: n XOR n = 0 and n XOR n XOR n = n).

Notice that all other numbers occurs three times. That said, if we sum them up, the sum must be multiple of 3. Can we take advantage of this?
If the singleton number is less than 3, say {2, 2, 2, 1}, we can simply sum them up and mod by 3. But there is little chance of such situation...
What if we sum up each bit of numbers? Then for each digit, mod the sum by 3 and the left-over must be the bit in the single element.
*/
 public static int findSingle(int[] array) {  
   int result = 0;  
   
   // Note: Java integer size is always 32-bit  
   for (int i=0; i<32; ++i) {  
     int mask = (1 << i);  
     int sum = 0;  
     for (int j=0; j<array.length; ++j) {  
       if ((array[j] & mask) != 0) ++sum;  
     }  
     result |= ((sum%3) << i);  
   }  
   
   return result;  
 }  
/*This algorithm runs in time O(kn) = O(n), where n is the size of the given array and k is the total number of digits in an integer.
*/
