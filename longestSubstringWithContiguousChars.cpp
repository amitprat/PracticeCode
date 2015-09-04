/*
Taken from Stackoverflow


If the substring is defined as ''.join(sorted(substr)) in alphabet then:

there is no duplicates in the substring and therefore the size of the longest substring is less than (or equal to) the size of the alphabet

(ord(max(substr)) - ord(min(substr)) + 1) == len(substr), where ord() returns position in the alphabet (+/- constant) (builtin ord() can be used for lowercase ascii letters)

Here's O(n*m*m)-time, O(m)-space solution, where n is len(input_string) and m is len(alphabet):

from itertools import count

def longest_substr(input_string):
    maxsubstr = input_string[0:0] # empty slice (to accept subclasses of str)
    for start in range(len(input_string)): # O(n)
        for end in count(start + len(maxsubstr) + 1): # O(m)
            substr = input_string[start:end] # O(m)
            if len(set(substr)) != (end - start): # found duplicates or EOS
                break
            if (ord(max(substr)) - ord(min(substr)) + 1) == len(substr):
                maxsubstr = substr
    return maxsubstr
    
*/

/* 
O(n3) CPP implementation
It can be improved to O(n2) using prebuilding Range Minimu Queury for answering min and max in O(1) time
*/

for(int i=0;i<n;i++) {
  for(int j=i+1;j<n;j++) {
    char mn,mx;
    find(word,i,j,mn,mx);
    if(mx-mn==j-i)  maxSize = max(maxSz, j-i+1);
  }
}
