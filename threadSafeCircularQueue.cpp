/*
  Implement thread-safe circular queue that has 2 methods Read & Write n bytes. 

The entire design and implementation was open for discussion. 

Discussion went for locking, multi threading, boundary cases, all sets of issues related to multi threading..it was quite intense..
*/

#include    <iostream>
#include    <pthread.h>
#define defaultSize 10
using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

template <class T>
class CircularQueue
{
    int size;
    T *array;
    int front;
    int rear;
    int capacity;

    public:
    CircularQueue(int capacity = defaultSize) {
        this->capacity = capacity;
        array = new T[capacity];
        size = 0;
        front = rear = -1;
    }
    ~CircularQueue() {
        delete[] array;
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ( (rear+1)%capacity == front);
    }
    bool push(T item) {
        pthread_mutex_lock(&mutex);
        if(isFull())  {
            cout<<"Overflow while pushing element "<<item<<"... \n";
            pthread_mutex_unlock(&mutex);
            return false;
        }
        array[ ( rear = (rear+1) % capacity ) ] = item;
        if( front == -1 )
            front = rear;
        size++;
        pthread_mutex_unlock(&mutex);
    }
    T pop() {
        pthread_mutex_lock(&mutex);
        if(isEmpty()) {
            cout<<"Underflow ..\n";
            pthread_mutex_unlock(&mutex);
            return T();
        }
        T item = array[front];
        if( front == rear )
            front = rear = -1;
        else
            front = (front+1) % capacity;
        size--;
        pthread_mutex_unlock(&mutex);
        return item;
    }
    T peek() {
        pthread_mutex_lock(&mutex);
        if(isEmpty()) {
            cout<<"Underflow ..\n";
            pthread_mutex_unlock(&mutex);
            return T();
        }
        pthread_mutex_unlock(&mutex);
        return array[front];
    }
};
void push(CircularQueue<int> &queue) {
    cout<<"Push 5 elements \n";
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
}
void print(CircularQueue<int> q) {
    cout<<"Pop and print Queue \n";
    while(!q.isEmpty()) {
        cout<<q.pop()<<" ";
    }
    cout<<endl;
}
void remove(CircularQueue<int> &q) {
    cout<<"Removed Queue Elements -\n";
    while(!q.isEmpty()) {
        cout<<q.pop()<<" ";
    }
    cout<<endl;
}

int main()
{
    CircularQueue<int> queue(5);
    push(queue);
    queue.push(6);
    cout<<"Queue size is = "<<queue.getSize()<<endl;
    print(queue);
    cout<< "Queue front element is = "<<queue.peek() <<endl;
    cout<< "Queue popped element is = "<<queue.pop() <<endl;
    queue.push(6);
    cout<< "Queue size is = "<<queue.getSize()<<endl;
    print(queue);
    cout<<"Queue size is = "<<queue.getSize()<<endl;
    cout<<"Queue popped element is = "<<queue.pop()<<endl;
    cout<<"Queue popped element is = "<<queue.pop()<<endl;
    push(queue);
    print(queue);
    remove(queue);
    print(queue);
    return 0;
}

