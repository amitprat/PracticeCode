
tree *mirror(tree *orig)
{
  if(!orig) return NULL;
  
  tree *newTree = new tree(orig->data);
  newTree->left = mirror(orig->right);
  newTree->right = mirror(orig->left);
  
  return newTree;
}
