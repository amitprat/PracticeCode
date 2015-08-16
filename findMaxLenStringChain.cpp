/*You are given a library of n words. You have to select any one word and remove a character from it such that it becomes one of the words remaining in the inventory. What is the length of the longest possible chain of these removed steps? 
The selected word is discarded and not added to the library
*/

By chain, do you mean the following statement: 
If we remove a character from string S1 and it becomes S2, next time do we have to only remove a character from S2 and making another word in the inventory ? 

If so, here's my dynamic programming approach: 

- Sort words by their size (from smallest to longest). 
- then, define dp[i] = The longest chain that can be formed from word[0] up to word[i] and ends at word[i]. 
- now, dp[i] = max( dp[j]+1) from all j from 0 to i, provided that by removing one character from word[i] we can have word[j].(we can use a hash map for checking this condition) 
- final answer is max(dp[i]) 0<=i<N. 
- The order is O(N*L*L), which N is the number of words and L is the maximum length of words.


#include <bits/stdc++.h>

using namespace std;

const int maxn=10000;

unordered_map< string,int > hashTable;
int dp[maxn];

int LongestChain(vector<string> V)
{

	vector< pair<int,string> > list;
	for (auto s:V){
		list.push_back({s.size(),s});
	}
	sort(list.begin(),list.end());
	
	int N=list.size();
	hashTable.insert( {list[0].second,0} );
	dp[0]=1;

	int answer=dp[0];

	for (int i=1;i<N;i++){
		dp[i]=1;
		string s=list[i].second;
		
		int size = s.size();
		for (int j=0;j<size;j++){
			
			string tmpStr = s;
			tmpStr.erase(tmpStr.begin()+j);
			auto it = hashTable.find(tmpStr);

			if (it!=hashTable.end())
				dp[i] = max (dp[i],dp[it->second]+1);
		}
		answer = max ( answer , dp[i]);

		hashTable.insert({s,i});

	}

	return answer;
}



int main()
{

	int N;
	cin >> N;
	vector<string> V(N);
	for (int i=0;i<N;i++)
		cin >> V[i];

	cout << LongestChain(V) << endl;


	return 0;
}



Record < string,string_len> for each word;
Sort the container according to string_len in non-decreasing order.
starting from beginning, search for longest increasing subarray and keep track or maximum length subarray.
return maxlen subarray.
