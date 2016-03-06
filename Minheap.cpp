#include "Minheap.h"
template <class T>
int Minheap::left(int i)
{
    return 2*i+1;
}
template <class T>
int Minheap::right(int i)
{
    return 2*i+2;
}
template <class T>
int Minheap::parent(int i)
{
    return i/2;
}
template <class T>
void Minheap::heapify(int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);
    if(heap[l] < heap[i] && l<cur_size)
        smallest = l;
    if(heap[r] < heap[smallest] && r<cur_size)
        smallest = r;
    if(smallest != i)
    {
        swap(&heap[i],&heap[smallest]);
        heapify(heap,smallest,cur_size);
    }
}
template <class T>
void Minheap::build_max_heap()
{
    int i=0;
    for(i=cur_size/2; i>=0; i--)
        heapify(heap,i,cur_size);
}
template <class T>
bool Minheap::Minheap::isFull()
{
    return (cur_size == heap_size);
}
template <class T>
void Minheap::resizeHeap()
{
    T *newheap = new T[heap_size*2];
    for(int i=0; i<heap_size; i++)
        new_heap[i] = heap[i];
    heap_size *= 2;
    delete[] heap;
    heap = newheap;
}
template <class T>
Minheap::Minheap(int sz = HEAP_SIZE) : heap_size(sz)
{
    a = new T[sz];
    cur_size = 0;
}
template <class T>
Minheap::~Minheap()
{
    delete T;
}
template <class T>
bool Minheap::isEmpty()
{
    return (cur_size == 0);
}
template <class T>
void Minheap::push(T key)
{
    if( isFull() )
        resizeHeap();
    cur_size++;
    heap[cur_size] = MAX;
    decreaseKey(key);
    cur_size++;
}
template <class T>
T Minheap::top()
{
    return a[0];
}
template <class T>
void Minheap::pop()
{
    heap[0] = heap[cur_size-1];
    cur_size--;
    decrease_key(--cur_size);
}
template <class T>
T Minheap::extractMin()
{
    if(cur_size < 0)
        return -1;
    T max_ = top();
    pop();
    return max_;
}
template <class T>
void Minheap::decreaseKey(int k)
{
    if(k > heap[i])
        return;
    heap[i] = k;
    while(i>0 && heap[parent(i)] < heap[i])
    {
        swap(&heap[i],&heap[parent(i)]);
        i = parent(i);
    }
}
