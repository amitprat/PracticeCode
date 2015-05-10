#include    "gprot.h"
#define N 5
class node
{
public:
    char data;
    int keys;
    node **child;
    node()
    {
        data = '0';
        keys = 0;
    }
    node(char data,int keys = N):data(data) , keys(keys)
    {
        child = new node *[keys];
        for(int i=0;i<keys;i++)
            child[i] = NULL;
    }
};

void traverse(node *root)
{
    if(!root)   return;
    cout<<root->data<<" ";
    for(int i=0;i<root->keys;i++)
        traverse(root->child[i]);
}
void serialize(FILE *fp, node *root)
{
    if(!root) {
        fprintf(fp,"%s","#");
        return;
    }
    fprintf(fp,"%c",root->data);
    for(int i=0;i<root->keys;i++)
        serialize(fp,root->child[i]);
    delete root;
}
node *deserialize(FILE *fp, node *root)
{
    char buf;
    if(fscanf(fp,"%c",&buf) == EOF)   return NULL;
    if(buf == '#')    return NULL;
    root = new node(buf);
    for(int i=0;i<N;i++)
    {
        root->child[i] = deserialize(fp,root->child[i]);
        if(!(root->child[i]))
            break;
    }
    return root;
}
int main()
{
    FILE *fp = fopen("tree1.txt","w");
    if(!fp) {
        cout<<"File error!";
        return 0;
    }
    node *root = new node('A');
    root->child[0] = new node('B');
    root->child[1] = new node('C');
    root->child[2] = new node('D');
    root->child[0]->child[0] = new node('E');
    root->child[0]->child[1] = new node('F');
    root->child[2]->child[0] = new node('G');
    root->child[2]->child[1] = new node('H');
    root->child[2]->child[2] = new node('I');
    root->child[2]->child[3] = new node('J');
    root->child[0]->child[1]->child[0] = new node('K');
    traverse(root);
    serialize(fp,root);
    fclose(fp);
    fp = fopen("tree1.txt","r");
    root = deserialize(fp,root);
    fclose(fp);
    traverse(root);
}
