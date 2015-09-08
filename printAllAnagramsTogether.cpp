#include    <iostream>
#include    <unordered_map>
#include    <list>
#include    <algorithm>
#include    <string.h>
using namespace std;

/*first method*/
string words[] = {"hat","that","pat","tah","aht","atth"};
void traverseHash(unordered_map<string,list<string> > map) {
    unordered_map<string,list<string> >::iterator it;
    for(it=map.begin();it != map.end();it++)
    {
        list<string>::iterator itlist;
        string word = (*it).first;
        list<string> node = (*it).second;
        cout<<word<<" : ";
        for(itlist=node.begin();itlist != node.end();itlist++)
        {
            cout<<*itlist<<" ";
        }
        cout<<endl;
    }
}

void printWordAnangram(unordered_map<string,list<string> > map) {
    unordered_map<string,list<string> >::iterator it;
    string word;
    cin>>word;
    cout<<word<<" : ";
    sort(word.begin(),word.end());
    it = map.find(word);
    if(it != map.end() )
    {
        list<string> node = (*it).second;
        list<string>::iterator it = node.begin();
        for(;it != node.end(); it++)
            cout<<*it<<" ";
    }
    else
    {
        cout<<"No Such Word";
    }
    cout<<endl;
}

/*second method*/
struct Map {
    char *w;
    int index;
    Map() {w = NULL;}
    Map(char *w,int idx) {
        this->w = (char *)malloc(strlen(w));
        strcpy( this->w, w);
        index = idx;
    }
    ~Map() {
        //free(w);
    }
};
int compareChar(const void *a, const void *b) {
    return (*(const char *)a) - (*(const char *)b);
}
int compare(const void *w11, const void *w12) {
    Map m1 = *(Map *)(w11);
    Map m2 = *(Map *)(w12);
    char *w1 = m1.w;
    char *w2 = m2.w;
    qsort(w1,strlen(w1),sizeof(char),compareChar);
    qsort(w2,strlen(w2),sizeof(char),compareChar);
    return strcmp(w1,w2);
}
int main()
{
    unordered_map<string,list<string> > map;
    unordered_map<string,list<string> >::iterator it;
    int size = sizeof(words)/sizeof(string);
    string copy[size];
    for(int i=0;i<size;i++) copy[i] = words[i];
    for(int i=0;i<size;i++) sort(copy[i].begin(),copy[i].end());

    for(int i=0;i<size;i++) {
        it = map.find(copy[i]);
        if(it != map.end()) {
            list<string> node = (*it).second;
            node.push_back(words[i]);
            map[copy[i]] = node;
        }
        else {
            list<string> node;
            node.push_back(words[i]);
            map.insert( make_pair(copy[i],node));
        }
    }
    cout<<"C++ Style anagram sorting, Using Hash - "<<endl;
    traverseHash(map);

    cout<<"\n\nEnter A word to print it anagrams : ";
    printWordAnangram(map);

    cout<<"\n\nNow, C style anagram sorting - "<<endl;
    int N = 4;
    char word[][32] = { "abc","dba","acb","abd" };
    Map m[N];
    for(int i=0;i<N;i++) {
        m[i] = Map(word[i],i);
    }
    qsort(m,N,sizeof(m[0]),compare);
    cout<<"Sorted Words - "<<endl;
    for(int i=0;i<N;i++)
        cout<<word[ m[i].index ]<<" ";
    cout<<endl;


    cout<<"\n\nThird Method, using Trie"<<endl;
    cout<<"Enter Sorted Words in Trie with Index listing in leaf node"<<endl;
    cout<<"ToDo"<<endl;
    return 0;
}
