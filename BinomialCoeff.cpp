#include <stdio.h>

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeffImproved(int n, int k)
{
    int res = 1;
    k = k < n-k ? k : n-k;

    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
int binomialCoeffNormal(int n,int r)
{
    if(n == r) return 1;
    if(r == 1)    return n;
    return binomialCoeffNormal(n-1,r-1) + binomialCoeffNormal(n-1,r);
}
int fact(int n)
{
    if(n <= 1)  return 1;
    return n*fact(n-1);
}
//chances of over flow
int binomialCoeffMul(int n,int r)
{
    return fact(n)/(fact(n-r)*fact(r));
}
/* Drier program to test above function*/
int main()
{
    int n = 10;
    for(int k=1;k<=10;k++) {
        printf("Binomial Coefficient for n = %d, k = %d -: \n",n,k);
        printf ("Value of C(%d, %d) is %d\n", n, k, binomialCoeffMul(n, k) );
        printf ("Value of C(%d, %d) is %d\n", n, k, binomialCoeffNormal(n, k) );
        printf ("Value of C(%d, %d) is %d\n", n, k, binomialCoeffImproved(n, k) );
    }
    return 0;
}
