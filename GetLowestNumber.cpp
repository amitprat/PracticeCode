#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

string trim(string str, int& n)
{
    if(n <= 0) return str;
    if(str.length() <= n) { n -= str.length(); return string(); }

    vector<pair<char,int>> tmp;
    for(int i=0;i<str.length(); i++) tmp.push_back({str[i], i});
    sort(tmp.begin(), tmp.end(), [](auto &f, auto &s){ return f.first < s.first;});
    sort(tmp.begin(), tmp.end()-n, [](auto &f, auto &s){ return f.second < s.second;});
    stringstream ss;
    for(int i=0;i<tmp.size()-n;i++) ss << tmp[i].first;
    n = 0;
    
    return ss.str();
}

int generateLowestNumber(string str, int n)
{
    string beforeZeros;
    string afterZeros;
    
    int pos = str.find('0');
    int start = 0;
    if(pos != string::npos) { beforeZeros = str.substr(start, pos); start = pos+1; }
    afterZeros = str.substr(start);
    
    beforeZeros = trim(beforeZeros, n);
    afterZeros = trim(afterZeros, n);
    
    // cout<<"before: "<<beforeZeros<<",after: "<<afterZeros<<endl;
    
    int mul = 10;
    int num = 0;
    for(auto ch : beforeZeros) { num = num * mul + (ch-'0'); }
    if(num !=0) { num = num * mul; }
    for(auto ch : afterZeros) { num = num * mul + (ch-'0'); }
    
    return num;
}

void insertIntoDQ(deque<int>& dq, char ch)
{
    while(!dq.empty() && dq.back() > ch) dq.pop_back();
    dq.push_back(ch);
}

string generateLowestNumberDQ(string str, int n)
{
    deque<int> dq;
    string res;
    int i = 0;
    for(i=0;i<n+1;i++) insertIntoDQ(dq, str[i]);
    
    for(;i<=str.length();i++)
    {
        res += dq.front(); dq.pop_front();
        
        if(i < str.length()) insertIntoDQ(dq, str[i]);
    }
    
    return res;
}

int main()
{
    vector< pair<string,int> > input = { {"",1}, {"12",1}, {"102",1}, {"102",2}, {"20",1}, {"201", 1}, {"1024",2}, {"4205123",4},{"216504",3} };
    for(auto i : input) {
        cout<<"Result for str : "<<i.first<<", n : "<<i.second<<" = "<<generateLowestNumber(i.first, i.second)<<endl;
    }
    
    for(auto i : input) {
        cout<<"Result for str : "<<i.first<<", n : "<<i.second<<" = "<<generateLowestNumberDQ(i.first, i.second)<<endl;
    }

    return 0;
}
