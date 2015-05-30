/*
Given an array of ints, return a string identifying the range of numbers

Example
Input arr - [0 1 2 7 21 22 1098 1099]
Output - "0-2,7,21-22,1098-1099"
*/
//Reference : http://www.careercup.com/question?id=5738850972336128
#include    <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 7, 21, 22, 1098, 1099};
    int n = sizeof(arr)/sizeof(arr[0]);

    int start = arr[0],end,count = 0;
    for(int i=1;i<n;i++) {
        if(arr[i]-1 == arr[i-1])
            end = arr[i], count = count+1;
        else {
            if(count)
                cout<<"["<<start<<"-"<<end<<"]"<<" ";
            else
                cout<<start<<" ";

            count = 0;
            start = arr[i];
        }
    }
    if(count)   cout<<"["<<start<<"-"<<end<<"]"<<" ";
    else cout<<start<<endl;
    return 0;
}
