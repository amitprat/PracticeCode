#include    <iostream>
using namespace std;

class Sol
{
    int a,b;
    public:
        Sol(int a,int b) {
            this->a = a;
            this->b = b;
        }
};
int main()
{
    Sol obj(10,208);
    void *ptr = (void *)&obj; //we can typecast anything to void pointer
    cout<<*(int *)ptr<<endl;  //point to first data member of class
    cout<<*(int *)(ptr+4)<<endl;  //increase pointer by 4 assuming int size to be 4 to point to next data member
    return 0;
}
