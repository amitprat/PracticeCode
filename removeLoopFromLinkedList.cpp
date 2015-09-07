struct node *removeLoop(struct node *head) {
    struct node *slow,*fast;
    slow = fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    fast = head;
    while(fast->next != slow->next) { fast = fast->next; slow = slow->next; }   //find the common point i.e start of the loop
    slow->next = NULL;
    return head;
}
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    /* Create a loop for testing */
    head->next->next->next->next->next->next->next->next = head->next->next->next;

    //removeLoop(head);
    head = removeLoop(head);
    printf("Linked List after removing loop \n");
    printList(head);

    getchar();
    return 0;
}
