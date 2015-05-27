In a matrix of characters, find an string. String can be in any way (all 8 neighbors to be considered), like find Microsoft in below matrix. 

A-C-P-R-C 

X-S-O-P-C 

V-O-V-N-I 

W-G-F-M-N 

Q-A-T-I-T 

String Microsoft is present in the matrix above ? 

There also a slight variation where a diagonal neighbor is not considered.

Do BFS from each element as 'M' in matrix;

for i to m
  for j to n
    if a[i][j] = 'M'
      bool visited[m][n]; 
      memset(visited,false,m*n*sizeof(bool));
      bool res = recur(a,string+1,visited) //this method itself is O(mn)
      
      
Complexity = O(m.n.m.n) = O(m2n2)
