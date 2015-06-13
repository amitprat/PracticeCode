// Example program
#include <iostream>
#include <climits>
using namespace std;
int a[4][5] = { {1, 2, 3, 4, 5},
                    {3, 4, 5, 8, 10},
                    {3, 5, 7, 9, 11},
                    {1, 3, 5, 7, 9},
                  };

void print()
{
    int pos[4] = {0,0,0,0};
    
    while(1)
    {
        int m1 = 0,m2 = 0;
        for(int j=1;j<4;j++)
        {
            if(a[j][pos[j]] < a[m1][pos[m1]])
                m1 = j;
            
            if(a[j][pos[j]] > a[m2][pos[m2]])
                m2 = j;
        }
        if(a[m1][pos[m1]] == a[m2][pos[m2]]){
            cout<<a[m1][pos[m1]]<<" ";
            for(int j=0;j<4;j++)    pos[j]++;
        } else {
            pos[m1]++;
        }
        if(pos[m1] == 5) {
                cout<<"No More..\n";
                break;
            }
    }
}
int main()
{
  print();
}
