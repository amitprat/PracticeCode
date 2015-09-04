/*
Largest subarray with equal number of 0s and 1s
Given an array containing only 0s and 1s, find the largest subarray which contain equal no of 0s and 1s. Expected time complexity is O(n).
*/

/*
Approach - 
It similar to find the 0 sum subarray in the array.
And the logic for that is to find the sum again repeating.
If we see the old sum again, then certainly we have zero sum
subarray inbetween them.
*/


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int findSubArray(int a[],int n) {
    unordered_map<int,int> m;
    int maxLen = 0;
    m[0] = 0;
    int sum = 0;
    int s,e;
    for(int i=0;i<n;i++) {
        sum += a[i]?a[i]:-1;
        if(m.find(sum) != m.end()) {
            maxLen = max(maxLen, i-m[sum]);
            s = m[sum];
            e = i;
        } else 
            m[sum] = i+1;
    }
    cout<<s-1<<"->"<<e-1<<endl;
    return maxLen;
}
/* Driver program to test above functions */
int main()
{
    int arr[] =  {1, 0, 0, 1, 0, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<findSubArray(arr, size)<<endl;
    return 0;
}
