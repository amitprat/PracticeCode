/*Taken from : http://n00tc0d3r.blogspot.com/2013/04/maximum-rectangle.html
Maximum Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

For example, given a rectangle as shown below, return 6.

0 0 0 1 1 0 1
0 1 0 1 0 1 1
1 0 1 1 1 0 0
0 1 1 1 1 0 1
Solution

Recall that we discussed Largest Rectangle in Histogram problem a few weeks ago. We can apply that idea to solve this problem, this is in 2D though.

First, we need to populate a table A for max length of vertical 1's. For each A[i][j], it is the maximum length of vertically continuous 1's ended at matrix[i][j], i.e. A[i][j] = k, meaning that matrix[i][j-k+1 .. j] are all 1's.

E.g. A such table for the given example in problem description is:

0 0 0 1 1 0 1
0 1 0 2 0 1 2
1 0 1 3 1 0 0
0 1 2 4 2 0 1

Then we can apply histogram algorithm on each row to find the maximum rectangle in the row.
*/
 private int maxRectangle(int[] histogram) {  
   Stack<Integer> ss = new Stack<Integer>();  
   int maxArea = 0, i = 0;  
   while (i < histogram.length) {  
     if (ss.isEmpty() || histogram[i] >= histogram[ss.peek()]) {  
       ss.push(i++);  
     } else {  
       maxArea = Math.max(maxArea,  
           histogram[ss.pop()]*(ss.isEmpty() ? i : (i - ss.peek() - 1)));  
     }  
   }  
   while (!ss.isEmpty()) {  
     maxArea = Math.max(maxArea,  
         histogram[ss.pop()]*(ss.isEmpty() ? i : (i - ss.peek() - 1)));  
   }  
   return maxArea;  
 }  
   
 public int maximalRectangle(char[][] matrix) {  
   int rows = matrix.length;  
   if (rows == 0) return 0;  
   int columns = matrix[0].length;  
   // lenTable[i][j] = k means matrix[i][j] - matrix[i][j+k-1] are all '1's.  
   int[][] lenTable = new int[rows][columns];  
   // initialize the table  
   for (int h=0; h<columns; ++h) {  
     if (matrix[0][h] == '1') lenTable[0][h] = 1;  
   }  
   for (int w=1; w<rows; ++w) {  
     for (int h=0; h<columns; ++h) {  
       if (matrix[w][h] == '0') continue;  
       lenTable[w][h] = lenTable[w-1][h] + 1;  
     }  
   }  
   // find the max rect area  
   int maxArea = 0;  
   for (int i=0; i<rows; ++i) {  
     maxArea = Math.max(maxArea, maxRectangle(lenTable[i]));  
   }  
   return maxArea;  
 }  
This algorithm runs in time O(n*m), where n and m are the number of rows and columns in the matrix, respectively. It takes O(n*m) space for the table and O(m) space for stack.
