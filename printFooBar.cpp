/*
Write a function called FooBar that takes input integer n and prints all the numbers from 1 upto n in a new line. If the number is divisible by 3 then print "Foo", if the number is divisible by 5 then print "Bar" and if the number is divisible by both 3 and 5, print "FooBar". Otherwise just print the number. 
for example FooBar(15) should print as follows: 
1 
2 
Foo 
4 
Bar 
Foo 
7 
8 
Foo 
Bar 
11 
Foo 
13 
14 
FooBar 
*/

/*Simple solution with expensive Mod operation*/
void print(int n) {
  for(int i=1;i<=n;i++) {
    int r1 = i%3;
    int r2 = i%5;
    if(r1 && r2) cout<<i;
    else {
      if(r1)  cout<<"Foo";
      if(r2)  cout<<"Bar";
    }
    cout<<endl;
  }
}

/*Elegant Solution without mod operation*/

void print(int n) {
  int i3 = 3, i5 = 5;
  for(int i=1;i<=n;i++) {
    if(i!=i3 && i!=i5) 
      cout<<i;
    else {
      if(i == i3 && i3 += 3)  //second condtition is just to execute the operation
        cout<<"Foo";
      if(i==i5 && i5 += 5)
        cout<<"Bar";
      cout<<endl;
    }
  }
}
