/*
Given a BST, find out the minimum length form root to leaf with sum S. Note that: 
a) Path from root to leaf node. 
b) Sum of node of the path is S. 
c) if multiple such path exist, print minimum length path. 
d) What is advantage of BST rather than BT used for this algorithm, how it improve the performance. in BST, is it required to explore both side ?
*/
/*Solution - 
With a BST we have an added advantage that we know all the nodes on the left is less than the current node and all the nodes on the right are greater than the current node. 

So, while doing a DFS to search for a minLen path in a BST we actually can take informed decision at each node to either go left or right based on the remaining sum to search and hence cutting down the search space in half in average case. This will guarantee finding the minimum length path because - 

1) If current node value is equal to sum and it is a leaf node than we have a complete path. If it is not a leaf then we need to find a zero sum minLen path along one of its subtrees. 

2) If current node value is greater than (or equal to) the remaining sum i.e. value>=(sum-value) then we should search for new sum=(sum-value) in the left sub tree because - if a path exists in the left subtree, it must be the shorter than any possible path in the right subtree, since all nodes at left is smaller than those at right. 

3) Similarly, If current node value is smaller than the remaining sum i.e. value<(sum-value) then we should search for new sum=(sum-value) in the right sub tree because - if a path exists in the right subtree, it must be the shorter than any possible path in the right subtree, since all nodes at right is greater than those at left. 

So, average case complexity will be improved to O(lgn) with a complete BST. However, the worst case complexity will be O(n) in case where we have to search both left and right subtree for the remaining sum.
*/
/*Solution from careercup*/
private int minLenSumPathBST(final TreeNode root, final int sum, final int len) {
    if (root == null) {
        return Integer.MAX_VALUE;
    }

    // find the remaining sum as we are including current node in the current path
    final int remainingSum = sum - root.key;
    // If remaining sum is zero and it is a leaf node then we found a complete path from root to a leaf.
    if (remainingSum == 0 && root.left == null && root.right == null) {
        return len + 1;
    }
    // If remaining sum is less than current node value then we search remaining in the left subtree.
    else if (remainingSum <= root.key) {
        int l = minLenSumPathBST(root.left, remainingSum, len + 1);
        // if search in left subtree fails to find such path only then we search in the right subtree
        if (l == Integer.MAX_VALUE) {
            l = minLenSumPathBST(root.right, remainingSum, len + 1);
        }

        return l;
    }
    // If remaining sum is greater than current node value then we search remaining in the right subtree.
    else {
        int l = minLenSumPathBST(root.right, remainingSum, len + 1);
        // if search in right subtree fails to find such path only then we search in the left subtree
        if (l == Integer.MAX_VALUE) {
            l = minLenSumPathBST(root.left, remainingSum, len + 1);
        }

        return l;
    }
}
/*
Doubt - Why it is necessary to look under right child if the remaining sum is already less than current node value, as every value on its right will always be greater than its own value.

if the remaing value is more than the current node value, the sum can be formed on either side and hence we have to peek at both sides. - Can we optmize this case also for BST ?
        5
    4       6
3               7

if sum = 7, then 7-5 =2 < 5 and hence look only to left.
if sum = 12, look on both sides

T = O(n) 

*/
/*My solution*/
int findPath(tree *root,int sum) {
    if(!root)   return (sum == 0 ? 0 : INT_MAX);
    sum -= root->data;
    if(!sum && !root->left && !root->right) return 0;
    if(sum <= root->data)
        return findPath(root->left,sum);
    else 
        return min( findPath(root->left,sum), findPath(root->right,sum) );
} 

void printPath(tree *root,int sum,vector<int> minPath, vector<int> curPath, int &minlen, int curlen)
{
    if(!root) {
        minlen = 0;
        return;
    }
    sum -= root->data;
    curPath.push_back(root->data);
    if(!sum && !root->left && !root->right) {
        if(curlen < minlen) {
            minlen = curlen;
            minPath = curPath;
            return;
        }
    }
    if( sum <= root->data )
        printPath(root->left,sum,minPath,curPath,minlen,curlen);
    else {
        printPath(root->left,sum,minPath,curPath,minlen,curlen);
        printPath(root->right,sum,minPath,curPath,minlen,curlen);
    }
}

caller - 
printPath(root,sum,minPath,vector(),minlen,0);
