/*
https://www.careercup.com/question?id=5651322294501376
Given an infinite stream of characters and a list L of strings, create a function that calls an external API when a word in L is recognized during the processing of the stream. 

Example: 
L = ["ok","test","one","try","trying"] 
stream = a,b,c,o,k,d,e,f,t,r,y,i,n,g............. 

the call to external API (let's call it some function callAPI()) would be called when the 'k' is encountered, again when the 'y' is encountered, and again at 'g'.
*/

/*
Create trie out of the list and navigate the nodes as you read from stream in linear time.
*/
