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
#include     <iostream>
#include     <string.h>
#include     <map>
using namespace std;

typedef struct _tst
{
    char data;
    struct _tst *left,*right,*eq;
    bool isEndOfStr;
}tst;
tst *newnode(char data)
{
    tst *new_node = (tst *)malloc(sizeof(tst));
    new_node->data = data;
    new_node->left = new_node->right= new_node->eq = NULL;
    new_node->isEndOfStr = false;
    return new_node;
}
void insertNode(tst **root,char *word)
{
    if(!(*root)) 
        (*root) = newnode(*word);
    if(*word < (*root)->data)
        insertNode(&((*root)->left),word);
    else if( *word > (*root)->data)
        insertNode( &((*root)->right),word);
    else
    {
        if( *(word+1))
            insertNode( &((*root)->eq),word+1);
        else
            (*root)->isEndOfStr = true;
    }
}
bool search(tst *root,char *word)
{
    if(!root) return false;
    if(root->data > *word)
        return search(root->left,word);
    else if(root->data < *word)
        return search(root->right,word);
    else
    {
        if(*(word+1) == '\0')
            return root->isEndOfStr;
        else
            return search(root->eq,word+1);
    }
}
void traverse(tst *root,char *buffer,int depth)
{
    if(!root) return;
    traverse(root->left,buffer,depth);
    buffer[depth] = root->data;
    if(root->isEndOfStr)
    {
        buffer[depth+1] = '\0';
        cout<<buffer<<endl;
    }
    traverse(root->eq,buffer,depth+1);
    traverse(root->right,buffer,depth);
}
void displayWordWithPrefix(tst *root,char *word,char *buffer,int depth)
{
    if(!root) return;
    if(root->data > *word)
         displayWordWithPrefix(root->left,word,buffer,depth);
    else if(root->data < *word)
         displayWordWithPrefix(root->right,word,buffer,depth);
    else
    {
        if(*(word+1) == '\0')
        {
            buffer[depth] = root->data;
            traverse(root->eq,buffer,strlen(buffer));
        }
        else
        {
            buffer[depth] = root->data;
            displayWordWithPrefix(root->eq,word+1,buffer,depth+1);
        }
    }
}
void spellCheck(tst *root,char *buffer,int depth,char *word)
{
    if(!root) return;
    spellCheck(root->left,buffer,depth,word);
    buffer[depth] = root->data;
    if(root->isEndOfStr)
    {
        buffer[depth+1] = '\0';
        int diff = 0;
        for(int i=0;i<=max(depth,(int)strlen(word));i++)
            if(!word || !buffer || word[i] != buffer[i]) diff++;
        if(diff < 7)
            cout<<buffer<<endl;
    }
    spellCheck(root->eq,buffer,depth+1,word);
    spellCheck(root->right,buffer,depth,word);
}
int main()
{
   tst *root = NULL;
   char buffer[32];
   insertNode(&root,"amit");
   insertNode(&root,"amitpratap");
   insertNode(&root,"amitpratapsingh");
   bool result = search(root,"amit");
   cout<<result<<endl;
   result = search(root,"sisngh");
   cout<<result<<endl;
   traverse(root,buffer,0);
   memset(buffer,0,32);
   displayWordWithPrefix(root,"ami",buffer,0);
   map<char*,int> diff;
   memset(buffer,0,32);
   spellCheck(root,buffer,0,"asitpratap");
   return 0;
}

#endif
