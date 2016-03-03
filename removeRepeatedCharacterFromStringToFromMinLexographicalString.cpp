/*
Number list compressing. 
Given an sorted array. Input: sorted number list 
1, 2, 3,10, 25, 26, 30, 31, 32, 33 

Output: find consecutive segments 
print: 1-3, 10, 25-26, 30-33
*/

//taken from careercup

/*
UPD: I could find a way to optimize my code to O(N). Main idea is the same. I added updated part after my old explanations 


Here's my O(N^2) idea which is absoloutly true:D ( proved, and tested with many random test cases) 

Let's say we have string S: 

I define next[i] = next position (after i) which is equal to S[i], if there is not, -1. 

So if S="bacdbcb", next={4,-1,5,-1,6,-1,-1} 

Now, I iterate through S, from left to right, and at each position, I decide whether to pick the current character or not. Also, there is an array called visited, which visited[i]=true means character i has been picked. 

Greedy part: 
If we are at position i, (let's say x=S[i]), we need to find the first j>i which next[j]=-1 and visited[j]=false, call it y=S[j]. Also I need to know what is the smallest character from i to j, call it z( and obviously visited[z]=false). If the smallest character in between, z, is bigger than x, then add x to answer and visited[x] = true, otherwise skip x and continue to i+1. 

Here's the reason: 
We have something like this. 
....x .... z ... y ... 
It means definietly y is the part of answer string (since its next is -1). So if there is nothing smaller than x between x and y (including y), for sure it's better to choose x to have a smaller lexicographic answer.(note that all the characters between x and y have another copy after y, since y is the first position which has no next, so it's safe to postpone picking them, if needed). On the other hand, if z<x for sure it's better to skip x and choose another x later on. 

Because at each position i, we need to see, in worst case, all next characters, so time complexity is O(N^2). 

I couldn't find a way to find y in O(logn) or O(1), if there is any suggestion please let me know. 

Also, I really really enjoyed the problem and it took me a day to come up with this solution!
*/

string removeRepeated(string s)
{
	int N=s.size();
	vector<int> next(N);
	int lastPos[26];
	for (int i=0;i<;26;i++)
		lastPos[i]=-1;

	for (int i=N-1;i>=0;i--){
		int ind = s[i]-'a';
		next[i] = lastPos[ind];
		lastPos[ind]=i;
	}
	
	vector<bool> visited(26,false);
	string ans;
	for (int i=0;i<N;i++){
		int cur = s[i]-'a';

		if (visited[cur]) continue;
		if (next[i]==-1){
			ans+=s[i];
			visited[cur]=true;
		}
		else{
			
			int j=i+1;
			char smaller=s[i];
			while(j<N){
				if (visited[s[j]-'a']==false){
					smaller = min (smaller , s[j]);
					if (next[j]==-1) break;
				}
				j++;
			}

			if (s[i]<=smaller){
				ans+=s[i];
				visited[cur]=true;
			}
		}
	}

	return ans;
}

/*
UPD: As I said it seemed it's possible to find y better than visiting all next characters.Using a stack I optimized the solution to O(26*N) = O(N) 

for each character, I add all of its positions in the string, into a stack.(from right to left of S) 
Also I keep the last position of each character in lastPos array. 

After processing a character from position i, I pop its position from its stack. So when I'm at position i, each element of all stacks are greater than i.(all positions before i are popped beforehand from their stacks). 


Now, I can find y and z much faster. 
position of y = min (lastPos[k]), which k is all characters which are not visited yet. 
Is there any z<x = if there is a character smaller than x which top of its stack is less than position of y. 

So time complexity is 26*N or O(N). 

Here's the code:
*/

string removeRepeatedLinear(string s)
{
	int N=s.size();
	stack<int> pos[26];//positions of each character
	int lastPos[26]={-1};

	for (int i=N-1;i>=0;i--){
		int cur= s[i]-'a';
		if (pos[cur].empty())
			lastPos[cur]=i;

		pos[cur].push(i);
	}


	vector<bool> visited(26,false);
	string ans;
	for (int i=0;i<N;i++){
		int cur = s[i]-'a';

		if (visited[cur]) continue;
		if (pos[cur].size()==1){ //last character of cur
			ans+=s[i];
			visited[cur]=true;
		}
		else{
			bool isSmaller=false;
			int minpos=N;
			for (int k=0;k<;26;k++){
				if (!visited[k] && !pos[k].empty())
					minpos=min(minpos,lastPos[k]);
			}

			for (int k=0;k<cur && !isSmaller;k++){
				if (visited[k] || pos[k].empty()) continue;
				if (pos[k].top()<=minpos)
					isSmaller=true;
			}

			if (isSmaller==false){
				ans+=s[i];
				visited[cur]=true;
			}
		}

		pos[cur].pop();
	}

	return ans;
}
