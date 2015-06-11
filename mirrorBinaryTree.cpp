/*
      3                     3                   3
    2   1       -->     1       2     -->     1   2
  4       5               5   4             5       4
*/
/*construct seperate mirror tree*/
tree *mirror(tree *orig)
{
  if(!orig) return NULL;
  tree *newTree = new tree(orig->data);
  newTree->left = mirror(orig->right);
  newTree->right = mirror(orig->left);
  
  return newTree;
}

/*inplace swapping*/
void swap_node(node n) {
  if(n != null) {
    swap(n.left,n.right);

    swap_node(n.left);
    swap_node(n.right);
  }
}

swap_node(root);
