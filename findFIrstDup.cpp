/*
Find first duplicate in an array where: 
Array has N integers ranging from 0 to n-1. 
(Multiple elements can be duplicated multiple times) 
in time complexity O(n) and space complexity O(1)

Sol :
1) This problem is quite easy, if we can use extra space. We can take hash or checker bit to test the reoccurance.

2) With constant space, we can use the marker postion by negating it.
But negation works only when numbers are from 1-n-1 or 1-n as negation of zero is same as zero. 
  - we can solve this problem by having an extra flag for marking zero
  - we can add N instead of negating it.
*/

#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

int fun1(int a[],int n) {
  bool isZeroSet = false;
  for(int i=0;i<n;i++) {
    if(a [ abs(a[i]) ] > 0 )
      a[ abs(a[i]) ] *= -1;
    else if( a[abs(a[i])] == 0 && !isZeroSet)
      isZeroSet = true;
    else {
      return a[i];
    }
  }
  return -1;
}

/*number are from 0-n-1*/

int fun2(int a[],int n) {
  for(int i=0;i<n;i++) {
    if( a [a[i]%n] >= n )
      return a[i]%n;
    else
      a[a[i]%n] += n;
  }
  return -1;
}

int fun3(int a[],int n) {
  int firstPos = INT_MAX;
  int i = 0;
  while(i < n) {
    if( a[i] != a[ a[i] ] )
      swap(a[i],a[a[i]]);
    else {
      if(i != a[i] )
        firstPos = min( firstPos, a[i] );
      i++;
    }
  }
  return firstPos;
}

int main() {
    int a[] = {0,5,1,3,5,4,2};
    cout<< fun2(a,7) << endl;
    return 0;
}
