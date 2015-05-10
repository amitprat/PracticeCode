/*
write a merge sort algorithm to sort a file which can't be loaded into the memory.
Assume you can only load 10 items in the memory at a time and there are 100 items to sort.
*/
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

void ksortfile(string file)
{
    ifstream in(file);
    ofstream out(file,ios_base::in);
    int number;
    int chunkSize = 10;
    int arr[chunkSize];
    Minheap<int> heap(chunkSize);

    while(!in.eof()) {
        int i = 0;
        int number;
        while(i < chunkSize && in>>number) {
            arr[i++] = number;
        }
        sort(arr,arr+i);
        int k = 0;
        while(k < i) {
            out << arr[k++]<< " ";
        }
    }

    in.close();
    out.close();

    in.open(file);
    out.open(file,ios_base::in);
    int i = 0;
    while(i < chunkSize && in>>number)   {
        heap.push(number);
        i++;
    }
    while(!heap.empty()) {
        int item = heap.extractMin();
        if(in>>number)
            heap.insert(number);
        out << item << " ";
    }
    out.close();
    in.close();
}
int main(int argc,char *argv[])
{
    string file("numbers.txt");
    ksortfile(file);

    int num;
    ifstream in(file);
    while(in>>num) {
        cout<<num<<" ";
    }
    in.close();
    cout<<endl;
    return 0;
}
