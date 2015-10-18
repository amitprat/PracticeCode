/*
Easy Approach - 
Time = O(n)
Space = O(n)
1. Take set or hashmap of size n
2. Traverse the tree in any order
3. Check of (sum-root->val) exists in map/set, if yes then print and return true, else insert it into set/map

Better Approach - 

Time = O(n)
Space = O(lgn)
Algorithm Taken from stackoverflow-
Two pointers or iterators, one from left to right (small to big) and one from right to left (big to small). If (a + b) > k then iterate the right to left one (the next smaller value) else the other one (the next bigger value). You can stop if a >= b The runtime is linear even in case of unbalanced tree. Every node is visited max one time.

I think real function recursion will become somewhat complicated in this case. So better use two selfmade stacks to do the recursion in one function. Something like that:

a = b = root;
while (a.left) {
    astack.push(a)
    a = a.left
}
while (b.right) {
    bstack.push(b)
    b = b.right
}


while (a.value < b.value) {
    if (a.value + b.value == k) found!
    if (a.value + b.value < k) {
        if (a.right){
            a = a.right
            while (a.left) {
                astack.push(a)
                a = a.left
            }
        } else a = astack.pop()
    } else {
        if (b.left){
            b = b.left
            while (b.right) {
                bstack.push(b)
                b = b.right
            }
        } else b = bstack.pop()
    }
}
*/


#include	<iostream>
#include	<string.h>
#include	<stdlib.h>
#include	<stack>
#include	<unordered_set>
using namespace std;
typedef unordered_set<int> Map;
struct node {
	int val;
	struct node *left,*right;
};
// A utility function to create BST node
struct node * NewNode(int val)
{
	struct node *tmp = (struct node *)malloc(sizeof(struct node));
	tmp->val = val;
	tmp->right = tmp->left =NULL;
	return tmp;
}

bool isPairPresent(node *root,int sum) {
	node *a,*b;
	a = b = root;
	stack<node *> ast, bst;
	while(a->left) {
		ast.push(a);
		a = a->left;
	}
	while(b->right) {
		bst.push(b);
		b = b->right;
	}

	while(a->val < b->val) {
		int s = a->val + b->val;
		if(s == sum)	{
			printf("Found pair : %d, %d\n",a->val,b->val);
			return true;
		}
		if(s > sum) {
			if(b->left) {
				b = b->left;
				while(b->right) {
					bst.push(b);
					b = b->right;
				}
			} else {
				b = bst.top(); bst.pop();
			}
		}
		else {
			if(a->right) {
				a = a->right;
				while(a->left) {
					ast.push(a);
					a = a->left;
				}
			} else {
				a = ast.top(); ast.pop();
			}
		}
	}
	return false;
}
// Driver program to test above functions
int main()
{
	/*
	   15
	   /     \
	   10      20
	   / \     /  \
	   8  12   16  25    */
	struct node *root =  NewNode(15);
	root->left = NewNode(10);
	root->right = NewNode(20);
	root->left->left = NewNode(8);
	root->left->right = NewNode(12);
	root->right->left = NewNode(16);
	root->right->right = NewNode(25);
	int target = 33;
	if (isPairPresent(root,target) == false)
		printf("\n No such values are found\n");

	getchar();
	return 0;
}
