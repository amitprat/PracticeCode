#include	<iostream>
#include	<unordered_map>
using namespace std;
typedef unordered_map<int,int> Map;

struct tree
{
	int data;
	struct tree *left,*right;
	tree(int data) {
		this->data = data;
		left = right = NULL;
	}
};

void diagSum(tree *root,Map &map,int pos) {
	if(root) {
		map[pos] += root->data;
		diagSum(root->left,map,pos+1);
		diagSum(root->right,map,pos);
	}
}
int main() {
	Map map;
	tree *root = new tree(1);
	root->left = new tree(4);
	root->left->right = new tree(5);
	root->right = new tree(2);
	root->right->left = new tree(6);
	root->right->right = new tree(3);
	root->right->right->left = new tree(7);
	root->right->right->left->left = new tree(10);
	root->left->left = new tree(8);
	root->left->left->right = new tree(9);
	diagSum(root,map,0);	
	for(auto i : map) {
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}
