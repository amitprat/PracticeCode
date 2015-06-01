/*
Reference : http://articles.leetcode.com/2010/04/multiplication-of-numbers.html
Tags : Multiplication of all other numbers except the current
  Product Array problem
  Product of all other numbers in array
  
There is an array A[N] of N numbers. You have to compose an array Output[N] such that Output[i] will be equal to multiplication of all the elements of A[N] except A[i]. Solve it without division operator and in O(n).

For example Output[0] will be multiplication of A[1] to A[N-1] and Output[1] will be multiplication of A[0] and from A[2] to A[N-1].

Example:
A: {4, 3, 2, 1, 2}
OUTPUT: {12, 16, 24, 48, 24}
*/
void array_multiplication(int A[], int OUTPUT[], int n) {
 int left = 1;
  int right = 1;
  for (int i = 0; i < n; i++)
    OUTPUT[i] = 1;
  for (int i = 0; i < n; i++) {
    OUTPUT[i] *= left;
    OUTPUT[n - 1 - i] *= right;
    left *= A[i];
    right *= A[n - 1 - i];
  }
}
