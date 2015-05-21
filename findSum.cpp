/*
Given an array and a target number. you have to print all sequences that generates the target number. 
you can use two arithmetic operators '+' and '-' to perform operations among array elements. 

Note: you can't modify the array and you have to use all the elments of the array. and the order would be same as given in the array. 

Example : 1 9 1 2 , Target Number = 9 

1 + 9 +1 -2 =9 

output should be "1 + 9 +1 -2 "
*/
#include    <iostream>
#include    <sstream>
using namespace std;

void sol(int a[],int index,int n,int c,int r,int s,int d,string result) {
    if(index == n && c == d)
        cout<<result<<endl;
    if(index >= n)  return;

    r = s - a[index];
    int tmp = c + -1*a[index];
    stringstream ss;
    if( r + tmp >= d ) {
        ss << (-a[index]);
        sol(a,index+1,n,tmp,r,s,d,result+" "+ss.str() );
    }
    ss.str("");
    tmp = c + a[index];
    if( tmp - r <= d ) {
        ss << (a[index]);
        sol(a,index+1,n,tmp,r,s,d,result+" "+ss.str() );
    }
}
int main()
{
    int a[] = {1,4,6};
    int s = 0, c = 0, r = 0;
    int n = sizeof(a)/sizeof(a[0]);
    string result;
    for(int i=0;i<n;i++)    s += a[i];
    sol(a,0,n,c,r,s,3,result);
}
~
