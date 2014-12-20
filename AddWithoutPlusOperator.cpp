#include <iostream>
using namespace std;

int sum(int a,int b)
{
    while(b)
    {
        int tmp = (a&b)<<1;
        a = a^b;
        b = tmp;
    }
    return a;
}

int main()
{
    for(int i=0;i<10;i++) {
        cout<<i<<" + "<<(i+1)<<" = "<<sum(i,i+1)<<endl;
    }
    return 0;
}
