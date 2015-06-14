/*
Reference : http://www.geeksforgeeks.org/sort-array-wave-form-2/
*/
Sort array in wave format - like
ip : 2 4 6 8 10 20
op : 4 2 8 6 20 10

1) T = O(nlgn)
  Sort the array and swap adjacent elements
  for(int i=0;i<n-1;i+=2)
  {
    swap(a[i],a[i+1]);
  }

2) T = O(n)

Trick : Just consider EVEN position elements, make sure it is on crest (i.e. bigger than previous and next element)

for(int i=0;i<n;i+=2) {
  if(i > 0 && a[i] < a[i-1])  //if this even position element is less than previous element, then swap it
    swap(a[i],a[i-1]);
  if(i<n-1 && a[i] < a[i+1])  //if this element is smaller than next element, then also swap it
    swap(a[i],a[i+]);
}
