/*taken from geeksforgeeks*/
struct Node* sortedListToBSTRecur(struct Node **head_ref, int n)
{
    /* Base Case */
    if (n <= 0)
        return NULL;
 
    /* Recursively construct the left subtree */
    struct Node *left = sortedListToBSTRecur(head_ref, n/2);
 
    /* head_ref now refers to middle node, make middle node as root of BST*/
    struct Node *root = *head_ref;
 
    // Set pointer to left subtree
    root->prev = left;
 
    /* Change head pointer of Linked List for parent recursive calls */
    *head_ref = (*head_ref)->next;
 
    /* Recursively construct the right subtree and link it with root
      The number of nodes in right subtree  is total nodes - nodes in
      left subtree - 1 (for root) */
    root->next = sortedListToBSTRecur(head_ref, n-n/2-1);
 
    return root;
}
