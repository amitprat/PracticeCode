/*
Given a file of n lines, where n-1 lines are identical and 1 line is different. Find the unique line in not more than one scan of the file.

First read three lines. 
If they are all same, these lines do not contain the unique line. Save this line, and go on matching for the other line in the rest of the (n-3) lines. 

If they are not all same, two of them must be same. The other one is the answer.
*/

if( line0 == line1  && line0 == line2)
  commonLine = line0;
else if(line0 == line1)
  return line2;
else if(line0 == line2)
  return line1;
else if(line1 == line2)
  return line0;
  
for(int i=3;i<n;i++)
  if(commonLine != line[i])
    return line[i]
