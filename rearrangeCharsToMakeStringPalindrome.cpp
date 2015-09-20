/*
Given an array of strings with only lowercase letters , create a function that returns an array of those same strings, but each string has its letters rearranged such that it becomes a palindrome (if possible, if not, return -1)
*/

bool makePalin(char word[],int n) {
  string res;
  
  int count[26]={0};
  for(int i=0;i<n;i++)  count[word[i]-'a']++;
  int oddCount = 0;
  char oddChar;
  for(char c='a';c<='z';c++) {
    if(!(count[c-'a']&1)) res += c;
    else {
      oddChar = c;
      oddCount++;
      if(oddCount > 1)  return false;
    }
  }
  
  return true;
}
