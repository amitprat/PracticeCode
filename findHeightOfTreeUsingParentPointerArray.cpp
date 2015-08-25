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

/*Third Approach - Taken from Geeksforgeeks.org
Using parent depth array;
1) Find depth of all nodes and fill in an auxiliary array depth[].
2) Return maximum value in depth[].

Following are steps to find depth of a node at index i.
1) If it is root, depth[i] is 1.
2) If depth of parent[i] is evaluated, depth[i] is depth[parent[i]] + 1.
3) If depth of parent[i] is not evaluated, recur for parent and assign depth[i] as depth[parent[i]] + 1 (same as above).

Following is C++ implementation of above idea.
*/
// C++ program to find height using parent array
#include <iostream>
using namespace std;
 
// This function fills depth of i'th element in parent[].  The depth is
// filled in depth[i].
void fillDepth(int parent[], int i, int depth[])
{
    // If depth[i] is already filled
    if (depth[i])
        return;
 
    // If node at index i is root
    if (parent[i] == -1)
    {
        depth[i] = 1;
        return;
    }
 
    // If depth of parent is not evaluated before, then evaluate
    // depth of parent first
    if (depth[parent[i]] == 0)
        fillDepth(parent, parent[i], depth);
 
    // Depth of this node is depth of parent plus 1
    depth[i] = depth[parent[i]]  + 1;
}
 
// This function returns height of binary tree represented by
// parent array
int findHeight(int parent[], int n)
{
    // Create an array to store depth of all nodes/ and
    // initialize depth of every node as 0 (an invalid
    // value). Depth of root is 1
    int depth[n];
    for (int i = 0; i < n; i++)
        depth[i] = 0;
 
    // fill depth of all nodes
    for (int i = 0; i < n; i++)
        fillDepth(parent, i, depth);
 
    // The height of binary tree is maximum of all depths.
    // Find the maximum value in depth[] and assign it to ht.
    int ht = depth[0];
    for (int i=1; i<n; i++)
        if (ht < depth[i])
            ht = depth[i];
    return ht;
}
 
// Driver program to test above functions
int main()
{
    // int parent[] = {1, 5, 5, 2, 2, -1, 3};
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};
 
    int n = sizeof(parent)/sizeof(parent[0]);
    cout << "Height is " << findHeight(parent, n);
    return 0;
}
