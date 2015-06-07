/*
What does an iterator in C++ point to in case of a vector vs. list. Where would it point to if the prior links are deleted in the list? In case of a vector if it points to a specific index, where would it point to if the prior indexes are deleted?
*/
#include    <iostream>
#include    <vector>
#include    <list>
using namespace std;

int main()
{
    list<int> l = {1,2,3,4,5};
    vector<int> v = {1,2,3,4,5};
    list<int>::iterator lit = l.begin();
    vector<int>::iterator vit = v.begin();
    cout<<"Vector operation - \n";
    for(;vit != v.end();) {
        cout<<*vit<<" ";
        v.erase(vit);
    }
    cout<<"\nagain - \n";
    for(vit=v.begin();vit != v.end();) {
        cout<<*vit<<" ";
        v.erase(vit);
    }
    cout<<"List operator - \n";
    for(;lit != l.end();) {
        cout<<*lit<<" ";
        l.erase(lit++);
    }
    cout<<"\nagain - \n";
    for(lit=l.begin();lit != l.end();) {
        cout<<*lit<<" ";
        l.erase(lit++);
    }
    cout<<endl;
    return 0;
}
