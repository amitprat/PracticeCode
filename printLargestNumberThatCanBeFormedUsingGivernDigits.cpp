//Ref::http://www.careercup.com/question?id=5645040497983488
/*
Given a Integer, find the maximum number that can be formed from the digits. 
Input : 8754365 
output : 8765543 
*/

I told solution in nlogn. He asked me optimize further.
1. Sort the digits.

2.
We can use Hash Table to optimize further, --> O(n)

Algorithm:
1. Take a hash table with size 10 (0 to 9).
2. Store the count of every digit from 0 to 9.
3. Print the index of the Hash table with respect to digit count in the reverse direction (from 9 to 0).

Example: 

Hash table after digit count for 8754365 -> (0 0 0 1 1 2 1 1 1 0) 
Print the index of the hash table with respect to their count in reverse order -> 8765543
Time Complexity : O(n)
