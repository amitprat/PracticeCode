#include <iostream>
using namespace std;

int mul(int a,int b)
{
    if(b < 0 ) return -(mul(a,-b));
    if(b == 0)  return 0;
    return a+mul(a,b-1);
}

int pow(int a,int b)
{
    if(b == 0) return 1;
    int tmp = pow(a,b/2);
    if(b&1) return mul(a,mul(tmp,tmp));
    return mul(tmp,tmp);
}
int main()
{
    int a = 2;
    for(int b = 0;b<=10;b++)
        cout<<a <<" * "<<b<<" = "<<pow(a,b)<<endl;
    return 0;
}

