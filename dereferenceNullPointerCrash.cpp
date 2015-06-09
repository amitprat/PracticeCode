/*
In code there is a breakpoint at the first line of main function. The program is executed but it crashes without touching the breakpoint. Is there any code that is executed before main itself
*/
#include<iostream>

int *p = NULL;

int func()
{
  return *p;
}

int c = func();

int main()
{
  int a = 5;
  printf("%d",a);
  return 0;
}
