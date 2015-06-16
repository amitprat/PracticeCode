/* 
        arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
*/
sort the interval by start time.
Select the jobs and schedule it on first platform if possile 
else add another patform and schedule it.

#include    <iostream>
#include    <vector>
#include    <algorithm>
using namespace std;
struct Interval
{
    float start, finish;
    Interval(float start,float finish):start(start),finish(finish){}
};
bool compare(Interval i1,Interval i2)
{
    return (i1.finish < i2.finish);
}
int schedule(Interval it[],int n)
{
  sort(it,it+n,compare);
  vector< vector<Interval> > v;
  v.push_back({it[0]});
  for(int i=1;i<n;i++)
  {
    int j = 0,sz=v.size();
    for(;j<v.size();j++)
    {
      if(it[i].start >= v[j][v[j].size()-1].finish)
      {
        v[j].push_back(it[i]);
        break;
      }
    }
    if(j == sz) {
        v.push_back( {it[i]} );
    }
  }
  for(int i=0;i<v.size();i++)
  {
    for(int j=0;j<v[i].size();j++)
      cout<<"("<<v[i][j].start<<","<<v[i][j].finish<<") ,";
    cout<<endl;
  }
  return v.size();
}
int main()
{
    Interval it[] = { {9,10},{10,12},{10,11},{11,12},{13,15},{14,16},{16,18} };
    cout<<"Intervals : "<<schedule(it,7)<<endl;
    return 0;
}
