/*
Taken from Careercup - 
There are n persons and k different type of dishes. Each person has some preference for each dish. Either he likes it or not. We need to feed all people. Every person should get atleast one dish of his chioce. What is the minimum number of different type of dishes we can order? 

Input is n x k matrix boolean matrix.For each person a row represent his likes or not likes each row. 

n = 6 k = 7 
1 0 0 0 1 0 0 
1 0 0 0 0 1 0 
1 0 0 0 0 0 1 
0 1 0 0 1 0 0 
0 0 1 0 0 1 0 
0 0 0 1 0 0 1 

Taken from geeksforgeeks - 
Set Cover Problem | Set 1 (Greedy Approximate Algorithm)
Given a universe U of n elements, a collection of subsets of U say S = {S1, S2…,Sm} where every subset Si has an associated cost. Find a minimum cost subcollection of S that covers all elements of U.

Example:

   U = {1,2,3,4,5}
   S = {S1,S2,S3}
   
   S1 = {4,1,3},    Cost(S1) = 5
   S2 = {2,5},      Cost(S2) = 10
   S3 = {1,4,3,2},  Cost(S3) = 3

Output: Minimum cost of set cover is 13 and 
        set cover is {S2, S3}

There are two possible set covers {S1, S2} with cost 15
and {S2, S3} with cost 13.
Why is it useful?
It was one of Karp’s NP-complete problems, shown to be so in 1972. Other applications: edge covering, vertex cover
Interesting example: IBM finds computer viruses (wikipedia)
Elements- 5000 known viruses
Sets- 9000 substrings of 20 or more consecutive bytes from viruses, not found in ‘good’ code.
A set cover of 180 was found. It suffices to search for these 180 substrings to verify the existence of known computer viruses.

Another example: Consider General Motors needs to buy a certain amount of varied supplies and there are suppliers that offer various deals for different combinations of materials (Supplier A: 2 tons of steel + 500 tiles for $x; Supplier B: 1 ton of steel + 2000 tiles for $y; etc.). You could use set covering to find the best way to get all the materials while minimizing cost
Source: http://math.mit.edu/~goemans/18434S06/setcover-tamara.pdf

Set Cover is NP-Hard:
There is no polynomial time solution available for this problem as the problem is a known NP-Hard problem. There is a polynomial time Greedy approximate algorithm, the greedy algorithm provides a Logn approximate algorithm.

2-Approximate Greedy Algorithm:
Let U be the universe of elements, {S1, S2, … Sm} be collection of subsets of U and Cost(S1), C(S2), … Cost(Sm) be costs of subsets.

1) Let I represents set of elements included so far.  Initialize I = {}

2) Do following while I is not same as U.
    a) Find the set Si in {S1, S2, ... Sm} whose cost effectiveness is 
       smallest, i.e., the ratio of cost C(Si) and number of newly added 
       elements is minimum. 
       Basically we pick the set for which following value is minimum.
           Cost(Si) / |Si - I|
    b) Add elements of above picked Si to I, i.e.,  I = I U Si
Example: 
Let us consider the above example to understand Greedy Algorithm.

First Iteration:
I = {}

The per new element cost for S1 = Cost(S1)/|S1 – I| = 5/3

The per new element cost for S2 = Cost(S2)/|S2 – I| = 10/2

The per new element cost for S3 = Cost(S3)/|S3 – I| = 3/4

Since S3 has minimum value S3 is added, I becomes {1,4,3,2}.

Second Iteration:
I = {1,4,3,2}

The per new element cost for S1 = Cost(S1)/|S1 – I| = 5/0
Note that S1 doesn’t add any new element to I.

The per new element cost for S2 = Cost(S2)/|S2 – I| = 10/1
Note that S2 adds only 5 to I.

The greedy algorithm provides the optimal solution for above example, but it may not provide optimal solution all the time. Consider the following example.

S1 = {1, 2}
S2 = {2, 3, 4, 5}
S3 = {6, 7, 8, 9, 10, 11, 12, 13}
S4 = {1, 3, 5, 7, 9, 11, 13}
S5 = {2, 4, 6, 8, 10, 12, 13}

Let the cost of every set be same.

The greedy algorithm produces result as {S3, S2, S1}

The optimal solution is {S4, S5} 
Proof that the above greedy algorithm is Logn approximate. - refer to geeksforgeeks or wiki
*/

/*Exponential time algo to first question*/
typedef unordered_set<int> set;
vector< set > vs;
for(int i=0;i<rows;i++) {
  set tmp;
  for(int j=0;j<cols;j++) {
    tmp.insert(a[i][j]);
  }
  vs.push_back(tmp);
}

void findMin(vector<set> vs, int index,int n,int cnt, int &minCnt) {
  if(index == n)  {
    minCnt = min(minCnt,cnt);
    return;
  }
  
  for(auto i : vs[index]) {
    int k = index+1;
    while(k<n &&  vs[k].find(i))
      k++;
    findMin(vs,k,n,cnt+1,minCnt);
  }
}



Greedy Approach - 

int find( vector<set> vs ) {
  set tmp;
  int j = 0;
  int n = vs.size();
  /*this loop will be O(n2) if each set contains every distinct element from other
  in that Universal set ( tmp ) will end up having total of all elements and hence
  O(n2) is required complexity. 
  However, the step to find set intersection might be optimized - TODO 
  */
  while(j < n) {
    for(int i=0;i<n;i++) {
      set tmp1 = vs[i];
      int cnt = 0;
      int maxCnt = 0;
      int maxIdx = 0;
      for(auto elem : tmp1 ) {
        if(tmp.find(elem) == tmp.end() )
          cnt++;
      }
      if(cnt > maxCnt){  maxCnt = cnt; maxIdx = i; }
    }
    if(maxCnt == 0) break;
    swap( vs[j++], vs[i] );
  }
}
