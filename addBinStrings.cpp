/*
Sum of two binary strings (Add Binary)

Given two binary strings, return their sum (also a binary string).
INPUT: a = “11”, b = “1”
OUTPUT: “100”
*/
#include <iostream>
using namespace std;

#define TOINT(x) ( x-'0' )
#define TOCHAR(x) (x+'0')

void makeSameLen(string &s1,string &s2,int l1,int l2)
{
    if(l1 > l2) {
        s2 = string(l1-l2,'0') + s2;
    } else {
        s1 = string(l2-l1,'0') + s1;
    }
}
string add(string s1,string s2,int l)
{
    char result[l+2];
    result[l+1] = '\0';
    int carry = 0;
    int k = l;
    for(int i=l-1;i>=0;i--) {
        int data = TOINT(s1[i]) +TOINT(s2[i]) + carry;
        switch(data)
        {
        case 0:
            result[k--] = TOCHAR(0);
            carry = 0;
            break;
        case 1:
            result[k--] = TOCHAR(1);
            carry = 0;
            break;
        case 2:
            result[k--] = '0';
            carry = 1;
            break;
        case 3:
            result[k--] = '1';
            carry = 1;
            break;
        }
    }
    if(carry)   result[k--] = TOCHAR(1);
    return string(result+k+1);
}
string addBin(string s1,string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    if( l1 != l2 )
        makeSameLen(s1,s2,l1,l2);
    int carry = 0;
    return add(s1,s2,max(l1,l2));
}
int main()
{
    string s1="11111";
    string s2="011";
    cout << addBin(s1,s2) <<endl;
    return 0;
}
