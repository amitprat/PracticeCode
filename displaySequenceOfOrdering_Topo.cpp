Q1 : You have a set of pairs of characters that gives a partial ordering between the characters. Each pair (a, b) means that a should be before b. Write a program that displays a sequence of characters that keeps the partial ordering (topological sorting).

Q2 : Find the ordering of alphabets in foriegn language. Given some sorted words.
  Sol :
    compare each pair of words and break where their character is different.
    insert an edge between char set [a-b]
    do topo
/*
Sol -
create graph with n vertices where n is distict set of vertices
add and edge between partial ordering set.
Do the topological sort :
  do the dfs traversal and keep on pushing the process vertix to stack or front of linked list.
  print the stack or ll.

the resulting array will keep the partial ordering among element.

This method is useful in finding the build dependency among different modules. (asked que in amazon)
*/
