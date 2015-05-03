/*
Sum find problem - find all unique pairs,triplets,foursums with given sum
*/
#include <iostream>
#include <vector>
using namespace std;

/*auxiliary data structure*/
struct Node
{
    int x;
    int y;
    Node(int a=0, int b=0):x(a),y(b){};
};

/* taken from careercup */
vector< vector<int> > Print4Sum(vector<int> A){
    int tsum, l = A.size();
    vector< vector<int> > ans;
    if (l < 4) return ans;

    map<int, Node> hashmap;
    for (int i = 0; i < l-1; ++i)
    {
        for (int j = i+1; j < l; ++j)
        {
            tsum = A[i] + A[j];
            if (hashmap.find(tsum) == hashmap.end()){
                Node tnode = Node(i,j);
                hashmap[tsum] = tnode;
            }else{
                Node tnode = hashmap[tsum];
                int x = tnode.x, y = tnode.y;
                if (x != i && x != j && y != i && y != j)
                {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    tmp.push_back(x);
                    tmp.push_back(y);
                    ans.push_back(tmp);
                }
            }
        }
    }
    return ans;
}

vector< vector<int> > print3Sum(int a[],int n,int sum)
{
    vector< vector<int> > ans;
    if(n < 3)   return ans;
    unordered_map<int,int> table;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int tsum = sum - a[i] - a[j];
            if(table[tsum] == table.end()) {
                table[a[i]] = i;
                table[a[j]] = j;
            } else {
                int x = table[tsum];
                if(x != i && x != j) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    tmp.push_back(x);
                    ans.push_back(tmp);
                }
            }
        }
    }
    return ans;
}
/*print3Sum alternative approach using sorting - taken from leetcode */
set<vector<int> > find_triplets(vector<int> arr) {
  sort(arr.begin(), arr.end());
  set<vector<int> > triplets;
  vector<int> triplet(3);
  int n = arr.size();
  for (int i = 0;i < n; i++) {
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      int sum_two = arr[i] + arr[j];
      if (sum_two + arr[k] < 0) {
        j++;
      } else if (sum_two + arr[k] > 0) {
        k--;
      } else {
        triplet[0] = arr[i];
        triplet[1] = arr[j];
        triplet[2] = arr[k];
        triplets.insert(triplet);
        j++;
        k--;
      }
    }
  }
  return triplets;
}

/*print3Sum alternative approach using sorting - taken from leetcode */
vector<int> find_triplets(vector<int> arr,int sum) {
  sort(arr.begin(), arr.end());
  vector<int> triplet(3);
  int n = arr.size();
  int tmin = INT_MAX;
  
  for (int i = 0;i < n; i++) {
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
        int tsum = a[i] + a[j] + a[k];
        if( abs(sum-tsum) < tmin ) {
            tmin = abs(sum-tsum);
            triplet[0] = i; triplet[1] = j; triplet[2] = k;
        }
        if(tsum < sum)  j++;
        else if(sum > tsum) k--;
        else break;
    }
  }
  return triplet;
}

/*Another modification of above approach can be used to find the triplet
with minimum difference also. Just keep track of current minimum difference */

/*find all unique pairs with given sum */
//1)  using extra space - hashing
// T = O(n), S = O(n)
vector<Pair> pairSum(int a[],int n,int sum)
{
    unordered_map<int,int> table;
    vector < Pair > ans;
    if( n < 2 ) return ans;
    /*
    1) In-time insertion to hashtable to avoid duplicates like (2,3) ( 3,2) with same sum
    2) Store index to avoid cases like (1,2,5), sum = 10, ans (5,5)
    */
    for(int i=0;i<n;i++) {
        if( table.find(sum - a[i]) == table.end())
            table[a[i]] = i;
        else {
            int index = table[sum-a[i]];
            int (index != i) {
                ans.push_back(Pair(i,index));
            }
        }
    }
    return ans;
}

/*
Sorting :
    T = O(nlgn)
    S = O(lgn) //system stack space
*/

vector<Pair> pairSum(int a[],int n,int sum)
{
    sort(a,a+n);
    int i=0,j=n-1;
    while(i < j) {
        int tsum = a[i] + a[j];
        if(tsum == sum )    ans.push_back(Pair(i++,j--));
        else if (tsum < sum) i++;
        else j--;
    }
    return ans;
}

/*
Another nice approach taken from spaceofjameschan
based on hashing - just an alternative
*/

vector<Pair> pairSum(int a[],int n,int sum)
{
    unordered_map<int,int> table;
    vector<Pair> ans;
    for(int i=0;i<n;i++) {
        if(table.find(sum-a[i]) != table.end())
            table[sum-a[i]]++;
        else
            table[a[i]] = 0;
    }
    for( auto i : table )
        if( i.second ) {
            ans.push_back(Pair(i.first,sum - i.first));
        }
    }
    return ans;
}
