/*
Largset Indepedent Set -
Given a Binary Tree, find size of the Largest Independent Set(LIS) in it. A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.
For example, consider the following binary tree. The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.



A Dynamic Programming solution solves a given problem using solutions of subproblems in bottom up manner. Can the given problem be solved using solutions to subproblems? If yes, then what are the subproblems? Can we find largest independent set size (LISS) for a node X if we know LISS for all descendants of X? If a node is considered as part of LIS, then its children cannot be part of LIS, but its grandchildren can be. Following is optimal substructure property.

1) Optimal Substructure:
Let LISS(X) indicates size of largest independent set of a tree with root X.

     LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
                     (sum of LISS for all children of X) }
                     
  */
  
  /*Exponential Time complexity*/
  int liss(tree *root) {
    if(!root) return 0;
    int excl = liss(root->left) + liss(root->right);
    int incl = 1;
    if(root->left)
      incl += liss(root->left->left) + liss(root->left>right);
    if(root->right)
      incl += liss(root->right->left) + liss(root->right->right);
    
    return max(incl,excl);
  }
  
  /*Dynamic Programming Solution T = O(n)*/
  int liss( tree *root ) {
    if(!root) return 0;
    if(root->lissVal) return root->lissVal;
     int excl = liss(root->left) + liss(root->right);
    int incl = 1;
    if(root->left)
      incl += liss(root->left->left) + liss(root->left>right);
    if(root->right)
      incl += liss(root->right->left) + liss(root->right->right);
    root->lissVal = max(incl,excl);
    return max(incl,excl);
  }
