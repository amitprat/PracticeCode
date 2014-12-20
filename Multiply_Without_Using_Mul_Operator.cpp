#include <iostream>
using namespace std;

int mul(int a,int b)
{
    if(b < 0 ) return -(mul(a,-b));
    if(b == 0)  return 0;
    return a+mul(a,b-1);
}

int main()
{
    int a = 2;
    for(int b = 0;b<=10;b++)
        cout<<a <<" * "<<b<<" = "<<mul(a,b)<<endl;
    return 0;
}
