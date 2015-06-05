/*
(Variant of Children-Sum Problem better than O(n^2)) 
Given a tree, implement a function which replaces a node’s value with the sum of all its childrens’ value, considering only those children whose value is less than than the main node’s value. 
Eg: input = 60->50->80->40 , output = 90->40->40->0
*/
#include    <iostream>
#include    <unordered_map>
using namespace std;

struct tree{
    int data;
    struct tree *left,*right;

    tree(int data) {
        this->data = data;
        left = right = NULL;
    }
};
void find(tree *root,unordered_map<tree *,pair<int,int> > &m)
{
    if(!root)   return;
    for(auto i : m)
        if(root->data < i.second.first)
            m[i.first].second += root->data;

    m[root] = make_pair(root->data,0);
    find(root->left,m);
    find(root->right,m);
    cout<<m[root].second<<" ";
}
int main()
{
    tree *root = new tree(6);
    root->left = new tree(3);
    root->right = new tree(5);
    root->right->left = new tree(18);
    root->right->right = new tree(5);
    root->left->left = new tree(4);
    root->left->right = new tree(2);
    unordered_map<tree *,pair<int,int> > m;
    find(root,m);
    return 0;
}
