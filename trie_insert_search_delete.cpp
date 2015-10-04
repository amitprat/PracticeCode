#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

typedef struct _trie
{
    struct _trie *child[26];
    bool isend;
}trie;

trie *newnode()
{
    trie *new_node = (trie *)malloc(sizeof(trie));
    for(int i=0;i<26;i++)
        new_node->child[i] = NULL;
    new_node->isend = false;
    return new_node;
}

trie *insert(char *word,trie *root)
{
    if(!root) root = newnode();
    if (*word == '\0') {
        root->isend = true;
        return root;
    }
    root->child[*word-'a'] = insert(word+1,root->child[*word - 'a']);
    return root;
}

trie *insertiter(char *word,trie *root)
{
    if(!root)
        root = newnode();
    trie *temp = root;
    for(int i=0;i<strlen(word);i++) {
        if(!(root->child[ word[i] - 'a']))
            root->child[ word[i] - 'a'] = newnode();
        root = root->child[word[i] - 'a'];
    }
    root->isend = true;
    return temp;
}

void printAll(trie *root,char *word,int level)
{
    if(!root) return;
    if(root && root->isend)
    {
        word[level] = '\0';
        printf("%s\n",word);
    }
    for(int i=0;i<26;i++)
    {
        if(root->child[i])
        {
            word[level] = i + 'a';
            printAll(root->child[i],word,level+1);
        }
    }
}
bool printMatching(char *word,trie *root,char *wordcopy,int len)
{
    if(!root)
        return false;
    if(*word == '\0' && root->isend == true)
        return true;
    else if(*word == '\0')
    {
        printAll(root,wordcopy,len);
        return false;
    }

    return printMatching(word+1,root->child[*word-'a'],wordcopy,len);
}

bool search(char *word,trie *root)
{
    if(!root)
        return false;
    if(*word == '\0' && root->isend == true)
        return true;
    return search(word+1,root->child[*word-'a']);
}

bool searchiter(char *word,trie *root)
{
    for(int i=0;i<strlen(word);i++)
    {
        if(!(root->child[word[i] - 'a']))
            return false;
        root = root->child[word[i] - 'a'];
    }
    if(root && root->isend)
        return true;
    return false;
}
bool isFree(trie *root)
{
    for(int i=0;i<26;i++)
        if(root->child[i])
            return false;
    return true;
}
bool isLeaf(trie *root)
{
    return root->isend;
}
bool deleteHelper(trie **root,char *word)
{
    if(!(*root))   return false;
    if( *word == '\0')
    {
        (*root)->isend = false;
        if(isFree(*root))
            return true;
    }
    else if(deleteHelper (&((*root)->child[*word-'a']),word+1))
    {
        free ((*root)->child[*word-'a'] );
        (*root)->child[*word-'a'] = NULL;
        if(isFree(*root) && !isLeaf(*root))
            return true;
    }
    return false;
}

void deleteTrie(trie **root,char *word)
{
    deleteHelper(root,word);
}

int main()
{
    trie *root = newnode();
    root = insertiter("amit",root);
    root = insertiter("amitwa",root);

    root = insertiter("aamit",root);
    root = insertiter("amitpratapsingh",root);

    bool res = search("singh",root);
    printf("res : %d\n",res);
    deleteTrie(&root,"singh");
    res = search("singh",root);
    printf("res : %d\n",res);
    char *wordcopy = (char *)malloc(32);
    memset(wordcopy,0,32);
    strncpy(wordcopy,"am",2);
    printMatching("am",root,wordcopy,2);
    return 0;
}
