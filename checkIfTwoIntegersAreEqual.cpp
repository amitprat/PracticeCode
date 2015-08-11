bool isEqual(int a,int b) {
  //assuming int size is 32 bits
  return 1^( ((a-b)>>31) | ((b-a)>>31));
}
