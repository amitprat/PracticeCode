#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

vector<int> getMinSeq(vector<int> input, int sum)
{
    int l = 0, r = 0, cur = 0;
    int mnSize = 99999;
    int mnSum = 99999;
    vector<int> res;
    int sz = input.size();
    
    while(r < sz || (cur > sum && l < sz)) {
        if(cur <= sum) cur += input[r++];
        if(cur > sum && (r -l < mnSize || cur < mnSum)) { res = vector<int>(input.begin() + l, input.begin() + r); mnSize = r - l; mnSum = cur; }
        if(cur > sum && l < sz) cur -= input[l++];
    }
    
    return res;
}

string toString(vector<int> v)
{
    stringstream ss;
    ss << "{";
    for(auto i : v) ss << i <<", ";
    ss << "}";
    return ss.str();
}

int main()
{
    vector< pair<vector<int>,int> > input = { {{2,1,1,4,3,6},18} };
    for(auto i : input) {
        cout<<"Result for input : "<<toString(i.first)<<" = "<<toString(getMinSeq(i.first, i.second))<<endl;
    }

    return 0;
}
