#include  <stdio.h>

int main()
{
 //type 1
  int  *p = 10; //invalid int to int * conversion
  cout<<*p<<endl;
//type 2
  int *p;
  *p = 10;  //error as pointer p may be pointing to illegal memory
  
//type 3
  int *p = 0; //is same as int  *p = NULL;
  *p = 10;  //error NULL pointer operation

//type 4
  int *p = NULL;
  int q = (*p) + 2;
  //or function returning (*p)

//type 5
  int *p = 0;
  p += 2;
  cout<<p;  //0x08

//type 6;
  int *p = 0;
  p++;
  cout<<p; //0x04

//type 7
void *p = 0;
p += 2;
cout<<*p; /error, illegal memeory reference
cout<<p;  //0x02

//type 8
int **p = 0;  //here pointer p means NULL;
cout<<**p; // NULL pointer operation

return 0;
}
