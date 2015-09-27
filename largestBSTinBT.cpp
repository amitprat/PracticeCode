/*
Ref : http://articles.leetcode.com/2010/11/largest-binary-search-tree-bst-in_22.html
Largest BST in a BT

A Top-down Approach:
The largest BST subtree solution requires a bottom-up approach where the min and max values are passed bottom-up. The main reason of doing this is when one of the nodes does not satisfy the BST properties, all subtrees above (which includes this node as well) must also not satisfy the BST requirements.

However, finding the largest BST requires a slightly different approach. We want the largest BST by including as many nodes as possible while we traverse down the tree, as long the current BST constraint is maintained. What happens when we see a node that breaks the current BST constraint? The answer is we can simply exclude it. However, we must treat it as an entirely new tree (ie, find in that tree if there is another larger BST). As you can see, we are passing the min and max values top-down, while the nodes count are passed bottom-up (Read my previous post to know how).

As a tree is defined recursively using its left and right subtrees, you could not simply return root node of the largest BST as this would include all of its subtrees. You would need to create copies of the subtrees or delete nodes from the original binary tree. My code below create copies of the subtrees. As it does not handle the deletion of trees, some of the subtrees that are created dynamically will eventually be memory-leaked. Handling this problem would require more complicated code. I will not demonstrate how to do it here since this post is to illustrate the algorithm.
*/


// Find the largest BST in a binary tree.
// This code does not delete dynamically-allocated nodes,
// so memory will be leaked upon exit.
// The min and max values are passed top-down to check if
// including a node satisfies the current BST constraint.
// The child nodes are passed bottom-up to be assigned 
// to its parent.
// Returns the total number of nodes the child holds.
int findLargestBST(BinaryTree *p, int min, int max, int &maxNodes, 
                   BinaryTree *& largestBST, BinaryTree *& child) {
  if (!p) return 0;
  if (min < p->data && p->data < max) {
    int leftNodes = findLargestBST(p->left, min, p->data, maxNodes, largestBST, child);
    BinaryTree *leftChild = (leftNodes == 0) ? NULL : child;
    int rightNodes = findLargestBST(p->right, p->data, max, maxNodes, largestBST, child);
    BinaryTree *rightChild = (rightNodes == 0) ? NULL : child;
    // create a copy of the current node and 
    // assign its left and right child.
    BinaryTree *parent = new BinaryTree(p->data);
    parent->left = leftChild;
    parent->right = rightChild;
    // pass the parent as the child to the above tree.
    child = parent;
    int totalNodes = leftNodes + rightNodes + 1;
    if (totalNodes > maxNodes) {
      maxNodes = totalNodes;
      largestBST = parent;
    }
    return totalNodes;
  } else {
    // include this node breaks the BST constraint,
    // so treat this node as an entirely new tree and 
    // check if a larger BST exist in this tree
    findLargestBST(p, INT_MIN, INT_MAX, maxNodes, largestBST, child);
    // must return 0 to exclude this node
    return 0;
  }
}
 
BinaryTree* findLargestBST(BinaryTree *root) {
  BinaryTree *largestBST = NULL;
  BinaryTree *child;
  int maxNodes = INT_MIN;
  findLargestBST(root, INT_MIN, INT_MAX, maxNodes, largestBST, child);
  return largestBST;
}
