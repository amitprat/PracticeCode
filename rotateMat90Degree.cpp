for(int i=0; i<n/2; i++)
   for(int j=0; j<(n+1)/2; j++)
       cyclic_roll(m[i][j], m[n-1-j][i], m[n-1-i][n-1-j], m[j][n-1-i]);


void cyclic_roll(int &a, int &b, int &c, int &d)
{
   int temp = a;
   a = b;
   b = c;
   c = d;
   d = temp;
}
