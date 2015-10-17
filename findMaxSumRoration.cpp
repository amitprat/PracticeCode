/*
Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possbile of summation of i*arr[i].

Example:

Input: arr[] = {1, 20, 2, 10}
Output: 72
We can 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Output: 330
We can 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330

res = res + sum - n*a[n-j];

Derivation - 

1) If you rotate right, add the sum of all elements except last element as it will move to front.
  res = res + sum - a[n-j];
2) Now, substract the last element as it moved back to beginning from (n-1) position;
  res = res + sum - a[n-j] - (n-1)*a[n-j];
  res = res + sum - a[n-j] - n*a[n-j] + a[n-j];
  res = res + sum -n*a[n-j];
*/

void fun() {
  for(int i=0;i<n;i++) {
    res += i*a[i];
    sum +=a[i];
  }
  int maxRes = res;
  for(int i=1;i<n;i++) {
    res = res + sum - n*a[n-i];
    if(res > maxRes)
      maxRes = res;
  }
}
