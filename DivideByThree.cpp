#include <iostream>
using namespace std;
int add(int x, int y) {
    while(x) {
        int t = (x & y) <<1;
        y ^= x;
        x = t;
    }
    return y;
}
/*Represent number in 4a +b format
num = 4*a + b;
num/3 = a + (a+b)/3
so, sum += a;
num =(a+b);
*/
int divideby3 (int num) {
    int sum = 0;
    while (num > 3) {
        sum = add(num >> 2, sum);
        num = add(num >> 2, num & 3);
    }
    if (num == 3) //if number is three, add one to it
        sum = add(sum, 1);
    return sum;
}
int main()
{
	for(int i=0;i<=19;i++)
		cout<<i<<" % 3 : "<<divideby3(i)<<endl;
    return 0;
}
