#include    <iostream>
using namespace std;

struct list{
    int data;
    struct list *next;
    list(int data):data(data),next(NULL){}
};
void print(list *l);
void pushToFront(list *&head,int data) {
    if(!head)   head = new list(data);
    else {
        list *tmp = new list(data);
        tmp->next = head;
        head = tmp;
    }
}
int size(list *l) {
    int sz = 0;
    while(l) { l = l->next; sz++; }
    return sz;
}
void addSameSize(list *l1, list *l2, list *&res, int &carry) {
    if(l1) {
        addSameSize(l1->next,l2->next,res,carry);
        int rem = (l1->data + l2->data + carry)%10;
        carry = (l1->data + l2->data + carry)/10;
        pushToFront(res,rem);
    }
}
void addRemaining( list *head, list *cur, list *&result, int &carry) {
    if(head != cur) {
        addRemaining(head->next,cur,result,carry);
        int rem = (head->data + carry)%10;
        carry = (head->data + carry)/10;
        pushToFront(result,rem);
    }
}
void addList(list *l1, list *l2, list *&result)
{
    int sz1 = size(l1);
    int sz2 = size(l2);
    int carry = 0;
    if(sz1 == sz2)  addSameSize(l1,l2,result,carry);
    else {
        int diff = 0;
        if(sz1 < sz2)  { swap(l1,l2); diff = sz2-sz1; }
        else diff = sz1 - sz2;
        list *old = l1;
        while(diff--)   l1 = l1->next;
        addSameSize(l1,l2,result,carry);
        addRemaining(old,l1,result,carry);
    }
    if(carry)   pushToFront(result,carry);
}
void print( list *l) {
    cout<<"List : ";
    while(l) {
        cout<<l->data<<" ";
        l = l->next;
    }
    cout<<endl;
}
int main()
{
    list *l1 = new list(9);
    l1->next = new list(9);

    list *l2 = new list(9);
    l2->next = new list(9);
    l2->next->next = new list(8);

    list *result=NULL;
    addList(l1,l2,result);
    print(l1);
    print(l2);
    print(result);
    return 0;
}
