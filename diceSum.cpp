/*
given n > 0 fair dice with m > 0 "sides", write an function that returns a histogram of the frequency of the result of dice rolls. For example, for two dice, each with three sides, the results are: 

(1, 1) -> 2 
(1, 2) -> 3 
(1, 3) -> 4 
(2, 1) -> 3 
(2, 2) -> 4 
(2, 3) -> 5 
(3, 1) -> 4 
(3, 2) -> 5 
(3, 3) -> 6 

And the function should return: 

2: 1 
3: 2 
4: 3 
5: 2 
6: 1
*/

#include    <iostream>
#include    <unordered_map>
using namespace std;
typedef unordered_map<int,int> hashtable;

void print(int n,int m,hashtable &table,int index,int sum)
{
    if(index == n) {
        table[sum] = table[sum] + 1;
        return;
    }
    for(int i=1;i<=m;i++)
        print(n,m,table,index+1,sum+i);
}
int main()
{
    int n = 2;
    int m = 3;
    hashtable table;
    print(n,m,table,0,0);
    for(auto i:table)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}
