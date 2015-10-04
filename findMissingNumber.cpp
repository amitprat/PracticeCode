#include    <iostream>
#include    <string>
using namespace std;
int digits(int num) {
    int c=0;
    while(num) {
        c++;
        num /=10;
    }
    return c;
}
int find(string s) {
    int next;
    int missing;
    for(int i=1;i<=s.length();i++) {
        string s1=s.substr(0,i);
        int num = stoi(s1);
        next = num+1;
        int count=digits(next);
        string s2=s.substr(i,count);
        if(stoi(s2) == next) {
            s=s.substr(i+count);
            next = num+2;
            break;
        }
        next = num+2;
        count=digits(next);
        s2=s.substr(i,count);
        if(stoi(s2) == next)    {
            missing = num+1;
            return missing;
        }
    }
    int d;
    while(stoi(s.substr(0,(d=digits(next)))) == next) {
        next = next+1;
        s=s.substr(d);
    }
    return next;
}
int main()
{
    string s[] = {"1235678",
            "9979981000",
            "624625627"};
    for(int i=0;i<3;i++) {
        cout<<find(s[i])<<endl;
    }
    return 0;
}
