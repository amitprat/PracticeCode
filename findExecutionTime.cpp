/*
Given an array of task and k wait time for which a repeated task needs to wait k time to execute again. return overall unit time it will take to complete all the task. 
Example: 
1. A B C D and k = 3 
ans: 4 (execute order A B C D) 
2. A B A D and k = 3 
ans: 6 (execute order A B . . A D) 
3. A A A A and k =3 
ans: 13 (A . . . A . . . A . . . A) 
4. A B C A C B D A and k = 4 
ans: 11 (A B C . . A .C B D A )
*/

template <typename T> 
int find( T a[], int n ) {
  unordered_map<T,int> m;
  int time = 0;
  for(int i=0;i<n;i++) {
    if(m.find(a[i] != m.end()) {
      int d = i - m[a[i] -1;
      time += d;
    }
    m [ a[i] ] = i;
    time += 1;
  }
  
  return time;
}
