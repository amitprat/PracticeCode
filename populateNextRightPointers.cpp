#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
  node(int data,struct node *left=NULL, struct node *right=NULL, struct node *nr=NULL) {
    this->data = data;
    this->left = left;
    this->right = right;
    this->nextRight = nr;
  }
};
void connectRecur(struct node* p)
{
  if (!p)
    return;
  if (p->left)
    p->left->nextRight = p->right;
  if (p->right)
    p->right->nextRight = (p->nextRight)? p->nextRight->left: NULL;
  connectRecur(p->left);
  connectRecur(p->right);
}
void connect (struct node *p)
{
    p->nextRight = NULL;
    connectRecur(p);
}
void connectIter(struct node *root)
{
    queue<struct node *> q;
    q.push(root);
    while(!q.empty())
    {
        int sz = q.size();
        node *nr = NULL;
        while(sz--) {
            root = q.front(); q.pop();
            root->nextRight = nr;
            nr = root;
            if(root->right) q.push(root->right);
            if(root->left)  q.push(root->left);
        }
    }
}
node *getNextRight(node *root)
{
    node *nr = root->nextRight;
    while(nr) {
        if(nr->left)
            return nr->left;
        if(nr->right)
            return nr->right;
        nr = nr->nextRight;
    }
    return NULL;
}
void connectR(node *root)
{
    if(!root)   return;
    connectR(root->nextRight);
    if(root->left) {
        if(root->right) {
            root->left->nextRight =  root->right;
            root->right->nextRight = getNextRight(root);
        } else
            root->left->nextRight = getNextRight(root);
        connectR(root->left);
    } else if(root->right) {
        root->right->nextRight = getNextRight(root);
        connectR(root->right);
    } else
        connectR(getNextRight(root));
}
/* Driver program to test above functions*/
int main()
{

  /* Constructed binary tree is
            10
          /    \
        8        2
      /            \
    3                6
  */
  node *root = new node(10);
  root->left        = new node(8);
  root->right       = new node(2);
  root->left->left  = new node(3);
 // root->left->right  = new node(4);
  //root->right->left  = new node(5);
  root->right->right  = new node(6);
  // Populates nextRight pointer in all nodes
  connectR(root);

  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->right->data,
        root->right->right->nextRight? root->right->right->nextRight->data: -1);

  return 0;
}
