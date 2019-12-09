//g++  5.4.0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

int index(string str, int i)
{
    return str[i] - 'a';
}

bool match(int p[], int t[], int n)
{
    for(int i=0;i<n;i++) if(p[i] > t[i]) return false;
    return true;
}

string findMinConsequetiveStr(string t, string p)
{
    string res;
    int mn = 999;
    int patBitMap[32] = {0}, txtBitMap[32] = {0};
    int i = 0;
    int s = 0;
    for(;i<t.size() && i<p.size();i++) {
        patBitMap[index(p,i)]++;
        txtBitMap[index(t,i)]++;
    }
    if(match(patBitMap, txtBitMap, 32)) { res = p; mn = res.length(); }

    for(;s<t.size();s++) {
        if(i < t.size()) txtBitMap[index(t,i++)]++;
        
        if(match(patBitMap, txtBitMap, 32)) {
            string tmp = t.substr(s, i-s+1);
            if(tmp.length() < mn) {
                res = tmp;
                mn = res.length();
            }
            txtBitMap[index(t,s)]--;
        }
    }

    return res;
}

int main()
{
    vector< pair<string,string> > input = { {"adobecodebanc", "abc"} };
    for(auto i : input) {
        cout<<"Result for S: "<<i.first<<", T: "<<i.second<<" = "<<findMinConsequetiveStr(i.first, i.second)<<endl;
    }

    return 0;
}
