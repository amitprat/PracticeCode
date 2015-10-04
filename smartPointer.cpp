/*
smartPointer
*/
template <class T>
class SmartPointer
{
  T *ptr;
  int count;
  
  public:
  SmartPointer(T *ptr = NULL) {
    this->ptr = ptr;
    count++;
  }
  SmartPointer(const SmartPointer &ptr) {
    this->ptr = ptr.ptr;
    this->count = ptr.count;
    count++;
  }
  ~SmartPointer() {
    count--;
    if(!count)  delete ptr;
  }
  SmartPointer & operator = (const SmartPointer &sptr) {
    if( ptr != sptr.ptr ) {
      count--;
      if(!cout) delete ptr;
      ptr = sptr.ptr;
      count = sptr.count;
      count++;
    }
    return *this;
  }
  T & operator *() {  
    return *ptr;
  }
  T * operator ->() {
    return ptr;
  }
};
int main()
{
    SmartPointer<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    SmartPointer<int> ptr1;
    ptr1 = ptr; //assignment operation
    SmartPointer<int> ptr2 = ptr; //copy constructor
    return 0;
}
