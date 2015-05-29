
void find(tree *root, tree *&pred, tree *&succ, int key) {
  if(!root) return;
  
  if(root->data == key) {
    if(root->right) succ = min(root->right);
    if(root->left)  pred = max(root->left);
    return;
  }
  
  if(key < root->data) {
    suc = root;
    find(root->left,pred,succ,key);
  } else {
    pred = root;
    find(root->right,pred,succ,key);
  }
}
