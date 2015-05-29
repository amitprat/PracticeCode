tree *successor(tree *root,tree *node) {
  if(node->right) return min(node->right);
  static tree *succ = NULL;
  while(root) {
    if( node->data < root->data) {
      succ = root;
      root = root->left;
    } else {
      root = root->right;
    } else
      break;
  }
  
  return succ;
}
