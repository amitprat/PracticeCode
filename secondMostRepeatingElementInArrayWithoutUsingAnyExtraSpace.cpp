#include    <iostream>
#include    <algorithm>
using namespace std;

/*
If extra space is allowed, it can be done in T = O(n) and S = O(n) time using hashtable method
for i : array
    table[ a[i] ]++;

for(auto i : table )
    update mostRepeating,secondMostRepeating

*/

/*
T = O(nlgn)
*/
void find(int a[],int n) {
    sort(a,a+n);
    int prev = a[0];
    int len = 0;
    int mostCount = 1, secondMostCount = 0;
    int mostRepeating,secondMostRepeating;
    for(int i=0;i<n;i++) {
        if(a[i] == prev)
            len++;
        else {
            if(len > mostCount) {
                secondMostCount = mostCount;
                mostCount = len;
                secondMostRepeating = mostRepeating;
                mostRepeating = prev;
            } else if(len > secondMostCount)
                secondMostCount = len, secondMostRepeating = prev;
            len = 1;
        }
        prev = a[i];
    }
    cout<<secondMostRepeating<<" : "<<secondMostCount<<endl;
    cout<<mostRepeating<<" : "<<mostCount<<endl;
}
/*
All numbers are in range[1-limit]
T = O(n)
Example Case : 5 5 5 2 2 1
*/
void find(int a[],int n,int limit) {
    int mostCount = 1, secondMostCount = 0;
    int mostRepeating,secondMostRepeating;
    int i=0;
    while(i<n) {
        if(a[i] <= 0)   i++;
        else {
            int pos = a[i]-1;
            if(a[pos] > 0) {
                swap(a[i],a[pos]);
                a[pos] = -1;
            } else if(a[pos] == 0) {
                a[pos] = -1;
                i++;
            }
            else {
                a[pos]--;
                a[i++] = 0;
            }
        }
    }
    for(int i=0;i<n;i++) {
        int len = -1*a[i];
        if(len > mostCount) {
                secondMostCount = mostCount;
                mostCount = len;
                secondMostRepeating = mostRepeating;
                mostRepeating = i+1;
            } else if(len > secondMostCount)
                secondMostCount = len, secondMostRepeating = i+1;
    }
    cout<<secondMostRepeating<<" : "<<secondMostCount<<endl;
    cout<<mostRepeating<<" : "<<mostCount<<endl;
}
int main()
{
    int a[] = {13,2,4,1,3,4,3,5,2,3,5,2,3,2,5,1,4,1,5,4,5,2,3,2,5,4,31,2,2,3,5};
    int n = sizeof(a)/sizeof(a[0]);
    find(a,n);
    find(a,n,100);
    return 0;
}
