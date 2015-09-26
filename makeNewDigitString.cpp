/*
Ref : http://www.careercup.com/question?id=5165229530939392
Given 2 large number A and B, create a new number C using the digits from A which needs to be grater than B. 
e.g. A = 5281, B = 7443 
C = 8125.

Solution - 
I'd just sort the digits of A into descending order. Either that's greater than B or nothing will be. 


Modifying the question - Find Just greater number
*/

#include    <iostream>
#include    <unordered_map>
#include    <vector>
#include    <algorithm>
using namespace std;
typedef unordered_map<int,int> Map;
void fillRest(int &C,int table[],int l,int r) {
    while(l<=r) {
        for(int d=0;d<10;d++) {
            if(table[d]) {
                C = C*10 + d;
                table[d]--;
                break;
            }
        }
        l++;
    }
}
int main()
{
    int table[10] = {0};
    int A=5281,B=7443;
    int tmpA = A;
    int tmpB = B;
    vector<int> v;
    while(A) {
        table[A%10]++;
        A /= 10;
    }
    while(B) {
        v.push_back(B%10);
        B /= 10;
    }
    reverse(v.begin(),v.end());
    int C = 0;
    for(int i=0;i<v.size();i++) {
        int d = v[i];
        if(table[d])   {
            C = C*10 + d;
            table[d]--;
        } else {
            int j= 0;
            for(j=d+1;j<10;j++) {
                if(table[j]) {
                    C = C*10 + j;
                    table[j]--;
                    break;
                }
            }
            if(j==10)   {
                cout<<"-1"<<endl;
                return 0;
            }
            fillRest(C,table,i+1,v.size()-1);
            break;
        }
    }
    cout<<C<<endl;
    return 0;
}
