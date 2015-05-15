/*
Write a function which returns the number of times the digit "1" appears in a number which is generated from raising 11 to the Nth power where N is passed in as an input parameter. The range of N is 0 to 1,000. 

Be sure to unit test your solution. 

For instance, If N is 3, the number is 1331 and the function returns 2. 
If N is 5, the function returns 3. 
If N is 10, the function returns 1 and so on.


public int solution(int N) { ... }
You have 30 minutes to complete the problem.
*/
/*
Sol : Use binomial coefficient method
(a+b)^n = a^n + nC1*a*(n-1).b^1....

So for 11^2 = (10+1)^2 = 10^2 + 1^2 + 2*10
Problem - explaining for 11^10 which contains only one 1.
1) Consider first and last term always
1)Consider only terms which contain only binomial multiplier as multiple of 10
2) If n is
*/
