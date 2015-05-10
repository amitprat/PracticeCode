/*
Write code to rotate a square matrix: 
Input: 
1 2 3 
4 5 6 
7 8 9 

Output: 
4 1 2 
7 5 3 
8 9 6
*/

#include    <iostream>

using namespace std;
const int N=3;

void cyclicRotate(int &a,int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void rotate(int a[][N])
{
    for(int layer=0;layer<N/2;layer++)
    {
        int j=layer;
        int tmp = a[layer][j];
        //top row
        int i = layer;
        for(j=layer+1;j<N-layer;j++) {
            cyclicRotate(a[i][j],tmp);
        }
        //right column
        j = N-layer-1;
        for(i=layer+1;i<N-layer;i++) {
            cyclicRotate(a[i][j],tmp);
        }
        //bottom row
        i=N-layer-1;
        for(j=N-layer-2;j>=0;j--) {
            cyclicRotate(a[i][j],tmp);
        }
        //left column
        j = layer;
        for(i=N-layer-2;i>=0;i--) {
            cyclicRotate(a[i][j],tmp);
        }
    }
}
int main()
{
    int a[][N] = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    rotate(a);

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
