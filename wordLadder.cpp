/*
Transform one word into another by changing only one letter at a time

Given two words of equal length that are in a dictionary, write a method to transform one word into another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.
EXAMPLE
Input: DAMP, LIKE
Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <queue>

using namespace std;

#define LARGE_DICT
#define BFS
class dict
{
    unordered_map<string,bool> dictionary;
public:
    dict() {
        dictionary["DAMP"] = true;
        dictionary["LAMP"] = true;
        dictionary["LIMP"] = true;
        dictionary["LIKE"] = true;
        dictionary["LIME"] = true;
        dictionary["DOSA"] = true;

        dictionary["HOT"] = true;
        dictionary["DOT"] = true;
        dictionary["DOG"] = true;
        dictionary["LOG"] = true;
        dictionary["LOT"] = true;
    }
    bool contains(string s) {
        return (dictionary[s]);
    }
};

dict d;

bool dist(string s1,string s2)
{
    int count = 0;
    for(int i=0;i<s1.length();i++) {
        if(s1[i] != s2[i])  count++;
        if(count > 1)   return false;
    }
    return true;
}
#ifdef LARGE_DICT
vector<string> getOneDistant(string s)
{
    vector<string> result;
    for(int i=0;i<s.length();i++)
    {
        string prefix = s.substr(0,i);
        string suffix = s.substr(i+1);
        for(char j = 'A';j<='Z';j++) {
            string tmp = prefix + j + suffix;
            if( tmp != s && d.contains(tmp) && dist(tmp,s) )
                result.push_back(tmp);
        }
    }
    return result;
}
#else
vector<string> getOneDistant(string s)
{
    vector<string> result;
    for(auto word:d)
    {
        if(dist(word,s) )
            result.push_back(word);
    }
    return result;
}
#endif

/*Using DFS approach */
#ifdef DFS
void ladderutil(string s,string d,unordered_map<string,bool> visited, vector<string> subset,vector< vector<string> > &totalset,int &minlen)
{
    if(s == d) {
        if(subset.size() < minlen)
            minlen = subset.size();
        totalset.push_back(subset);
        return;
    }

    vector<string> resultset = getOneDistant(s);
    for(auto word : resultset)
    {
        if(!visited[word])
        {
            visited[word] = true;
            subset.push_back(word);
            ladderutil(word,d,visited,subset,totalset,minlen);
            visited[word] = false;
            subset.pop_back();
        }
    }
}
void ladder(string s,string d)
{
    vector<string> subset;
    vector< vector<string> > totalset;
    unordered_map<string,bool> visited;
    visited[s] = true;
    int minlen = INT_MAX;
    subset.push_back(s);
    ladderutil(s,d,visited,subset,totalset,minlen);
    cout<<"minlen :"<<minlen<<endl;

    for(int i=0;i<totalset.size();i++) {
        for(int j=0;j<totalset[i].size();j++) {
            cout<<totalset[i][j]<<" --> ";
        }
        cout<<endl;
    }
}
#endif // DFS

#ifdef BFS
vector<string> ladderUtil(string s,string e)
{
    queue<string> q;
    unordered_map<string,bool> visited;
    unordered_map<string,string> route;

    q.push(s);
    visited[s] = true;
    vector<string> result;
    while(!q.empty())
    {
        string tmp = q.front(); q.pop();
        if(tmp == e) {
            result.push_back(s);
            while(route.find(tmp) != route.end()){
                result.insert(result.begin(),tmp);
                tmp = route[tmp];
            }
            return result;
        }

        vector<string> resultSet = getOneDistant(tmp);
        for(string word : resultSet) {
            if(!visited[word]) {
                visited[word] = true;
                q.push(word);
                route[word] = tmp;
            }
        }
    }
    return result;
}
void ladder(string s,string e)
{
    vector<string> result = ladderUtil(s,e);
    for(auto word : result)
        cout<<word<<"-->";
    cout<<endl;
}
#endif // BFS
int main()
{
    string start = "DOT";
    string end = "LOG";
    ladder(start,end);
    return 0;
}
