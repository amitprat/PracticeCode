//Reference : http://www.careercup.com/question?id=5635989726822400
Write a program to test whether a string and all strings that can be made using the characters of that string are palindrome or not. 
Eg: 
Input	Output 
mmo	True 
yakak	True 
travel	False 


Get the string length as x
Put all characters with respective count in a map or array with count as value and character ascii as index
Scan through the map, and count the odd chars
if count(oddChars) > 1 || count(oddChars) == 1 && len&1 == 0
  return false;
else
  return true;
  
/If we need to rearrange chars also to make it palindrome then,
fidn the odd char (count) position if there , keep it at midlen
now iterate for each each <char,freq> in map, and place at l=(mid-1), r=(mid+1)
