

void printFactors(int number)
{
  while(!(number % 2))  {
    cout<<"2"<<"\t";
    number /= 2;
  }
  int sqNum = sqrt(number);
  for(int i=3;i<=sqNum;i+=2)  //check for all possible prime numbers which can devide this number 
  {
    int dev = i;
    while(number%dev == 0) {
      cout<<i<<"\t";
      dev *= i;
    }
  }
}
