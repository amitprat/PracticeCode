/*
Reference : http://www.careercup.com/question?id=5120588943196160
Three points are given A(x1, y1), B(x2, y2), C(x3, y3). Write a method returning an array of points (x, y) inside the triangle ABC.


Way to test a point (p,q) is within a triangle is by checking if the area of the triangle is equal to the sum of the three triangles formed with (p,q). 

Now to return points within a triangle 
- Get a point (p,q) which is within the triangle 
- Use flood-fill to generate next points by using the above mentioned condition

area of traingle : area = |1/2 * ( x1(y2−y3)+x2(y3−y1)+x3(y1−y2) )|
*/

#include <iostream>
#include <set>
#include <utility>
#include <cstdlib>
using namespace std;

double t_area;		//area of the triangle given
set<pair<int, int> > res;	//set of pairs, only unique pairs are stored

double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	double val = abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));	
	val = val / 2.0;
	return val;
}
	
bool is_inside(int x[], int y[], int a,int b)
{	
	double ar = 0;
	ar += area(x[0], y[0], x[1], y[1], a, b);
	ar += area(x[0], y[0], a, b, x[2], y[2]);
	ar += area(a, b, x[1], y[1], x[2], y[2]);	
	if ( ar == t_area)
		return true;
	else
		false;
}

void find_pts(int x[], int y[], int a, int b)
{
	if (res.count( make_pair(a,b)) == 1) // if (res.find( make_pair(a,b) != res.end() ) ) return false;
		return;
	cout<<a<<" "<<b<<endl;
	res.insert( make_pair(a,b));
	
	if (is_inside(x, y, a-1, b-1))
		find_pts(x, y,a-1 , b-1);
	if (is_inside(x, y, a, b-1))
		find_pts(x, y,a , b-1);
	if (is_inside(x, y, a+1, b-1))
		find_pts(x, y,a+1 , b-1);
	if (is_inside(x, y, a-1, b))
		find_pts(x, y,a-1 , b);
	if (is_inside(x, y, a+1, b))
		find_pts(x, y,a+1 , b);
	if (is_inside(x, y, a-1, b+1))
		find_pts(x, y,a-1 , b+1);
	if (is_inside(x, y, a, b+1))
		find_pts(x, y,a , b+1);
	if (is_inside(x, y, a+1, b+1))
		find_pts(x, y,a+1 , b+1);
}

int main()
{
	int x[3], y[3];
	
	for (int i=0;i<;3;i++)
	{
		cin>>x[i]>>y[i];
	}
	t_area = area(x[0], y[0], x[1], y[1], x[2], y[2]);
	cout<<"---------------\n";
	find_pts(x,y,x[0],y[0]);
}
