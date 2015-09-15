/*
Input:  n = 100
Output: 1
100 can be written as 102. Note that 100 can also be 
written as 52 + 52 + 52 + 52, but this
representation requires 4 squares.

Input:  n = 6
Output: 3
*/

/*Recursive approach*/
int sol (int n) {
  if(n <= 1)  return n;
  
  int mn = INT_MAX;
  for(int i=1;i*i<=n;i++)
    mn = min(mn, 1+sol(n-i*i));
  
  return mn;
}

/*Dynamic Programming*/
int sol(int n) {
  int dp[n+1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  
  for(int i=4;i<=n;i++) {
    dp[i] = i;
    for(int j=1;j*j<=i;j++) {
      dp[i] = min(dp[i],1+sol(n-j*j));
    }
  }
  
  return dp[n];
}
