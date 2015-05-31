/*in a tree any root can have any number of children. Every node has an integer value. Find the maximum length on consecutive number sequence anywhere in the tree. For example if root is 2 and one child is 3, its child is 4 its child is 6 then max length will be 3. I was able to write the code the find of one sequence but when one sequence ends and other starts I was not able to handle that case. I think its hard to do by recursion. Is there any other trick or algorithm for this??*/

#include    <iostream>
#include    <vector>
#include    <cmath>
#include    <unordered_map>
using namespace std;

struct tree
{
    int data;
    int size;
    struct tree **child;
    tree() {}
    tree(int data,int size=0) {
        this->data = data;
        this->size = size;
        child = NULL;
        if(size > 0) {
            child = new tree*[size];
            for(int i=0;i<size;i++)
                child[i] = NULL;
        }
    }
    void deleteTree(tree *root) {
        if(!root)   return;
        for(int i=0;i<root->size;i++) {
            deleteTree(root->child[i]);
        }
        if(! root->size) delete root;
    }
    ~tree() {
    }
};
void print(tree *root) {
    if(root) {
        cout<<root->data<<" ";
        for(int i=0;i<root->size;i++)
            print(root->child[i]);
    }
}
void findLongest(tree *root,unordered_map<int, vector<int> > &m)
{
    if(!root)   return;
    for(int i=0;i<root->size;i++) {
        int tmp = root->child[i]->data;
        if(m.find(tmp-1) != m.end())
            m[tmp-1].push_back(tmp);
        else if (m.find(tmp+1) != m.end())
            m[tmp+1].push_back(tmp);

        findLongest(root->child[i],m);
    }
}
void findLongest(tree *root,vector<int> cur,vector<int> &ml,int prev=0)
{
    if(!root)
        return;

    if( abs(prev-root->data) == 1 )
        cur.push_back(root->data);
    else {
        if(cur.size() > ml.size())
            ml = cur;
            cur.clear();
            cur.push_back(root->data);
    }
    if(!root->size) {
        if(ml.size() < cur.size())
            ml = cur;
    } else {
        for(int i=0;i<root->size;i++) {
            findLongest(root->child[i],cur,ml,root->data);
        }
    }
}
int main()
{
    tree *root = new tree(2,4);
    unordered_map<int, vector<int> >m;
    root->child[0] = new tree(3,3);
    root->child[1] = new tree(4,2);
    root->child[2] = new tree(5,2);
    root->child[3] = new tree(6,2);

    root->child[0]->child[0] = new tree(4);
    root->child[0]->child[1] = new tree(5);
    root->child[0]->child[2] = new tree(6);

    root->child[1]->child[0] = new tree(5,1);
    root->child[1]->child[1] = new tree(6);

    root->child[2]->child[0] = new tree(6);
    root->child[2]->child[1] = new tree(7);

    root->child[3]->child[0] = new tree(7);
    root->child[3]->child[1] = new tree(8);

    root->child[1]->child[0]->child[0] = new tree(6,1);
    root->child[1]->child[0]->child[0]->child[0] = new tree(7);
    //print(root);
    //findLongest(root,m);
    vector<int> v;
    findLongest(root,vector<int>(),v);
    for(int j=0;j<v.size();j++) {
        cout<<v[j]<<" ";
    }
    cout<<endl;
    deleteTree(root);
    return 0;
}
