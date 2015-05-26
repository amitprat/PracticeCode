

string convert( unsigned int ip )
{
  Endianness 
  {
    int i;
    char c;
  }
  Endianness end;
  end.i = 1;
  
  unsigned char *p = (unsigned char *)&ip;
  stringstream result;
  
  if(end.c == 1)  \\little endian
  {
    result << (p+3) << "." << (p+2) <<"."<<(p+1)<<"."<<p;
  }
  else
  {
    result << (p) << "." << (p+1) <<"."<<(p+2)<<"."<<(p+3);
  }
  
  return p.str();
}
