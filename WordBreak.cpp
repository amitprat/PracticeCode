#include    <iostream>
#include    <string.h>
using namespace std;

string dict[] = { "my","name","is","amit" };
bool iscontains(string pat)
{
    for(int i=0;i<sizeof(dict)/sizeof(dict[0]);i++)
        if(dict[i] == pat)
            return true;
    return false;        
}

bool wordbreak(string str,int s,bool wb[])
{
    
    for(int i=1;i<=s;i++)
    {
        if(iscontains(str.substr(0,i)))
            wb[i] = true;
        if(wb[i] == true) {
            for(int j=i+1;j<=s;j++)
            {
                if(iscontains(str.substr(i,j-i)))
                    wb[j] = true;
            }
        }
    }
    for(int i=1;i<=s;i++)
    {
        cout<<wb[i]<<" ";
    }
    cout<<endl;
    return wb[s];
}
bool wordbreakrecur(string str,bool wb[],int start)
{
    int s = str.size();
    if(s == start)  return true;
    for(int i=start+1;i<=s;i++) {
        if(iscontains(str.substr(start,i-start)) 
            && wordbreakrecur(str,wb,i)) {
            wb[i] = true;
            return true; 
        }
    }
    return false;
}
void printbreak(string str,bool wb[],int s)
{
    for(int i=0;i<s;i++) {
        cout<<str.at(i);
        if(wb[i+1])   cout<<" ";
    }
}
int main()
{
   string str="mynameisamit";
   int s = str.size();
   bool wb[s+1];
   memset(wb,0,s+1);
   cout<<wordbreakrecur(str,wb,0);
   printbreak(str,wb,s);
   return 0;
}
