/*
Babylonian method for square root
Algorithm:
This method can be derived from (but predates) Newton–Raphson method.


1 Start with an arbitrary positive start value x (the closer to the 
   root, the better).
2 Initialize y = 1.
3. Do following until desired approximation is achieved.
  a) Get the next approximation for root using average of x and y
  b) Set y = n/x
  
*/

float sqrt(float n) {
  float x = n;
  float y =1;
  
  while( (x-y) > e ) {
    x = (x+y)/2;
    y = n/x;
  }
  return x;
}

/*This method can only work if N is perfect square */
unsigned int sqrt(unsigned int n) {
  unsigned int x = n;
  unsigned int y = 1;
  
  while (x > y) {
    x = (y+y)/2;
    y = n/x;
  }
  return x;
}
  }
}
