/*
Given an array containing sequence of bits (0 or 1), you have to sort this array in the ascending order i.e. all 0' in first part of array followed by all 1's. The constraints is that you can swap only the adjacent elements in the array. Find the minimum number of swaps required to sort the given input array. 

Example: Given the array (0,0,1,0,1,0,1,1) the minimum number of swaps is 3. 

Note: You just need to complete the function given below for this task. The function is given a binary string as input and returns the required answer.

Or

Given an array of 0’s and 1’s. Need to tell minimum number of swaps required to take all 1’s to one side. Only adjacent swap is allowed.
*/

/*
Solution - 
Its actually the sum of the number of 0's to the right for each 1. The pseudo code is as follows :-
*/


swap = 0, count = 0
for (j = N; j >= 1; j--) {
       if(arr[j] == 0)
              count++
       else
              swaps += count
}
print(swaps)
