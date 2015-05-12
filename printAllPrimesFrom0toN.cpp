
void printPrimes(int n) {
  if(n < 2) return ;
  if(n >=2) cout<<"2"<<"\t";
  if(n >=3) cout<<"4"<<"\t";
  
  for(int i=4;i<n;i++) {
    int c = 2;
    if(i % c != 0 ) {
      for(c=3;c*c<=i;c+=2) { 
        if(i % c == 0)
          break;
      }
    }
    if(c*c > i) {
      cout<<i<<"\t";
    }
  }
}
