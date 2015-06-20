#include    <iostream>
#include    <unordered_map>
using namespace std;
template <class T>
struct Node
{
    T data;
    struct Node *prev,*next;
    Node(T data,struct Node *p=NULL,struct Node *n=NULL) {
        this->data = data;
        prev = p, next = n;
    }
};

template <class T>
class DLL
{
    Node<T> *head,*tail;
public:
    DLL<T>(){ head = tail = NULL;}
    void push_back(T data)
    {
        if(head == NULL)
            head = tail = new Node<T>(data);
        else {
            tail->next = new Node<T>(data);
            tail = tail->next;
        }
    }
    void push_back(Node<T> *node)
    {
        if(head == NULL)
            head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }
    }
    void push_front(Node<T> *node)
    {
        if(head == NULL)
            head = tail = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void pop_back()
    {
        if(head == NULL)    return;
        else if(head == tail)    {
            delete head;
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            delete tail->prev->next;
            tail->prev->next = NULL;
        }
    }
    void moveToFront(Node<T> *n)
    {
        if(head == n)   return;
        n->prev->next = n->next;
        if(n->prev->next == NULL)
            tail = n->prev;

        n->next = head;
        head->prev = n;
        head = n;
    }
    void print()
    {
        Node<T> *tmp = head;
        while(tmp != tail) {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
    }
    ~DLL<T>()
    {
      while(head != tail) {
            head = head->next;
            delete head->prev;
            head->prev = NULL;
        }
        head = tail = NULL;
    }
};
template <class T>
class LRU
{
    DLL<T> object;
    unordered_map<T, Node<T> *> table;
    int size,capacity;
public:
    LRU(int n):capacity(n)
    {
        size = 0;
    }
    void reference(T pgNum)
    {
        if( table.find(pgNum) == table.end() ) {
           Node<T> *node = new Node<T>(pgNum);
           object.push_front(node);
           table[pgNum] = node;
           size++;
        } else {
            if(size == capacity)
                object.pop_back();
            object.moveToFront(table[pgNum]);
        }
    }
    void print()
    {
        object.print();
    }
};
int main()
{
    LRU<int> object(4);
    object.reference(1);
    object.reference(2);
    object.reference(3);
    object.reference(1);
    object.reference(4);
    object.reference(5);
    //object.reference(1);
    //object.reference(1);
    //object.reference(1);
    object.print();
    return 0;
}
