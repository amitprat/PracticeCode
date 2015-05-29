
tree *inorder_suc(tree *root,tree *node) {
  if(!root || !node)  return NULL;
  if(root->right) return min(root->right);
  
  tree *parent = root->parent;
  while(parent && parent->left != right) {
    root = parent;
    parent = root->parent;
  }
  return parent;
}
