/*
Find missing number in an array with continuous number
Problem
An array A[1... n] contains all the integers from 0 to n except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation.
The elements of A are represented in binary, and the only operation we can use to access them is “fetch the jth bit of A[i]”, which takes constant time. Write code to find the missing integer. Can you do it in O(n) time?
*/
// Example program
#include <iostream>
#include <string>
using namespace std;
int findNum( int a[], int n ) {
    int num = 0;
    for(int i = 0;i<n;i++) {
        for(int j=0;j<32;j++) {
            num ^= a[i]&(1<<j);
        }
    }
    return num;
}
int main()
{
    int a[] = {1,2,3,4,5,7};
    int  n = sizeof(a)/sizeof(a[0]);
    
    cout << findNum(a,n) <<endl;
    return 0;
}
