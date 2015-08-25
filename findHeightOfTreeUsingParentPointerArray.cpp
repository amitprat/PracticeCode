/*
Tags - Construct Binary tree using parent pointer array
     - Find height of binary tree from given parent array
*/


/*
Find Height of Binary Tree represented by Parent array

Input: parent [] = {1 5 5 2 2 -1 3} Output: 4

I did it in O(n2) and then interviewer ask to optimize it then I optimize the code but still it is O(n2) but the interviewer was satisfied with the solution.
*/

/*
O(n2) Approach - 
1) Construct tree using parent pointer 
2) Get the height of tree
*/
#include    <iostream>
#include    <unordered_map>
using namespace std;

struct tree
{
    int data;
    struct tree *left,*right,*parent;
    tree(int data):data(data),left(NULL),right(NULL),parent(NULL){}
};
void traverse(tree *root) {
    if(root) {
        traverse(root->left);
        cout<<root->data<<" ";
        traverse(root->right);
    }
}
int height(tree *root) {
    if(!root)   return 0;
    return max(height(root->left),height(root->right))+1;
}
int main()
{
    tree *root = NULL;
    int p[] = {1,5,5,2,2,-1,3};
    int n = sizeof(p)/sizeof(int);
    unordered_map<int, tree *> m;
    for(int i=0;i<n;i++) {
        m[i] = new tree(i);
    }
    for(int i=0;i<n;i++) {
        if(p[i] != -1) {
            tree *parent = m[p[i]];
            m[i]->parent = parent;
            if(parent->left == NULL)
                parent->left = m[i];
            else
                parent->right= m[i];
        } else
            root = m[i];
    }
    traverse(root);

    cout<<"\nHeight : "<<height(root)<<endl;

    return 0;
}

/*
Second Approach - O(n) time.

[1,5,5,2,2,-1,3]

1) Find the index of node with parent pointer value as -1. This node is root node of tree., [5]
2) Find this node in parent array. [ 1,2 ]
3) Count the possible nodes left and right of this node ( unique nodes, here in example is 2,3,5,6 (indices) )
. These are the number of nodes in most dense part of tree.
4) Return the maximum of it.

Another example -
[1,5,5,2,3,-1,4]

1) Index = 5;
2) Nodes [1,2]
3) left = 0,1 ; right = 2,3,4,5,6
4) Height = 5;

*/
