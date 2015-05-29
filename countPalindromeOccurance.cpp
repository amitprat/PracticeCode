/*
Identifying the number of occurrences of each palindrome in a file
*/

/*
Text file can be too large to fit in RAM, so i will prefer .. Map-Reduce approach:


1. Split your text file in to small chunks to fit in RAM.
2. Check each word for palindrome within the node and update its frequency in HashTable. Than write table to secondary storage.
3. Collect result\table for each chunk and combine them all.
4. To combine the results we can use "external sort" kind of approach.
*/
