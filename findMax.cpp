
/*
Find the maximum of two number without if-else instructions
Problem
Write a method which finds the maximum of two numbers. You should not use if-else or any other comparison operator.
EXAMPLE
Input: 5, 10
Output: 10

Solution
*/
#include <iostream>

using namespace std;

int max_without_if(int a, int b)
{
    return a + (a - b) * ((a - b) >> 31);
}
/* In case of a<b , (a-b)>>31 returns -1;
int main(int argc, char* argv[])
{
    int a = 5;
    int b = 10;

    cout << max_without_if(a, b) << endl;
    return 0;
}
