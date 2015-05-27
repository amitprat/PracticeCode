/*
Given n rows of integers, such that the ith row (1 <= i <= n) contains i integers, find the path having the maximum weight. 
Path traversal rules: 
1. A valid path sequence would be top-down i.e. begins with the integer in the first row, and traverses all rows selecting only one integer in each row.
2. From any jth integer in the ith row i.e row[i][j], traversal can happen either downward (i.e to row[i+1][j]) or diagonally downward to the right (i.e to row[i+1][j+1]) 
The weight of a Path is the sum of values of integers in the Path sequence. 
Sample Input: 
No. of Rows: 5 
4 
2 9 
15 1 3 
16 92 41 44 
8 142 6 4 8 

Expected Output: 4, 2, 15, 92, 142 (Max weight is 255)
*/

void sol(int a[][5],int m,int n)
{
    char dir[m][n];

    int op[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            op[i][j] = INT_MIN;

    op[0][0] = a[0][0];
    dir[0][0] = 'O';
    int max = INT_MIN;
    pair<int,int> maxIndex;
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(op[i][j] < op[i-1][j]+a[i][j]) {
                op[i][j] = op[i-1][j]+a[i][j];
                dir[i][j] = 'U';
            }
            if(j > 0 && op[i][j] < op[i-1][j-1]+a[i][j]) {
                op[i][j] = op[i-1][j-1]+a[i][j];
                dir[i][j] = 'D';
            }
            if(op[i][j] > max) {
                max = op[i][j];
                maxIndex = make_pair(i,j);
            }
        }
    }
    cout<<max<<endl;
    for(int i=0;i<5;i++) {
        for(int j=0;j<=i;j++)
            cout<<dir[i][j]<<" ";
        cout<<endl;
    }
    for(int i=maxIndex.first;i>=0;)
    {
        for(int j=maxIndex.second;j>=0;)
        {
            cout<<a[i][j]<<" ";
            if(dir[i][j] == 'U')  i--;
            else if(dir[i][j] == 'D')  j--,i--;
            else return;
        }
    }
}

int main()
{
    int a[5][5] = { {4},
            {2, 9 },
            {15, 1, 3},
            {16, 92, 41, 44},
            {8, 142, 6, 4, 8}
    };
    sol(a,5,5);
    return 0;
}
  
