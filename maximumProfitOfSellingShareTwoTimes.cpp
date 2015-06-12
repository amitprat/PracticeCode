
int find(int price[],int n)
{
  int profit[n];
  memset(profit,0,n*sizeof(int));
  
  int maxprice = price[n-1];
  for(int i=n-2;i>=0;i--)
  {
    if(price[i] > maxprice)
      maxprice = price[i];
    
    profit[i] = max( profit[i+1], max - price[i]) );
  }
  int minprice = price[0];
  for(int i=1;i<n;i++)
  {
    if(price[i] < minprice)
      minprice = price[i];
    
    profit[i] = max( profit[i-1], profit[i] + (price[i] - minprice) );
  }
  return profit[n-1];
}
