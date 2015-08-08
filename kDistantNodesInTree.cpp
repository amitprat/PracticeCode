/*
print K distance nodes from a given node in a tree
KDistantNodesInATree
nodes at K distance from any given node in tree
*/
#include <iostream>
using namespace std;

// A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};
void printDown(node *root,int k) {
    if(k < 0 || !root)   return;
    //cout<<root->data<<" "<<k<<endl;
    if(k == 0)  { cout<<root->data<<" "; return; }
    printDown(root->left,k-1);
    printDown(root->right,k-1);
}
int printKDistNodes(node *root,node *a,int k) {
    if(!root)   return -1;
    if(root == a) {
        printDown(a,k);
        return k-1;
    }
    int op = printKDistNodes(root->left,a,k);
    if(op != -1) {
        if(op == 0) cout<<root->data<<" ";
        else        printDown(root->right,op-1);
        return op-1;
    }
    op = printKDistNodes(root->right,a,k);
    if(op != -1) {
        if(op == 0) cout<<root->data<<" ";
        else printDown(root->left,op-1);
        return op-1;
    }
    return -1;
}
// A utility function to create a new binary tree node
node *newnode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    node * root = newnode(20);
    root->left = newnode(8);
    root->right = newnode(22);
    root->left->left = newnode(4);
    root->left->right = newnode(12);
    root->left->right->left = newnode(10);
    root->left->right->right = newnode(14);
    node * target = root->left->right;
    printKDistNodes(root, target, 2);
    return 0;
}
