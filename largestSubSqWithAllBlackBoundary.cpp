/* Cracking the coding interview
20.11 Imagine you have a square matrix, where each cell is filled with either black or white. Design an algorithm to find the maximum subsquare such that all four borders are filled with black pixels.
Assumption: Square is of size NxN.
This algorithm does the following:
1. Iterate through every (full) column from left to right.
2. At each (full) column (call this currentColumn), look at the subcolumns (from biggest to smallest).
3. At each subcolumn, see if you can form a square with the subcolumn as the left side. If so, update currentMaxSize and go to the next (full) column.
4. If N - currentColumn <= currentMaxSize, then break completely. We’ve found the largest square possible. Why? At each column, we’re trying to create a square with that column as the left side. The largest such square we could possibly create is N - currentColumn. Thus, if N-currentColumn <= currentMaxSize, then we have no need to proceed.
Time complexity: O(N^2).
*/
#include <iostream>
using namespace std;
#define N  4

struct subsq
{
    int r;
    int c;
    int sz;
    subsq(int r=0,int c=0,int sz=0):r(r),c(c),sz(sz) {}
};

bool isSq(bool arr[][N],int r,int c,int sz)
{
    for(int i=r;i<r+sz;i++) {
        if(!arr[i][c] || !arr[i][c+sz-1])
            return false;
    }
    for(int i=c;i<c+sz;i++) {
        if(!arr[r][i] || !arr[r+sz-1][i])
            return false;
    }
    return true;
}

subsq find(bool arr[][N])
{
    int maxSz = 0;
    int col = 0;
    subsq  sq;
    while(N-col > maxSz) {
        for(int row=0;row<N;row++) {
            int size = N-max(row,col);
            while(size > maxSz) {
                if(isSq(arr,row,col,size)) {
                    maxSz = size;
                    sq= subsq(row,col,size);
                    break;
                }
                size--;
            }
        }
        col++;
    }
    return sq;
}

int main()
{
    bool arr[][N] = {
                {1,1,1,1},
                {1,1,1,1},
                {0,1,1,1},
                {1,0,1,1}
                };
    subsq sq = find(arr);
    cout<<sq.sz<<endl;
    return 0;
}
