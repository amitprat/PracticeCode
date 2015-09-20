/*
Appending the strings to form maximum length result string -
Given n strings consisting of ‘R’ and ‘B’. Two strings can be only combined if last character of first string and first character of second string are same. Given n strings, you have to output the maximum length possible by combining strings. 

I/P 
RBR 
BBR 
RRR 
output : 9
*/

/*
Solution - 
The solution becomes more apparent after analyzing the input a bit. Based only on the first and last character, there are 4 types of strings: RR (starts in R, ends in R), RB (starts in R, ends in B), BR and BB. 

We can combine all RRs into one big RR string, and all BBs into one big BB string. Both these big strings can be combined with any BR or RB string. If the input does not have any BR or RB strings then we return the size of the longest big string. It the input has at least one BR or RB, then we add the size of both big strings to our solution. 

Now we reduced the problem into finding a solution when the input only has strings of type RB or BR. We gradually add to our solution the size of the longest strings, oscillating between the two classes. When we ran out of strings in one class, we can add one more string from the other class (if there is one) and then we are done. 

The complexity in worst case scenario is n*log(n), due to sorting. Below is a Python implementation of the algorithm. Any feedback is most welcome.
*/
/*
Psuedo Code - taken from Careercup
strings = ['RRRR', 'BBB', 'R', 'BBB', 'RBBBB', 'RRB', 'BRBR', 'RBBB', 'BR']

RR = 0
BB = 0
RB = []
BR = []
for s in strings:
    if s[0] + s[-1] == 'BB':
        BB += len(s)
    elif s[0] + s[-1] == 'RR':
        RR += len(s)
    elif s[0] == 'R':  # and s[-1] = 'B'
        RB.append(len(s))
    else:
        BR.append(len(s))

if not BR and not RB:
    solution = max(RR, BB)
else:
    RB.sort(reverse=True)
    BR.sort(reverse=True)

    solution = BB + RR
    for i in range(min(len(BR), len(RB))):
        solution += BR[i] + RB[i]

    if len(RB) < len(BR):
        solution += BR[len(RB)]
    elif len(BR) < len(RB):
        solution += RB[len(BR)]

print solution
*/

/*My Soluion - Derived from above*/

int maxLen( vector<string> words ) {
  int rr=0,bb=0;
  vector<int> rb,br;
  
  for(auto word : words ) {
    if(isRR(word))  rr += word.size();
    else if(isBB(word)) bb += word.size();
    else if(isRB(word)) {
      rb.push_back(word.size());
    } else {
      br.push_back(word.size());
    }
  }
  
  if(rb.size() == 0 && br.size() == 0)
    maxLen = max(rr,bb);
  else {
    sol += rr+bb;
    sort(rb.begin(),rb,end());
    sort(br.begin(),br.end());
    
    for(int i=0;i<min(rb.size(),br.size());i++)
      sol += rb[i] + br[i];
    
    if(rb.size() > br.size())
      sol += rb[ br.size() -1 ];
    else if(br.size() > rb.size())
      sol += br[ rb.size() - 1];
  }
  
  return sol;
}
