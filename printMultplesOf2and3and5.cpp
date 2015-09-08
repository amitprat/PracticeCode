/*
Print the numbers of form 2^i.5^j in increasing order -- Google
Print Multiples of 2 and 5;
print Multiples of 2,3 & 5;
*/

/* 
  Return the nth multiple of 2,3 and 5
  Using Queue Method
  Ref - cracking coding interview
*/
int printMultiples( int n ) {
  queue<int> q2,q3,q5;
  q2.push(2);
  q3.push(3);
  q5.push(5);
  int count = 1;
  int mn = 1;
  while( count < n ) {
    mn = min( q2.front(), min(q3.front(), q5.front()) );
    if(mn == q5.front()) {
      q5.pop();
    } else {
      if(mn == q3.front() ) {
        q3.pop();
      } else {
        q2.pop();
        q2.push( 2*mn );
      }
      q3.push( 3*mn );
    }
    q5.push( 5*mn );
    count++;
  }
  return mn;
}

/*
Print all multiples of 2 and 5.
This method doesn't take any extra space.
We can extend this method also for 3 variable
like 2,3 and 5;
Ref - https://sites.google.com/site/spaceofjameschen/

*/
int printIncreasingNums( int n ) {
  vector<int> v;
  v.push_back(1);
  int c2 = 0;
  int c5 = 0;
  while( v.size() < n ) {
    if( v[c2]*2 < v[c5]*5 ) 
      v.push_back(v[c2++]*2);
    else if( v[c2]*2 > v[c5]*5 ) 
      v.push_back(v[c5++]*5);
    else {
      v.push_back(v[c2]*2);
      c2++;
      c5++;
    }
  }
  
  for(auto i : v) {
    cout<<i<<" ";
  }
  cout<<endl;
}

void printIncreasingNumsExtended( int n ) {
  vector<int> v;
  v.push_back(1);
  int c2 = 0;
  int c3 = 0;
  int c5 = 0;
  while( v.size() < n ) {
    int mn = min ( v[c2]*2, min(v[c3]*3,v[c5]*5) );
    if( v[c2]*2 == mn )
      v.push_back(v[c2++]*2);
    if( mn == v[c3]*3 ) {
      if(v.back() != mn )
        v.push_back(v[c3]*3);
      c3++;
    }
    if( mn == v[c5]*5) {
      if( v.back() != mn  )
        v.push_back(v[c5]*5);
      c5++;
    }
  }

  for(auto i : v) {
    cout<<i<<" ";
  }
  cout<<endl;
}
