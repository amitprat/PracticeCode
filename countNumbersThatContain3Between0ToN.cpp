int countNum(int num)
{
  if(num < 3) return 0;
  if(num >=3 && num < 10) return 1;
  
  int b = 1;
  while(num/b > 9)  b*=10;
  
  int m = num/10;
  int r = num%10;
  
  if(m == 3)  return (r+1) + m*countNum(b-1);
  else if(m > 3)  return (b-1) + m*countNum(b-1) + countNum(r);
  returnr m*countNum(b-1) + countNum(r);
}
