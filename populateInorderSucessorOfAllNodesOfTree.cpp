
/*Do reverse inorder traversal*/

struct tree {
	int data;
	struct tree *left,*right,*next;
};
void print(tree *root) {
	static struct tree *next = NULL;
	if(root) {
		print(root->right);
		root->next = next;
		next = root;
		print(root->left);
	}
}
