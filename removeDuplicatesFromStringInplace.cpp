/*
Remove duplicates from a string inplace. The algorithm should be as efficient as possible. 
I gave two approaches. First, the simple comparison O(n2) and second, sorting O(nlgon). But the interviewer did not seem satisfied. 
Can someone please suggest a better algorithm?
*/
/*Solution - 
  void sol(char s[],int &n) {
    int start = 0;
    for(int i=0;i<n;i++) {
      if(!map[ s[i] ]) {
        s[start++] = s[i];
        map[ s[i] ] = true;
      }
    }
    s[start] = '\0';
    n = start;
  }
*/
