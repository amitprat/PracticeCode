#include <iostream>

using namespace std;

/*
    str a;
    mean
    char *a;

    it replaces "str" with char *;
*/
typedef char * str;

int mul(int a,int b) {return a*b;}
int sum(int a,int b) { return a+b; }
/*
this typedef means, if
    func fptr = sum;
means -
    int (*fptr)(int,int) = sum;
*/
typedef int (*func)(int a,int b);
typedef int (*fsm)(int,int);    //just shorthand

/*Receiving function pointer*/
int guess( int (*fptr)(int,int), int a,int b)
{
    return fptr(a,b);
}

/*This uses the typedef to represent easy shorthand notation*/
void func_call(func a,func b)
{
    cout<<"In function fund_call -:"<<endl;
    cout<<"mul :"<<a(1,2)<<"\tsum :"<<b(1,2)<<endl;
}

/*Function pointer can be used to simulate fsm also*/
void func_call1(func list[])
{
    cout<<"In function fund_call1 -:"<<endl;
    cout<<"mul :"<<list[0](1,2)<<"\tsum :"<<list[1](1,2)<<endl;
}
int main()
{
    /*function pointer wihtout typedef*/
    int (*s_fptr)(int ,int) = sum;
    int (*m_fptr)(int,int); //just another way of writing it
    m_fptr = mul;
    cout<< "Sum : "<<s_fptr(10,23)<<endl;
    cout<< "Mul : "<<m_fptr(2,3)<<endl;

    /*Passing function as function ptr to another function without typedef */
    cout<<"Guess output : sum "<<guess(&sum,2,4)<<endl;
    cout<<"Guess output : mul "<<guess(&mul,2,4)<<endl;

    /*Use typedef */
    func a = sum;
    cout<<a(010,0020)<<endl; //Octoal sum , 010 = 8 in decimal, 020 - 16
    cout<<a(1 , 020)<<endl;

    fsm machine[2] = { mul, sum };
    cout<<"mul :"<<machine[0](1,2)<<"\tsum :"<<machine[1](1,2)<<endl;
    func_call(mul,sum);
    func_call1(machine);
    return 0;
}
