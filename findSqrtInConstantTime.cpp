/*
Reference : http://www.careercup.com/question?id=5679974386237440
Find whether a number (which is less than 10000) is a perfect square or not. If it is perfect square, calculate square root in O(1) without using sqrt function. 
Example : 1024 => 32 
1025=> not perfect square.
*/

/*Sol 
Preprocessing step: 
Calculate squares of numbers from 1 to 100 (Note that we'll query the numbers that are less than 10000) and put the number and the square to a hashmap/hashtable value = the numbers from 1 to 100 and the keys are the corresponding square of that number, e.g.,
<1, 1>
<4, 2>
<9, 3>
...
<10000, 100>
Time complexity of the preprocess = TO(N), but since N is constant which is equal to 100, then time complexity is constant time - O(1)


Query Step: 
Once the hashtable is created in the preprocessing step, all the queries can be done in in O(1) time. Of course, assuming that the hashmap/hashtable used has O(1) for get, put, containsKey operations.

Time complexity of the queries: O(1)
*/
