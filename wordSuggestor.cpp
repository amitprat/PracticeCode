#include    <iostream>
#include    <list>
#include    <map>
#include    <string>
using namespace std;
#define HASH_SUGGESTOR
/*Word suggesstor using Hashing
#ifdef HASH_SUGGESTOR
int main()
{
    string str[3] = {"apple","appron","ape"};
    map< string,list<int> > table;
    map< string,list<int> >::iterator it;
    for(int i=0;i<3;i++)
    {
        for(int j=1;j<=str[i].size();j++)
        {
            string s1 = str[i].substr(0,j);
            it = table.find(s1);
            list<int> l;
            if(it != table.end())
                l= table[s1];
            l.push_back(i);
            table[s1] = l;
        }
    }
    list<int> l3 = table["app"];
    list<int>::iterator it1 = l3.begin();
    for(;it1!=l3.end();it1++)
        cout<<str[*it1]<<" ";
}
#endif

#ifdef TERNARYTREE_SUGGESTOR

#endif
