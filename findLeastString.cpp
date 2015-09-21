/*
Given a string which only contains lowercase. You need delete the repeated letters only leave one, and try to make the lexicographical order of new string is smallest. 
i.e: 
bcabc 
You need delete 1 'b' and 1 'c', so you delete the first 'b' and first 'c', the new string will be abc which is smallest. 

ps: If you try to use greedy algorithm to solve this problem, you must sure that you could pass this case: 
cbacdcbc. answer is acdb not adcb 

I can't solve this problem well and the interviewer said that you can scan the string twice. First scan is do some preprocess, and the second is to get the answer, but I really can't come up this idea.
*/

string smallest( char word[], int n ) {
  int map[26] = {0};
  for(int i=0;i<n;i++)  map[ word[i]-'a']++;
  string res;
  
  for(int i=0;i<n;i++) {
    if(map[word[i]] == 0) continue; //if letter already included
    int mnIndex = i;  //this is the element which need to be included
    int pos = findPos(map,i,n,mnIndex); //the index of element of which is first single from current position else return n-1
    //and minIndex is set to the element before pos which is least before 'pos'
    int tmp;
    if(word[pos] < word[mnIndex]) {
      res += word[pos];
      tmp = pos;
    } else {
      res += word[mnIndex];
      tmp = mnIndex;
    }
    
    map[ word[tmp] ] = 0;
    for(int j=i;j<tmp;j++)  map[ word[j] ]--;
    i = tmp;
  }
  
  return res;
}
