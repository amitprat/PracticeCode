/*
Given an array of integers when the difference between every two neighbored elements is either -1 or +1 or 0. 
Write an efficient search algorithm to find a given number of x in the array.
*/
/*Psuedo code */
/*
This algorithm works because element can't be before (a[i]+diff) as the difference can only be < abs(1).
So by exploiting this property, increase index by diff everytime and hence the element will always be on right side
of current element if exists and not the current element.

array - 	3 4 5 6 5 4 4 3 2 1
indices - 	0 1 2 3 4 5 6 7 8 9

x = 7
index = 0;
index = 4 ( x - 3) ;
index = 4 + 2 (x-5) = 6
index = 6 + 3(7-4) = 9
break
*/
This condition is not true for general elements.
n=no of elements 
x element to found 

i=0; 
while(i<n && a[i]!=x) 
{ 
diff=abs(x-a[i]); 
i+=diff; 
} 
if(i>=n) 
print "element no found"; 
else 
print i;
