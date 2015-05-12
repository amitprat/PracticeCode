
/*
  Check If two Tree are mirror images of each other. Content may not be same but tree looks alike.
  
      2                   
    1   3     
  4       5
  
  recursive(1,3) -->recursive(4,5) --> return true 
                |-->recursive(NULL,NULL) -->return true
  return true
*/
bool isMirror( tree *root )
{
  if(!tree) return true;
  
  return isMirrorUtil(root->left,root->right);
}

bool isMirrorUtil(tree *t1, tree *t2)
{
  if(!t1 && !t2)  return true;
  
  if(!t1 || !t2)  return false;
  
  return isMirrorUtil(t1->left,t2->right) &&
          isMirrorUtil(t1->right,t2->left);
}
