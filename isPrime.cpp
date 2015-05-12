
bool isPrime(int number) {
  if(number < 2)  return false;
  if(number == 2 || number == 3) return false;
  if(number % 2)  return false;
  int sqNum = sqrt(number);
  for(int i=3;i<=sqNum;i+=2) {
      if(number % i  == 0)
        return false;
  }
  
  return true;
}

bool isPrime1(int number) {
  if(number < 2)  return false;
  if(number == 2 || number == 3) return false;
  if(number % 2)  return false;
  for(int i=3;i*i<=number;i+=2) {
    if(number % i == 0) return false;
  }
  return true;
}
