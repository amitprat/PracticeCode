/*
print diameter in binary tree
print longest path in binary tree
longest path in tree
*/
#include    <iostream>
#include    <vector>
using namespace std;

struct tree
{
    char data;
    struct tree *left,*right;
    tree(int data,struct tree *left=NULL,struct tree *right=NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
void traverse(tree *root)
{
    if(root) {
        traverse(root->left);
        cout<<root->data<<" ";
        traverse(root->right);
    }
}
int height(tree *root,vector<char> &path) {
    if(!root)   return 0;
    vector<char> lpath,rpath;
    int lh = height(root->left,lpath);
    int rh = height(root->right,rpath);
    if(lh > rh) path = lpath;
    else    path = rpath;
    path.push_back(root->data);
    return max( lh,rh ) + 1;
}
int longest(tree *root,vector<char> &path) {
    if(!root)   return 0;
    vector<char> lpath,rpath,lv,rv;
    int ld = longest(root->left,lpath);
    int rd = longest(root->right,rpath);
    int cmax = height(root->left,lv) + height(root->right,rv) + 1;

    if(cmax > max(ld,rd)) {
        lv.push_back(root->data);
        path = lv;
        path.insert(path.end(),rv.begin(),rv.end());
    } else if(ld > rd)  path = lpath;
    else path = rpath;
    return max(cmax,max(ld,rd));
}
int main()
{
    tree *root = new tree('A');
    root->left = new tree('B');
    root->left->left=  new tree('C');
    root->left->right = new tree('E');
    root->left->right->left = new tree('D');
    root->right = new tree('F');
    root->right->left = new tree('G');
    traverse(root);
    cout<<endl;
    vector<char> path;
    cout<< longest(root,path) <<endl;
    for(auto i : path)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}
