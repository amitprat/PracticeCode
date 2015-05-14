/*given an array with elements check if just by exchanging two elements of the array we get a sorted array. 

time restriction: 
O(NlogN) 
space restriction: 2N
*/

bool correctArray(int a[],int n)
{
    int first = -1, second = -1;
    bool flag = true;
    
    for(int i=1;i<n;i++) {
      if(flag) {
        if(a[i-1] > a[i]) {
          first = i-1;
          flag = false;
        } 
      }else {
        if(a[first] <= a[i]) {
          second = i-1;
          break;
        }
      }
    }
    if(first == -1) return false;
    if(second == -1)  second = n-1;
    
    swap(a[first],a[second]);
    
    for(int i=1;i<n;i++) {
      if(a[i-1] > a[i])
        return false;
    }
    return true;
}
