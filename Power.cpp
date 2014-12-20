#include <iostream>
using namespace std;

// O(n) time
int pow(int a,int b)
{
    if(b == 0)  return 1;
    if(b%2)
        return a*pow(a,b/2)*pow(a,b/2);
    return pow(a,b/2)*pow(a,b/2);
}

// O(lgn) time
int pow_improved(int a,int b)
{
    if(b == 0)  return 1;
    int tmp = pow(a,b/2); //replace two recursive calls with single call
    if(b%2)
        return a*tmp*tmp;
    return tmp*tmp;
}
float fpow(int a,int b)
{
    if(b >= 0)  return pow(a,b);
    return (float)1/(float)pow(a,-b);
}
int main()
{
    int a = 2;
    for(int b = -10;b < 0;b++)
        cout<<"fpow( "<<a<<", "<<b<<") = "<<fpow(a,b)<<endl;
    for(int b = 0;b<=10;b++)
        cout<<"pow( "<<a<<", "<<b<<") = "<<pow(a,b)<<" , "<<pow_improved(a,b)<<endl;
    return 0;
}
