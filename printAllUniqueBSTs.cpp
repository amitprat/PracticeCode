#include    <iostream>
#include    <vector>
using namespace std;

struct tree
{
    int data;
    struct tree *left,*right;
    tree(int data, struct tree *left = NULL, struct tree *right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void print( tree *root) {
    if(root){
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
    }
}

vector<tree *> countTree(int l,int r)
{
    vector<tree *> trees;
    if(l > r)   trees.push_back(NULL);
    else {
        for(int i=l;i<=r;i++) {
            vector<tree *> left = countTree(l,i-1);
            vector<tree *> right = countTree(i+1,r);
            for(auto j : left) {
                for(auto k : right) {
                    trees.push_back( new tree(i,j,k) );
                }
            }
        }
    }
    return trees;
}
void printTrees(vector<tree *> root) {
    for(auto i : root) {
        print(i);
        cout<<endl;
    }
    cout<<"\n\n";
}
int main()
{
    vector<tree *> trees = countTree(1,3);
    cout<<"size : "<<trees.size()<<endl;
    printTrees(trees);
    return 0;
}
