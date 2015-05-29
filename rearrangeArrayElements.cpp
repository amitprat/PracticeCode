/*
Microsoft - 
Arrange the numbers in an array in alternating order. 
For example if the array is [a1, a2, a3, a4.. ]arrange the array such that b1<=b2>=b3<=b4 and so on. 
Sampe Input: 3 5 7 8 4 9 
Sample Output: 3 < 5 > 4 < 8 >7 < 9

Google -
Given an array of integers, sort the array into a wave like array, namely 
a1 >= a2 <= a3 >= a4 <= a5.....
*/

Three ways to tackle this problem - 
1) 
Calculate median of unsorted array - O(n)
  - (partition array around n/2 or (n+1)/2 smallest element)
Arrange elements around median of each side
  - put at i-1 pos =  largest on left side
  - put at i+1 pos = smallest on right hand side
  - considering left and right subarrays as two seperate arrays -arrange elements
  
2) Easier way = T = O(nlgn) time;

Sort array
for i=1 to n-1
  swap(a[i],a[i+1])
  
3) Best Way - T = O(n)
  void sol(int a[],int n) {
    for(int i=1;i<n;i++) {
      if( i%2 && a[i] < a[i-1] ) // variation a<b
        swap(a[i],a[i-1]);  //keeping variation that element at odd position should be greater than element at even position assuming starting index = 0
      else if( i%2 == 0 && a[i] > a[i-1] ) // variation b>c
        swap(a[i],a[i-1]);
    }
  }
  
  Proof - : Reference : http://stackoverflow.com/questions/17777762/aranging-integers-in-a-specific-order
  Given any three successive numbers in the array, there are four possible relationships:

a < b < c
a < b > c
a > b < c
a > b > c
In the first case we know that a < c. Since the first condition is met, we can swap b and c to meet the second condition, and the first condition is still met.

In the second case, both conditions are already met.

In the third case, we have to swap a and b to give b < a ? c. But we already know that b < c, so if a < c then swapping to meet that second condition doesn't invalidate the first condition.

In the last case we know that a > c, so swapping a and b to meet the first condition maintains the validity of the second condition.

Now, you add a fourth number to the sequence. You have:

a < b > c ? d
If c < d then there's no need to change anything. But if we have to swap c and d, the prior condition is still met. Because if b > c and c > d, then we know that b > d. So swapping c and d gives us b > d < c.

You can use similar reasoning when you add the fifth number. You have a < b > c < d ? e. If d > e, then there's no need to change anything. If d < e, then by definition c < e as well, so swapping maintains the prior condition.

Alternative implementation - 
Pseudo code that implements the algorithm:

for i = 0 to n-2
    if i is even
        if (a[i] > a[i+1])
            swap(a[i], a[i+1])
        end if
    else
        if (a[i] < a[i+1])
            swap(a[i], a[i+1])
    end
  
