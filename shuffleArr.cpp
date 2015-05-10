/*
Given array A of size N, using function Random(returns random number between 0 and 1) implement function that will return array of size N with randomly shuffled elements of the array A. 
You shoul give only algo.
*/

void fun(int a[],int n) 
{
  for(int n-1;i>=0;i--) {
    int index = (int)i * rand();  //rand() - generates between 0-1
    swap(a[i],a[index]);
  }
}
