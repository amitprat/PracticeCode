/*revsrse linked list, reverse list, reverse list recursively, list reverse recursive*/


#include	<stdio.h>
#include	<stdlib.h>

typedef struct _node
{
	int num;
	struct _node *next;
}node;

node *create_linked_list(node *orig)
{
	int i=1;
	node *cur = NULL;
	while(i<5)
	{
		node *new_node = malloc(sizeof(node));
		new_node->num = i++;
		new_node->next = NULL;
		if(orig == NULL)
			orig =cur =  new_node;
		else
		{
			cur->next = new_node;
			cur= cur->next;
		}
	}
	return orig;

}
void traverse(node *root)
{
	while(root)
	{
		printf("%d\t",root->num);
		root = root->next;
	}
}
node *reverse(node *prev,node *root,node **orig)
{
	if(root == NULL)
	{
		*orig = prev;
		return prev;
	}
	root = reverse(root,root->next,orig);
	root->next = prev;
	return prev;
}
node *reverse_linked_list(node *orig)
{
	node *root = NULL;
	reverse(NULL,orig,&root);
	return root;
}
node *reverse_linked_list_iter(node *orig)
{
	node *root,*temp,*temp1;
	root = NULL;
	temp = temp1 = orig;
	while(temp1)
	{
		temp = temp1;
		temp1 = temp->next;
		temp->next = root;
		root = temp;
	}
	return temp;
}
node *reverseList(node *root, node **head) {
    if(!root || !root->next) { *head = root; return root;}
    node *n = reverseList(root->next,head);
    n->next = root;
    return root;
}
void tailRecur(node *root,node **prev) {
    if(!root) return;
    if(!root->next) {root->next = *prev;*prev = root; return; }
    node *next = root->next;
    root->next = *prev;
    *prev = root;
    tailRecur(next,prev);
}
void recReverse(node **root) {
    if(!*root)  return;
    node *first = *root;
    node *rest = first->next;
    if(!rest)   return;
    recReverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *root = rest;
}
int main()
{
	node *orig = NULL;
	printf("\n original linked list : \n");
	orig = create_linked_list(orig);
	traverse(orig);
	//orig = reverse_linked_list(orig);
	//orig = reverse_linked_list_iter(orig);
	node *head = NULL;
	//orig = reverseList(orig,&head);
	//orig->next = NULL;
	//tailRecur(orig,&head);
	recReverse(&orig);
	printf("\n reverse linked list : \n");
	traverse(orig);
	printf("\n");
	return 0;
}
