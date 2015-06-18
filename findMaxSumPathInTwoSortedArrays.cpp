/*
from : geeksforgeeks
Input:  ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
35 is sum of 1 + 5 + 7 + 10 + 12.
We start from first element of arr2 which is 1, then we
move to 5, then 7.  From 7, we switch to ar1 (7 is common)
and traverse 10 and 12.

Input:  ar1[] = {10, 12}, ar2 = {5, 7, 9}
Output: 22
22 is sum of 10 and 12.
Since there is no common element, we need to take all 
elements from the array with more sum.

Input:  ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
        ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122
122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34
*/
// Example program
#include <iostream>
#include <string>
#include    <vector>
using namespace std;
// Driver program to test above function


int maxPathSum(int a[],int b[],int n,int m)
{
    int sum1 = 0, sum2 = 0, sum = 0;
    int i =0,j=0;
    int pos = 0;
    vector<int> result;
    while(i < n && j< m )
    {
        if(a[i] < b[j]) {
            sum1 += a[i++];
        }
        else if(a[i] > b[j]) {
            sum2 += b[j++];
        }
        else {
            if(sum1 > sum2) {
                sum += sum1 + a[i];
                result.insert(result.end(),a+pos,a+i+1);
            } else {
                sum += sum2 + b[j];
                result.insert(result.end(),a+pos,a+i+1);
            }
            sum1 = sum2 = 0;
            pos = i+1;
            i++,j++;
        }
    }
    while(i < n) {
        sum1 += a[i++];
    }
    while(j < n) {
        sum2 += b[j++];
    }
    
  if(sum1 > sum2) {
    sum += sum1;
    result.insert(result.end(),a+pos,a+n);
  } else {
    sum += sum2;
    result.insert(result.end(),b+pos,b+m);
  }
  cout<<"resultant array :"<<endl;
  for(auto k : result)
    cout<<k<<"  ";
  cout<<endl;
  return sum;
}
int main()
{
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << maxPathSum(ar1, ar2, m, n);
    return 0;
}
