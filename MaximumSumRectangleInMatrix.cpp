#include<bits/stdc++.h> 
using namespace std; 

#define ROW 4
#define COL 5 

int kadane(int* arr, int &start, int &finish, int n) 
{ 
    int mx = INT_MIN;
    int curMax = 0;
    int s = 0;
    for(int i=0;i<n;i++) {
        curMax += arr[i];
        if(curMax > mx) {
            start = s;
            finish = i;
            mx = curMax;
        }
        if (curMax < 0) {
           s = i+1;
           curMax = 0;
        }
    }
    
    return mx;
} 

void findMaxSum(int M[][COL]) 
{
	int maxSum = INT_MIN, finalLeft, finalRight,finalTop, finalBottom; 

	int left, right, i; 
	int temp[ROW], sum, start, finish; 

	// Set the left column 
	for (left = 0; left < COL; ++left) 
	{
		memset(temp, 0, sizeof(temp));
		for (right = left; right < COL; ++right) 
		{
			for (i = 0; i < ROW; ++i) 
				temp[i] += M[i][right]; 

			sum = kadane(temp, start, finish, ROW); 
			if (sum > maxSum) 
			{ 
				maxSum = sum; 
				finalLeft = left; 
				finalRight = right; 
				finalTop = start; 
				finalBottom = finish; 
			} 
		} 
	} 

	cout<< "Max Sum Matrix:"<<endl;
	for(int i=finalLeft;i<=finalRight;i++) {
	    for(int j=finalTop;j<=finalBottom;j++) {
	        cout<<setw(4)<<M[i][j]<<" ";
	    }
	    cout<<endl;
	}
	cout << "Max sum is: " << maxSum << endl; 
} 

// Driver Code 
int main() 
{ 
	int M[ROW][COL] = {{1,   2, -1, -4, -20}, 
					   {-8, -3, 4, 2, 1}, 
					   {3,   8, 10, 1, 3}, 
					   {-4, -1, 1, 7, -6}}; 

	findMaxSum(M); 

	return 0; 
} 
