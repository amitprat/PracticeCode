#include    <iostream>
#include    <vector>
using namespace std;

typedef vector< vector<int> > mat;

#define WAY2
/*using extra space, S = O(n), T = O(n2) */

void print(mat m) {
    for(int i=0;i<m.size();i++) {
        for(int j=0;j<m[0].size();j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
}
#ifdef WAY1
void nullify(mat &m)
{
    int r = m.size(), c = m[0].size();
    bool row[r];
    bool col[c];
    for(int i=0;i<c;i++)    col[i] = false;
    for(int i=0;i<r;i++) {
        row[i] = false;
        for(int j=0;j<c;j++) {
            if(!m[i][j])
                row[i] = col[j] = true;
        }
    }
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(row[i] || col[j])
                m[i][j] = 0;
        }
    }
}
#endif // WAY1

/*without using extra space*/
#ifdef WAY2
void nullifyRow(mat &m,int r)
{
    for(int i=0;i<m[0].size();i++)
        m[r][i] = 0;
}
void nullifyCol(mat &m,int c)
{
    for(int i=0;i<m.size();i++)
        m[i][c] = 0;
}
void nullify(mat &m)
{
    int r = m.size(), c = m[0].size();
    bool rowZero = false, colZero = false;
    for(int i=0;i<r;i++)    if(!m[0][i]) rowZero = true;
    for(int i=0;i<c;i++)    if(!m[i][0]) colZero = true;

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!m[i][j])
                m[0][j] = m[i][0] = 0;
        }
    }
    for(int i=0;i<r;i++)
        if(!m[i][0])
            nullifyRow(m,i);
    for(int j=0;j<c;j++)
        if(!m[0][j])
            nullifyCol(m,j);
    if(rowZero)
        nullifyRow(m,0);
    if(colZero)
        nullifyCol(m,0);
}
#endif // WAY2
int main()
{
    mat m = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,1,1,1}
    };
    nullify(m);
    print(m);
    return 0;
}
