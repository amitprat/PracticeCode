//Tags - Infix to Postfix, Reverse Polish Notation, postfix converstion, convert infix to postfix
#include    <iostream>
#include    <stack>
#include    <string>
using namespace std;

bool isOperand(char s) {
    return (s>='a' && s<='z');
}
int priority(char ch) {
    char s[] = "+-*/^";
    for(int i=0;i<5;i++)
        if(s[i] == ch)
            return i;
}
string convert(string s)
{
    string res;
    stack<char> st;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            while(!st.empty() && st.top()!='(' ) {
                res += st.top(); st.pop();
            }
            st.pop();
        } else if(isOperand(s[i])) {
            res += s[i];
        } else {
            while(!st.empty() && priority(st.top()) <= priority(s[i])) {
                res +=s[i]; st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()) {
        res += st.top(); st.pop();
    }
    return res;
}
int main()
{
    string s[] = {"(a+(b*c))","((a+b)*(z+x))","((a+t)*((b+(a+c))^(c+d)))"};
    string op;
    for(int i=0;i<3;i++) {
        op= convert(s[i]);
        cout<<op<<endl;
    }
    return 0;
}
