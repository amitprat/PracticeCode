#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval(int s,int e):start(s),end(e) {}
};
void insert(vector<Interval> &v,Interval it)
{
    vector<Interval>::iterator itr = v.begin();
    while(itr != v.end()) {
        int s = min(it.start,itr->start);
        int e = max(it.end, itr->end);
        if( it.start > itr->end)
            itr++;
        else if( it.end < itr->start) {
            v.insert(itr,it);
            break;
        }else {
            it = Interval(s,e);
            v.erase(itr);
        }
    }
    if( itr == v.end())
        v.push_back(it);
}
void print(vector<Interval> v)
{
    for(int i=0;i<v.size();i++) {
        cout<<"("<<v[i].start<<","<<v[i].end<<")"<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<Interval> v;
    v.push_back(Interval(1,2));
    v.push_back(Interval(3,5));
    v.push_back(Interval(6,7));
    v.push_back(Interval(8,10));
    v.push_back(Interval(12,16));
    Interval it(4,9);
    insert(v,it);
    print(v);
    return 0;
}
