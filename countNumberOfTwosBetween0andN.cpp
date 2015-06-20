/*Recursive method*/

int count(int num)
{
  if(num == 0)
    return 0;
  int base = 1;
  int c = 0;
  while(num/base > 10)  base *= 10;
  int rem = num%base;
  int mul = num/base;
  
  if(rem == 2)
    c = rem+1;
  else
    c = base;
  c += mul*count(base-1) + count(rem);
  return c;
}

/*Iterative Method*/

int count(int num)
{
  int seen = 0, base = 1, pos = 0;
  int c = 0;
  while(num)
  {
    int digit = num%10;
    c += digit*pos*(base/10);
    
    if(digit == 2)
      c += seen+1;
    else
      c += base;
    
    seen = digit*base;
    pos++;
    base *= 10;
    num /= 10;
  }
  return c;
}
