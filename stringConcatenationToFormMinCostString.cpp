/*
You are to concatenate n strings (concatenate in any order) and a function: 
int strCat(str1, str2); // returns the concatenated str length 
Concatenate all strings in any order so that total cost is minimum. 
Example: Strings A="abc", B="wxyz", C="a" 
Cost of strCat(A,B) = (3+4) = 7 
Cost of strCat(AB,C) = 7+1 = 8 
Total cost = 7+8 =15 
Other way: 
Cost of strCat (A,C) = 3+1 = 4, 
Cost of strCat (AC,B) = 4+4 = 8 
Total Cost = 4+8 = 12 
In this case, min(12,15) = 12 so Ans=12.
*/
/*Similar to huffman coding */
Minheap<Node *> heap;
heap.insert( new Node(A,3)  );
heap.insert( new Node(B,4) );
heap.insert( new Node(C,1) );
heap.heapify();
int cost = 0;
vector<char> res;
while(heap.size() > 1) {
  Node *n1 = heap.extractMin();
  Node *n2 = heap.extractMin();
  heap.insert( n1.str+n2.str, n1.cost+n2.cost );
}
return heap.top().cost;
