/*
Find element in almost sorted array.
Source : http://www.careercup.com/question?id=6315677910564864
An array consist of elements whose difference is positive or negative 1. I have to find the given elements without using linear search. 
Say 
Int arr[]={1,2,3,4,3,4,5,6,7 

To find : 6 
. 
Please provide some one code/algorithm for this problem.
*/

/*
Solution - 
The answer is skipping. If you're starting at 1, and you're looking for 6, then you know that the best case scenario is the next five values increase by one each. So you skip 5 and check that value. You repeat the same step. It turns out the value at that position is 4. The best case scenario is the next two values increase by one each. So you jump two positions and there's your number.

The key is to figure out at each position how far the goal value is from that position's value and jump ahead by as many steps.

Is that true that your code in worst case needs n/2+1 steps to find the answer?
*/
#include    <iostream>
#include    <stdlib.h>
#include    <time.h>
using namespace std;

int find(int a[],int n,int item) {
    int d = item - a[0];
    if(d == 0)  return 0;
    if(d <0 || d >= n)  return -1;
    int ret = find(a+d,n-d,item);

    if(ret != -1)   return d+ret;
    return -1;
}
int main(){
    int arr[]={1,2,3,4,3,4,5,6,7};
    srand(time(NULL));
    for(int i=0;i<10;i++) {
        int item = rand()%10;
        cout<< "Element "<<item<<" found at "<<find(arr,sizeof(arr)/sizeof(int),item)<<endl;
    }
    return 0;
}
