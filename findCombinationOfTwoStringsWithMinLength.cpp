/*
Reference : http://www.careercup.com/question?id=5150387063488512
Two strings s1 and s2 are given. You have make a new string s3 such that it has both s1 and s2 as one of its subsequences and length of s3 is minimum. 
*/

/*
Let's intial value of answer to longest common subsequence(LCS) of s1 and s2 
ans = LCS(s1,s2) 

Now we have to add remaining characters of s1 and s2 into ans. This could be done greedily. 

Here's why and how: 
assume that LCS(s1,s2) = abc 

So s1 and s2 should be something like these: 
s1= (x1) a (x2) b (x3) c (x4) 
s2= (y1) a (y2) b (y3) c (y4) 

in which (xi) and (yi) could be any strings of any size(>=0) 

Obviously, all of the characters of (xi) and (yi) are different, because otherwise we could extend LCS and get a bigger one which is a contradiction to the definition of LCS. 

So now we could add all characters of xi and yi in any order to the answer. 
so the answer would be: 

ans = (x1)(y1) a (x2)(y2) b (x3)(y3) c (x4)(y4) 

and finding the LCS is a classic Dynamic Programming problem which could be solved in O(N*M). 

The length of S3 would be S1.size()+S2.size()-LCS.size(), which is the minimum size we could get, so this would be the best answer. 

So the final time complexity would be O(N*M) 
*/


//Mehrdad AP

// finding LCS (by DP) and add remainig character between lcs greedily.
//Time Complexity: O(N*M)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LCS(string s1,string s2)
{

	int N=s1.size(),M=s2.size();
	vector< vector<int> > dp(N),parent(N);
	for (int i=0;i<N;i++){
		dp[i].resize(M);
		parent[i].resize(M);
	}

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			int maxi=0,par=1;

			if (i!=0 && dp[i-1][j]>maxi){
				maxi = dp[i-1][j];
				par = 1;
			}
				 
			if (j!=0 && dp[i][j-1]>maxi){
				maxi = dp[i][j-1];
				par = 2;
			}


			if (s1[i]==s2[j]){
				if (i!=0 && j!=0 && dp[i-1][j-1]+1>maxi){
					maxi = dp[i-1][j-1]+1;
					par = 3;
				}
				if (1>maxi){
					maxi = 1;
					par=3;
				}
			}

			dp[i][j] = maxi;
			parent[i][j]=par;
		}
	}

	int i=N-1,j=M-1;
	string ans="";
	while (i>=0 && j>=0){
		int par =parent[i][j];
		if (par==3){
			ans+=s1[i];
			i--,j--;
		}
		else if (par==2)
			j--;
		else if (par==1)
			i--;

	}
	reverse(ans.begin(),ans.end());

	return ans;

}



string findingMix(string s1,string s2)
{

	string lcs=LCS(s1,s2);

	int i=0,j=0;
	string ans="";

	for (int k=0;k<lcs.size();k++){
		while (i<s1.size() && s1[i]!=lcs[k]){
			ans+=s1[i];
			i++;
		}

		while(j<s2.size() && s2[j]!=lcs[k]){
			ans+=s2[j];
			j++;
		}

		ans+=lcs[k];
		i++,j++;
	}

	//finishing s1 and s2 characters
	while (i<s1.size()){
			ans+=s1[i];
			i++;
		}

	while(j<s2.size()){
		ans+=s2[j];
		j++;
	}

	return ans;
}


int main()
{

	string s1,s2;

	while (cin >> s1 >> s2){
		cout << findingMix(s1,s2) << endl;
	}

	return 0;
}
