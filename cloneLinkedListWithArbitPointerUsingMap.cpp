#include    <iostream>
#include    <unordered_map>
using namespace std;


struct list
{
    int data;
    struct list *next,*arbit;
    list(int d,struct list *n=NULL,struct list *a=NULL) {
        this->data = d;
        this->next = n;
        this->arbit = a;
    }
    void setArbit(list *root,list *arbit) {
        root->arbit = arbit;
    }
};

void print(list *root) {
    while(root) {
        cout<<root->data<<" "<<(root->next?root->next->data:-1)<<" "<<(root->arbit?root->arbit->data:-1)<<endl;
        root = root->next;
    }
}

void del(list *root)
{
    list *next;
    while(root) {
        next = root->next;
        delete root;
        root = next;
    }
}

list *clone(list *root) {
    list *head=NULL,*org=NULL;
    unordered_map<list *,list *> map;
    while(root) {
        if(!head)	head = org = new list(root->data,NULL,root->arbit);
        else {
        	org->next = new list(root->data,NULL,root->arbit);
        	org = org->next;
        }
        map[root] = org;
        root = root->next;
    }
    org = head;
    while(org) {
        org->arbit = map[org->arbit];
        org = org->next;
    }
    return head;
}
int main()
{
    list *root = new list(1);
    root->next = new list(2);
    root->next->next = new list(3);
    root->next->next->next = new list(4);
    root->next->next->next->next = new list(5);
    root->arbit = root->next;
    root->next->arbit = root->next->next->next;
    root->next->next->arbit = root->next->next->next;
    root->next->next->next->arbit = root->next->next->next->next;
    cout<<"old list -- \n";
    print(root);
    list *newlist = clone(root);
    del(root);
    cout<<"old list deleted \n";
    cout<<"new cloned list -- \n";
    print(newlist);
    del(newlist);
    cout<<"new list deleted \n";
    return 0;
}
