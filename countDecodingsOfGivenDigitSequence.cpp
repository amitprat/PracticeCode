#include <iostream>
#include <cstring>
using namespace std;
/*gkg method which will count even the '0' possoble numbers which is somewhat wrong*/
int countDecoding(char *digits, int n)
{
    // base cases
    if (n == 0 || n == 1)
        return 1;

    int count = 0;  // Initialize count

    if (digits[n-1] > '0')
        count =  countDecoding(digits, n-1);

    if (digits[n-2] < '2' || (digits[n-2] == '2' && digits[n-1] < '7') )
        count +=  countDecoding(digits, n-2);

    return count;
}
/*My methods Recursion and DP to solve problem discarding invalid sequences*/
int numWays(char *str,int n) {
    if(n==0)    return 1;
    if(n==1)    return (str[n-1] != '0');

    int count = 0;
    if(str[n-1] > '0')
        count = numWays(str,n-1);

    if( (str[n-2] != '0') && (str[n-1]<'7' || str[n-2] <'2') )
        count += numWays(str,n-2);
    return count;
}

int numWaysDP(char  *str,int n) {
    int table[n+1];
    table[0] = 1;
    table[1] = (str[0] != '0');

    for(int i=2;i<=n;i++) {
        table[i] = 0;
        if((str[i-1] != '0'))
            table[i] = numWaysDP(str,n-1);
        if((str[i-2]!='0')&&(str[i-2]<'2' || str[i-1]<'7'))
            table[i] += numWaysDP(str,n-2);
    }
    return table[n];
}
// Driver program to test above function
int main()
{
    char digits[] = "101";
    int n = strlen(digits);
    cout << "Count is " << numWaysDP(digits, n);
    return 0;
}
