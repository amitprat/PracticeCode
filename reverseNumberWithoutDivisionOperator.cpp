#include	<iostream>
using namespace std;

int rev(int num)
{
	int base = 10, mul = 1, prev = 0, res = 0, i =0;
	while( mul < num )
	{
		int r = num % base - prev;
		
		for(i=0;r;i++,r -= mul);
		
		res = res*10 + i;
		
		prev = num%base;
		
		base *= 10;
		mul *= 10;
	}
	return res;
}
int main()
{
	int num = 765;
	cout<<rev(num)<<endl;
	return 0;
}
