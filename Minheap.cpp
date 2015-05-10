#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#define DEFAULT_SIZE    10
using namespace std;

template <class T>
class Minheap
{
public:
    T *arr;
    int size;
    int capacity;
    int left(int i) {return 2*i +1; }
    int right(int i) { return 2*i + 2 ;}
    int parent(int i) { return i/2; }
    void heapify(int i=0)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < size && arr[l] < arr[smallest])
            smallest = l;
        if(r < size && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i) {
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }
    Minheap(int size=DEFAULT_SIZE)
    {
        arr = new T[capacity=size];
        this->size = 0;
    }
    Minheap(T arr[], int size) {
        size = 0;
        arr = new T[capacity=size];
        for(int i=0;i<size;i++)
            this->arr[i] = arr[i];
        heapify();
    }
    void push(T item) {
        if(size >= capacity) return;
        arr[size++] = item;
        heapify();
    }
    T extractMin() {
        T top = arr[0];
        arr[0] = arr[size-1];   size--;
        heapify();
        return top;
    }
    void decreaseKey(int pos, T key)
    {
        if( arr[pos] < key )
            return;
        arr[pos] = key;
        while(pos > 0 && arr[parent(pos)] > arr[pos]) {
            swap(arr[parent(pos)],arr[pos]);
            pos=parent(pos);
        }
    }
    void insert(T item) {
        arr[size++] = item;
        decreaseKey(size-1,item);
    }
    T getMin()  { return arr[0]; }
    bool empty() { return (size<=0); }
    bool full() { return (size == capacity);}
};
