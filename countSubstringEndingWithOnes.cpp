/*
IP : 00010101
OP : 3 ( pos - (3,5), (3,7) , (5,7) )

/*
It is just like selecting 2 points from set of all end of points.
So count all numbers of 1s present in the string 
and then do nC2  = n*(n-1)/2
*/
int fun() {
  for(int i=0;i<n;i++)  
    if(a[i] == 1) m++;
  return m*(m-1)/2;
}



//If we also want to count the string with single ones as itself then simply add n to the above answer.

int fun() {
  for(int i=0;i<n;i++)  
    if(a[i] == 1) m++;
  return m*(m-1)/2 + m;
}
