/*
Maximum length subarray with given sum
*/

int maxlen(int a[],int n,int x) {
  int sum = 0;
  int start = 0;
  int maxlen = 0;
  for(int i=start;i<=n;i++) {
    while(sum > x && start < i) {
      sum -= a[start++];
    }
    if(sum == x) {
      cout<<"Found subarray with given sum between"<<start<<","<<i<<endl;
      maxlen = max(maxlen, i-start+1);
    }
    sum += a[i];
  }
  return maxlen;
}
