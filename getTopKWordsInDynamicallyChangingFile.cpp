/*
 There is a big file of words which is dynamically changing. We are continuously adding some words into it. How would you keep track of top 10 trending words at each moment?
 */
 
 /*Approach :
 1) Using HashMap- 
  - insert all words to hashmap with freq
  - sort the hashmap acc to freq
  - print top k words
2) Using hashmap and minheap
  - insert each word by word to hash and keep on increasing freq
  - take the minheap of k size and increase word freq if already present
  - insert element into minheap<word,freq> - keep in adding if empty or replace the root node and heapify
  - print the entire minheap with word and freq
3) Using Trie- Trie can be efficient data structure to store words if the dictionary size if too large.
  - Modify the vanilla trie structure to include frequency field also.
  - insert each word to trie and increase freq counter in case of repetition.
  - use and same as above minheap to keep track of top k words.
  
*/
 
#include	<iostream>
#include	<string>
#define MAX 256
using namespace std;

struct Node {
	bool isEnd;
	int freq;
	struct Node *child[MAX];
	Node() {
		isEnd = false;
		freq = 0;
		for(int i=0;i<MAX;i++)
			child[i] = NULL;
	}
};
struct HeapNode {
	string word;
	int freq;
	HeapNode(){}
	HeapNode(string w,int f):word(w),freq(f){}
};
void heapify(HeapNode words[],int n,int i ) {
	int l = 2*i+1;
	int r = 2*i+2;
	int mn = i;
	if(l<n && words[l].freq < words[i].freq)
		mn = l;
	if(r<n && words[r].freq < words[i].freq)
		mn = r;
	if(mn != i) {
		swap(words[mn],words[i]);
		heapify(words,n,mn);
	}
}
int contains(HeapNode words[],int n,string str){ 
	for(int i=0;i<n;i++)
		if(words[i].word==str)
			return i;
	return -1;
}
class Trie {
	HeapNode *words;
	int k;
	int sz;
	public:
		Trie(int k) {
			this->k = k;
			this->sz = 0;
			words = new HeapNode[k];
		} 
		void insert( Node *&root, char *w, string str ) {
			if(!root)	root = new Node();
			if(!*w) {
				root->isEnd = true;
				root->freq++;
				int k1;
				if( (k1= contains(words,sz,str))!=-1 )
					words[k1].freq++;
				else {
					if(sz == k) {
						if(root->freq > words[0].freq) {
							words[0].word = str;
							words[0].freq = root->freq;
						}
					} else 
						words[sz++] = HeapNode(str,root->freq);
				}
				heapify(words,sz,0);
				return;
			}
			insert(root->child[*w-'a'],w+1,str);
		}
		void print() {
			cout<<"Top "<<sz<<" Most frquent Words are - :"<<endl;
			for(int i =0;i<sz;i++) {
				cout<<words[i].word<<" :  "<<words[i].freq<<endl;
			}
			cout<<endl;
		}
		void traverse(Node *root, char *w,int index) {
			if(!root)	return;
			if(root->isEnd) {
				w[index] = '\0';
				cout<<w<<" : "<<root->freq<<endl;
				return;
			}
			for(int i=0;i<MAX;i++) {
				w[index] = ('a'+i);
				traverse(root->child[i],w,index+1);
			}
		}
};
int main() {
	Trie obj(2);
	Node *root = NULL;
	char *word[] = {"a","b","c","a","b","c","a","d","d","d","d"};
	int N = sizeof(word)/sizeof(word[0]);
	for(int i=0;i<N;i++)
		obj.insert(root,word[i],string(word[i]));
	obj.print();
	
	cout<<"Print the Entire trie - "<<endl;
	char w[10] = {'\0'};
	obj.traverse(root,w,0);
	return 0;
}
