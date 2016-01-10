/*
* Number of ways to make change of given amount/sum.
* Num Ways To Make Change
* count Ways To Make Change
* Minimum number of coins required to make change
* Min coins req to make change
* coin change problem
*/
#include    <iostream>
#include    <string.h>
#include    <climits>
#include    <vector>
using namespace std;

/*minimum coin change*/
int recSol(int dp[],int sum, int n) {
    if(sum < 0) return INT_MAX;
    if(sum == 0)    return 0;
    int mn = INT_MAX;
    for(int i=0;i<n;i++) {
        int tmp = recSol(dp,sum-dp[i],n);
        if(tmp != INT_MAX && tmp+1 < mn)
            mn = tmp+1;
    }
    return mn;
}
int dpSol(int dp[],int sum,int n)
{
    int table[sum+1];
    memset(table,0,sizeof(table));
    table[0] = 1;
    for(int i=0;i<n;i++)
    {
        int res = 0;
        for(int j=1;j<=sum;j++)
        {
            if(j >= dp[i])
                table[j] +=table[ j - dp[i] ];
        }
    }
    return table[sum];
}

/*number of ways- coin change*/
int recSolWays(int dp[],int sum, int n,int index) {
    if(sum == 0)    return 1;
    if(sum < 0 || index >= n)     return 0;
    int ways = 0;
    for(int i=index;i<n;i++) {
        ways += recSolWays(dp,sum-dp[i],n,i);   //only consider including current element or after it to avoid repeat count
    }
    return ways;
}
int recSolWays2(int dp[],int sum,int n,vector<int> &v,int k)
{
    if(sum == 0) {
        for(int i=0;i<k;i++)
            cout<<v[i]<<" ";
        cout<<endl;
        return 1;
    }
    if(n == 0 || sum < 0)
        return 0;
    int exclude =  recSolWays2(dp,sum,n-1,v,k);
    v[k] = dp[n-1];
    int include = recSolWays2(dp,sum-dp[n-1],n,v,k+1);
    return exclude+include;
}
int findMinDp(int dp[],int sum,int n)
{
    int table[sum+1];
    table[0] = 0;
    for(int i=1;i<=sum;i++)
    {
        int mn = 999;
        for(int j=0;j<n;j++)
        {
            if(dp[j] <= i)
                mn = 1 + min(mn,table[ i - dp[j] ] );
        }
        table[i] = mn;
    }
    return table[sum];
}
int main() {
    int dp[] = {1,2,5,10};
    int sum = 6;
    vector<int> v(10,0);

    cout<< "Number of ways to make sum(DP) : " <<dpSol(dp,sum,4)<<endl;
    cout<< "Minimum number of coins req to make change(DP) : "<<findMinDp(dp,sum,4)<<endl;
    cout<<endl;
    cout<< "Number of ways to make sum(Rec) : " <<recSolWays(dp,sum,4,0)<<endl;
    cout<< "Number of ways to make sum(Rec2) :"<< recSolWays2(dp,sum,4,v,0)<<endl;
    cout<< "Minimum number of coins req to make change(Rec) : "<<recSol(dp,sum,4)<<endl;
    return 0;
}
