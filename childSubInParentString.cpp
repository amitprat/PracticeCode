/*
Two strings i.e. one parent and one child string, you have to find how many child subsequences can occur in the parent string, there can be different combinations if a character repeats itself. For ex:
Parent[]= ABABDCAD
Child[]= AD
Then your answer should be 5.
I applied modification of LCS here and coded it.

ToDo????
*/


int find(string parent, string child ) {
  int n = parent.length();
  int m = child.length();
  
  int table[n+1][m+1];
  
  for(int i=0;i<=n;i+) {
    for(int j=0;j<=m;j++) {
      if(i == 0 || j ==0) {
        table[i][j] = 0;
      } else {
        table[i][j] = table[i][j-1];
        if(parent[i-1] == child[j-1])
          table[i][j] = table[i-1][j] + table[
      }
    }
  }
}
