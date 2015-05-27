#include    "gprot.h"
/*
Tags - 
Overload ostream operator to print the complex data structure to ostream through << operator
Overload istream operator to input data to complex data structure though input stream reader >> operator
Copy Constructor Example
Object creation different ways 
*/
class Point
{
    int x;
    int y;
    string *info;
    friend ostream &operator<<(ostream &o,Point &p);
    friend istream &operator>>(istream &i,Point &p);
public:
    Point(int x_=0,int y_=0){
        x = x_;
        y = y_;
        info = new string("Default");
    }
    Point(const Point& obj)
    {
        x = obj.x;
        y = obj.y;
        info = new string();
        info = obj.info;
    }
    void changeInfo(char *hello)
    {
        delete info;
        info = new string(hello);
    }
};

ostream &operator<<(ostream &o,Point &p)
{
    o<<"x : "<<p.x<<", y :"<<p.y<<endl;
    o<<"info :"<<*(p.info)<<endl;
    return o;
}
istream &operator>>(istream &i,Point &p)
{
    i>>p.x>>p.y;
    char p1[32];
    i>>p1;
    p.info = new string(p1);
    return i;
}
int main()
{
    Point p1(10,15);
    cout<<p1;
    Point p2 = p1;
    cout<<p2;
    Point p3 = {1,2};
    p3.changeInfo("Hello");
    cout<<p3;
    Point p4;
    cin>>p4;
    cout<<p4;
    return 0;
}
