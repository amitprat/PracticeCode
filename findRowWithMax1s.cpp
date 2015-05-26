/*
A 2-D array of 1's and 0's is given. Find the row with max 1's. The array is sorted row wise (all 0's in a row are followed by all 1's).
*/

int func ( int a[], int m, int n )
{
  int row;
  i = m-1;
  j = n-1;
  while( i >= 0 && j >=0 )
  {
    if( a[i][j] )
    { 
      j--; 
      row =i;
    }
    else
      i--;
  }
  return(row);
}
