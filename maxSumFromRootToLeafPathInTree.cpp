Given a binary tree, find out the maximum sum of value from root to each leaf.


int find_Max(Node *root){
  if (root==null)
    return 0;
  else
    return max((find_Max(root->left), find_Max(root->right))+root->value;
}

void find(Node *root,int sum,int &maxSum) {
  if(!root) { maxSum = max(maxSum, sum); return; }
  find(root->left,sum_root->data,maxSum);
  find(root->right,sum_root->data,maxSum);
}
