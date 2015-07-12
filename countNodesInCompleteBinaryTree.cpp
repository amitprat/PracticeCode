 /*Question taken from leetcode.com
 Complete Binary Tree - All nodes are completely filled up except last level nodes which left aligned
 */
 int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int lh = height(root->left,true);
        int rh = height(root->right,false);
        if(lh == rh)    return (1<<lh) + (1<<rh) - 1;
        else {
            int lr = height(root->right,true);
            if(lh == lr)
                return (1<<lh) + countNodes(root->right);
            else
                return (1<<lr) + countNodes(root->left);
        }
    }
