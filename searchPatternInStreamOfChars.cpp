/*
Given pattern P (say aba) search for the pattern if the input is a stream of characters. 

1. You cant store the stream of chars. not even till Length(P) 
2. You have access to only one char of stream at a time. 

I gave KMP algo which was okay for him, but he mentioned you could have used some better DS.. 

I am wondering which DS can be used to store pattern.. 
Trie ??? 

You need to consider cases for stream like aababa 
there are 2 occurences
*/

1. Approach - T = O(n) where n is length of txt

int main() {
  char pat[m];  //pattern of length of m
  char txt[n]; // stream of length of n
  int lps[m];
  int count = 0;
  int len = 0;
  constructlps(lps,pat,m);  //same as kmp lps calculation method
  for(int i=0;i<n;i++) {
    int pos = isMatch(pat,lps,txt[i],m,len,count);  //little modification of original kmp method
    if( pos != -1)
      cout<<"found at "<<pos<<endl;
  }
}
int isMatch(char pat[],int lps[],char ch,int m,int len,int &count) {
  if(pat[len] == ch) {
    len++;
    count++;
  }
  if(len == m) {
    return (count - m);
  } else if( pat[len] != ch) {
    while(len)  return isMatch(pat,lps,ch,m,lps[len-1],count);
  }
  return -1;
}

2. Approach - T = O(m) where m = length of pattern

int main() {
  trie *root = new trie();
  char txt[n]; //txt of length of n
  insert(root,txt[0]);
  for(int i=1;i<n;i++) {
    insert(root,txt[i]);
    insertHead(root,txt[i]);
  }
  
  char pat[m]; //pattern of length of m
  
  cout<< "found "<<( search(root,pat) ? "Yes" : "No" ) <<endl;
  return 0;
}
void insertHead(trie *root,char ch) {
  if( !root[ INDEX(ch) ] ){
    root[ INDEX(ch) ] = new trie();
    root[ INDEX(ch) ]->isEnd = true;
  }
}
void insert( trie *root, char ch ) {
  if(isLeaf(root)){
    insertHead(root,ch);
    return;
  }
  for(int i=0;i<26;i++) {
    if(root[i])
      insert(root[i],ch);
  }
}
bool search(trie *root, char pat[],int n){
  for(int i=0;i<n;i++) {
    if(!root[ INDEX(pat[i]) ])  return false;
    root = root[ INDEX(pat[i])] ;
  }
  return true;
}
