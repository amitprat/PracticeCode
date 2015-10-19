/*
some people are standing in a queue and only even people are selected. Again out of these only even people are selected.This happens until we are left with one.
Find out the position of that person in the original queue.
*/

#include	<iostream>
using namespace std;
/*
In each round, we delete 1 element and 1 element is left inbetween, so 
we mark 1 in each round to adjust the position offset.
+ 1 ( the count of deleted element)

Base case - when n==1, we return 0 as array is 1 index based.
*/
int pos(int n) {
	if(n==1)	return 1;
	return (1+pos(n-1))%n+1;
}
int main() {
	int n = 5;
	cin>>n;
	int p = pos(n);
	cout<<p<<endl;
	return 0;
}
