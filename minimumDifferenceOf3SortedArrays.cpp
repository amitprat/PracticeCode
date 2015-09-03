/*
Taken from : careercup.com
Given 3 Arrays of integer sorted in ascending order, get the sum of minimum difference using one element from each array. 
where a, b, c are the elements from each array. 
diff = |a-b| + |b-c|+|c-a| 
*/

#include<iostream>
using namespace std;
int Abs(int x)
{
	return x>;0?x:-x;
}
int diff(int a, int b)
{
	return Abs(Abs(a)-Abs(b));
}
int min(int a, int b)
{
	return a<b?a:b;
}
int mindiff(int a[], int b[], int c[], int n)
{
	int i=0,j=0,k=0,mindiff;
	mindiff= diff(a[0],b[0])+diff(b[0],c[0])+diff(c[0],a[0]);
	while(1)
	{
		if(mindiff==0) break;
		if( a[i]<=b[j] && a[i] <= c[k] )
			i++;
		else if( b[j] <= a[i] && b[j] <= c[k] )
			j++;
		else k++;
		if(i<n&&j<n&&k<n)
			mindiff=min(mindiff,diff(a[i],b[j])+diff(b[j],c[k])+diff(c[k],a[i]));
		else 
			break;
	}
	cout<<mindiff<<"\n "<<i<<j<<k;
}
int main()
{
	int a[]={1,2,13,15,18};
	int b[]={3,5,10,12,13};
	int c[]={2,4,6,12,13};
	mindiff(a,b,c,5);
}


/*
My Sol
*/
#include        <iostream>
#include        <cmath>
#include        <algorithm>
#include	<climits>
using namespace std;


int minDiff( int a[], int b[], int c[] ,int n) {
    int i=0,j=0,k=0;
    int mn = INT_MAX;
    while(i < n && j < n && k < n) {
        mn = min(mn, abs(a[i]-b[j]) + abs(b[j]-c[k]) + abs(c[k]-a[i]));
        if(mn == 0)     break;
        if(a[i] <= b[j] && a[i] <= c[k])        i++;
        else if(b[j] <= a[i] && b[j] <= c[k])  j++;
        else k++;
    }
    return mn;
}
int main()
{
    int a[]={1,2,13,15,18};
    int b[]={3,5,10,12,13};
    int c[]={2,4,6,12,14};
    cout<< minDiff(a,b,c,5) <<endl;
    return 0;
}
