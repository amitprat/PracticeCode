/* 2D range sum, range sum in matrix, find sum between two ranges in a matrix in O(1) time*/
#include    <iostream>
#include    <string.h>
#include    <iomanip>
using namespace std;
#define N 4

int rangeSum(int table[][N],int x1,int y1,int x2,int y2) {
    if(x1==0 && y1 == 0)    return table[x2][y2];
    else if(x1 == 0) return table[x2][y2] - table[x2][y1-1];
    else if(y1 == 0) return table[x2][y2] - table[x1-1][y2];
    else {
        int cd = table[x2][y1-1] - table[x1][y1-1];
        int rd = table[x1-1][y2] - table[x1-1][y1];
        int org = table[x1-1][y1] + table[x1][y1-1] - table[x1-1][y1-1];
        return table[x2][y2] -cd -rd -org;
    }
}
int main()
{
    int a[N][N] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,1,0,2},
        {3,4,1,5}
    };

    int table[N][N];
    table[0][0] = a[0][0];
    for(int i=1;i<N;i++)    table[i][0] = a[i][0] + table[i-1][0];
    for(int j=1;j<N;j++)    table[0][j] = a[0][j] + table[0][j-1];
    for(int i=1;i<N;i++) {
        for(int j=1;j<N;j++) {
            table[i][j] = a[i][j] + table[i][j-1] + table[i-1][j] - table[i-1][j-1];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout<<setw(2)<<table[i][j]<<" ";
        cout<<endl;
    }
    int x1=1,y1=1,x2=2,y2=2;
    cout<< rangeSum(table,x1,y1,x2,y2) <<endl;
    return 0;
}
