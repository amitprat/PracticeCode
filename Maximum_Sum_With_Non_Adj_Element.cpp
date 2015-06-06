int sum(int a[],int n)
{
  int excl = 0;
  int incl = a[0];
  for(int i=1;i<n;i++)
  {
    int excl_new = max(excl,incl);
    incl = excl+a[i];
    excl = excl_new;
  }
  return max(excl,incl);
}
