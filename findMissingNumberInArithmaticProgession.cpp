/*
  finding d ?
  
  given a of all AP series of length of nof which one element is removed.
  ex : 
  1 3 5 9
  n = 4;
  
  d = (a[n-1] - a[0])/n    //( ans  = 2)
  [ actual diff in correct AP is , d = (a[n-1] - a[0])/(n-1) as there are n-1 empty spaces between n elements ]
  
  another method = 
  d = min( a[i+2] - a[i+1] , a[i+1] - a[i] );
  [ this is not correct as it will in case of decreasing AP 
    ex : 9 5 3 1
    d by above method = -4 which is not correct
  ]
  [ reject array itself if less than 3 elements as we can't determine AP then ] 
  
*/

1 ) T = O(n)
  for(int i=1;i<n;i++)
    if(a[i] != a[i-1] + d )
      return a[i-1] + d;
  return a[i-1] + d; //if found no missing element, return next element

2) for(int i=1;i<n-1;i++) {
      if(a[i] != (a[i-1] + a[i+1])/2) {
        if( abs(a[i] - a[i-1]) > abs(a[i+1]-a[i]) )
          return (a[i]+a[i-1])/2;
        else 
          return (a[i] + a[i+1])/2;
      }
      return (2*a[i] - a[i-1]); //if found no missing element, return next element
   }
   
   
3) T = O(lgn)
  int d = (a[n-1]-a[0])/2;
  
int find(int a[],int l,int r,int d)
{
    if(l<r) {
        int m = (l+r)/2;
        if(m > 0 && (a[m] != a[m-1] +d))
            return a[m-1]+d;
        if(a[m] +d != a[m+1])
            return a[m]+d;
        if(a[0]+d*m != a[m])     //missing in left
            return find(a,l,m-1,d);
        else  //missing in right 
            return find(a,m+1,r,d); 
    }
    return INT_MAX;
}
