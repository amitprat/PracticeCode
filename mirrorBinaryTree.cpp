/*
      3                     3                   3
    2   1       -->     1       2     -->     1   2
  4       5               5   4             5       4
*/
tree *mirror(tree *orig)
{
  if(!orig) return NULL;
  
  tree *newTree = new tree(orig->data);
  newTree->left = mirror(orig->right);
  newTree->right = mirror(orig->left);
  
  return newTree;
}
