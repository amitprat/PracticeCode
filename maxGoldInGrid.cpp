/*
Find maximum gold in a grid
Given a grid of m*n size. Each block in grid has some amount of gold. 

We start from first column of the grid(any row) and we can move in 3 direction - right, right-up and right-down. 

What is the maximum amount of gold we can collect from the grid.
*/

/*
Dynamic programming O(mn) time.
a[i][j]=max{a[i-1][j-1],a[i][j-1],a[i+1][j-1]} +a[i][j] for j=0 to n-1
and a[i][j]=0 for i<0 or i>=m

Finally the max element in the last column is the solution.
*/
