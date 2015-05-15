/*
PLEASE NOTE: NlogN time complexity requirement. 

A non-empty zero-indexed array A of N integers is given. A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q]. 

A min abs slice is a slice whose absolute sum is minimal. 

For example, array A such that: 

A[0] = 2 
A[1] = -4 
A[2] = 6 
A[3] = -3 
A[4] = 9 

contains the following slice, among others: 

(0, 1), whose absolute sum = |2 + (−4)| = 2 
(0, 2), whose absolute sum = |2 + (−4) + 6| = 4 


Both slices (0, 3) and (1, 3) are min abs slices and their absolute sum equals 1. 

Write a function: 

class Solution { public int solution(int[] A); } 

that, given a non-empty zero-indexed array A consisting of N integers, returns the absolute sum of min abs slice. 

For example, given: 

A[0] = 2 
A[1] = -4 
A[2] = 6 
A[3] = -3 
A[4] = 9 

the function should return 1, as explained above. 

Assume that: 

N is an integer within the range [1..100,000]; 
each element of array A is an integer within the range [−10,000..10,000]. 

Complexity: 

expected worst-case time complexity is O(N*log(N)); 
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments). 

Elements of input arrays can be modified.
*/


(EDITED) 
Let S[u] = A0 + A1 + ... + Au, u = [0..N) 
Then we have the sum of slice (P,Q) is: S[Q] - S[P-1]. (except boundary cases when P = 0) 

Suppose slice (u,v) has minimum absolute sum. Then we have abs(S[v] - S[u]) must be minimum over all pairs of S. 

If S is sorted, between Su and Sv there's no other element, otherwise abs(Su-Sv) won't be minimum. 

Thus, after sorting S, we can just check two consecutive elements in the sorted S to find the min absolute sum. 

Pseudo code of O(n logn) algorithm: 
- Compute array S, where Su = sum of range A0, A1, ... Au 
- Sort S in O(n log n) 
- Compute minimum difference between 2 consecutive elements in S. This can be done in O(n). 

- Check for the boundary cases. Boundary cases when P = 0: sum of the slice (P,Q) is abs(S[Q]) itself. 

- Output the minimum difference as the answer. 

Code in C++:


#include <iostream>
#include <algorithm>

using namespace std;
const int Nmax = 100050;
int A[] = {20, -40, 60, 3, 90, 1};
int N = sizeof(A) / sizeof(int);

int S[Nmax];

int main()
{
    S[0] = A[0];
    for(int i=1; i<N; i++) S[i] = S[i-1] + A[i];

    sort(S, S+N);

    
    int minDifference = abs(S[0]);

    for(int i=1; i<N; i++){
        minDifference = min(minDifference, S[i]-S[i-1]);
        minDifference = min(minDifference, abs(S[i]));
    }

    cout <<minDifference<<endl;

    return 0;
}
