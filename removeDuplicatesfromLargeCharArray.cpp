/*
Remove Duplicates from Char array
*/
Java: You're given a very large array of char's. Write a method to remove duplicates in the array, in place. Optimize for space complexity, not time complexity.

As the array is very large so we can assume that array has more space than range of its charset i.e [a-z] or [A-Z] or  both

1) for only printing the non-repeating elements - 
/*for simplicity consider only chars in set [A-Z]*/
void print(char in[],int n)
{
  for(int i=0;i<n;i++) {
    int pos = (abs(in[i])-'A')%26;
    if(in[pos] > 0 )
      cout<<(char)(abs(in[i]))<<" ";
      in[pos] *= -1;
  }
}

2) For actually removing duplicates from array and return array with non-duplicate elements - 
void remove(char in[],int n,int &new_n)
{
  
}
