/*
Find the number of bits set in a given character array. 

After giving him a bit wise operation that was O(n) where n is the number of bits set, he wanted a more optimum solution
*/
/*Solution - 
1 )Create an array (of ints) where each item contains the bits in the character that is indexing it (e.g. numBits['A'] = 2; etc)
2) Then it is just an indexing/adding per each character in the array.
*/

int setBits(int num) {
  int count = 0;
  while(num) {
    count++;
    num &=(num-1);
  }
  return count;
}
void precalculate(int a[],char *arr) {
  for(int i=0;i<256;i++) {
    a[i] = setBits((int)arr[i]);
  }
}
int main() {
  char arr="amit";
  int count[256];
  int sum = 0;
  precalculate(arr,count);
  for(int i=0;i<strlen(arr);i++) {
    sum += count[arr[i]];
  }
  cout<<sum<<endl;
  return 0;
}
