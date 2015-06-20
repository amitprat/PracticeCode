
int countNum(int num)
{
  if(num < 3) return num;
  if(num >= 3 && num < 10)  return (n-1);
  
  int b = 1;
  while(num/b > 9)  b *= 10;
  int m = num/b;
  int r = num%b;
  
  if(m == 3)  return countNum(m*b-1);
  else return count(m)*countNum(b-1) + countNum(m) + countNum(r);
}
