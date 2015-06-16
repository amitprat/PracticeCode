
// C++ program to find Index of 0 to be replaced with 1 to get
// longest continuous sequence of 1s in a binary array
#include<iostream>
using namespace std;

// Returns index of 0 to be replaced with 1 to get longest
// continuous sequence of 1s.  If there is no 0 in array, then
// it returns -1.
int maxOnesIndex(bool arr[], int n)
{
    int max_count = 0;  // for maximum number of 1 around a zero
    int max_index;  // for storing result
    int prev_zero = -1;  // index of previous zero
    int prev_prev_zero = -1; // index of previous to previous zero

    // Traverse the input array
    for (int curr=0; curr<n; ++curr)
    {
        // If current element is 0, then calculate the difference
        // between curr and prev_prev_zero
        if (arr[curr] == 0)
        {
            // Update result if count of 1s around prev_zero is more
            cout<<prev_prev_zero<<" "<<prev_zero<<" "<<curr<<" "<<curr - prev_prev_zero -1<<endl;
            if (curr - prev_prev_zero-1 > max_count)
            {
                max_count = curr - prev_prev_zero -1;
                max_index = prev_zero;
            }

            // Update for next iteration
            prev_prev_zero = prev_zero;
            prev_zero = curr;
        }
    }

    // Check for the last encountered zero
    if(arr[n-1] == 1 && n-prev_prev_zero > max_count) {
       cout<<prev_prev_zero<<" "<<prev_zero<<" "<<n-1-prev_prev_zero<<endl;
       max_count = (n-1)-prev_prev_zero;
       max_index = prev_zero;
    }
    else if(arr[n-1] == 0 && n-prev_prev_zero-1>max_count) {
        cout<<prev_prev_zero<<" "<<prev_zero<<" "<<n-1-prev_prev_zero-1<<endl;
        max_count = (n-1)-prev_prev_zero -1;
        max_index = prev_zero;
    }
    cout<<max_index<<" "<<max_count<<endl;
    return max_index;
}

// Driver program
int main()
{
    bool arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of 0 to be replaced is "
         << maxOnesIndex(arr, n);
    return 0;
}
