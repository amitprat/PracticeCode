Move the first n numbers in a 10 element array to the end. 

I think the way to do it was to reverse the array and then reverse the first 10-n and then the last n.

void leftRotate(int arr[], int d, int n)
{
  rvereseArray(arr, 0, n-1);
  rvereseArray(arr, 0, d-1);
  rvereseArray(arr, d, n-1);
}
