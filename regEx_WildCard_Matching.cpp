#include    <iostream>
using namespace std;

bool wildCard(char *t,char *p)
{
    if(!*t && !*p)  return true;
    if(!*t && *p=='*' && *(p+1) != '\0')    return false;
    if(*p == *t || *p == '.')   return wildCard(t+1,p+1);
    if(*p == '*')
        return wildCard(t,p+1) || wildCard(t+1,p);
    return false;
}

bool regEx(char *t,char *p)
{
    if(!*p) return (*t=='\0');

    if(*(p+1) != '*')
        return (*p == *t || (*p=='.'&&*t!='\0')) && regEx(t+1,p+1);
    if(*p==*t || (*p=='.'&&*t!='\0'))
        return regEx(t,p+2) ||  regEx(t+1,p);
    return regEx(t,p+2);
}
int main()
{
    cout<<regEx("aa","a")<<endl;// → false
    cout<<regEx("aa","aa")<<endl;// → true
    cout<<regEx("aaa","aa")<<endl;// → false
    cout<<regEx("aa", "a*")<<endl;// → true
    cout<<regEx("aa", ".*")<<endl;// → true
    cout<<regEx("ab", ".*")<<endl;// → true
    cout<<regEx("aab", "c*a*b")<<endl;// → true
    return 0;
}
