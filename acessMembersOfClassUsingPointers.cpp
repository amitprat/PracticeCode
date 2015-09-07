#include    <iostream>
using namespace std;

class Calc
{
    public:
    int x,y;
    int mul(int x,int y) { return x*y; }
    int div(int x,int y) { return y?(x/y):-1; }
    int sub(int x,int y) { return x-y; }
    int add(int x,int y) { return x+y; }
};

typedef int (Calc::*fptr)(int,int);
typedef int Calc::*ptr;

int main()
{
    Calc obj;
    fptr op[] = {
        &Calc::mul, &Calc::div, &Calc::sub, &Calc::add
    };

    ptr p= &Calc::x;

    obj.*p = 10;

    p = &Calc::y;

    obj.*p = 20;
    cout<<(obj.*op[0])(1,2)<<" "<<(obj.*op[1])(1,2)<<" "<<(obj.*op[2])(1,2)<<" "<<(obj.*op[3])(1,2)<<endl;
    cout<<obj.x<<" "<<obj.y<<endl;
    return 0;
}
