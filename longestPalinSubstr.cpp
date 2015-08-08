/*Longest Palindromic substring, palinsubstr, palinsubstring, palindromic substring, longest palin substring*/
#include "gprot.h"

string expand(string s,int l,int r)
{
    while( l >= 0 && r < s.length() && s[l] == s[r]) { l--; r++; }
    return s.substr(l+1,r-l-1);
}
string lps(string s)
{
    string str = "";
    for(int i=0;i<s.length()-1;i++)
    {
        string l = expand(s,i,i);
        str = l.length() > str.length() ? l : str;
        string r = expand(s,i,i+1);
        str = r.length() > str.length() ? r : str;
    }
    return str;
}
int lpsDP(string s) {
    int l = s.length();
    int max=1;
    int table[l][l];
    memset(table,0,l*l*sizeof(int));
    for(int i=0;i<l;i++)
        table[i][i] = 1;
    for(int cl=2;cl<l;cl++) {
        for(int i=0;i<l-cl+1;i++) {
            int j = i+cl-1;
            if(cl == 2) table[i][j] = ((s[i]==s[j])?2:0);
            else {
                if(s[i]==s[j])
                    table[i][j] = table[i+1][j-1] + 2;
            }
            if(table[i][j] > max)   max = table[i][j];
        }
    }
    return max;
}

int main()
{
    string s = "forgeekss";
    cout<<lpsDP(s)<<endl;
}
