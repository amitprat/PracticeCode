//taken from - https://sites.google.com/site/spaceofjameschen/home/c/access-private-members-of-base-class
#include <iostream>

using namespace std;

class A
{
private:
    int x;
public:
    A(int x) { this->x = x;}  
    int GetX() const {return x; }

    friend class B;
};

class B: public A
{
public:
    B(int x): A(x - 1) {}

    void UseBasePrivateX(){
        cout << A::x << endl;
    }
};

int main()
{
    B b(3);

    b.UseBasePrivateX();
    cout << b.GetX() << endl;


 return 0;
}
