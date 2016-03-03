/*
you are on a biz trip and travelling from one city to another. you have a stack of unsorted flight boarding passes. only departure city and destination city are on the boarding pass. how do you find the first departure city and your final destination city, write the solution in javascript.
*/

/*
Pop the flight boarding passes one at a time. Create a hash table of String to Integer. We're going to map the city to the net in and out. For departure, decrease value of net in and out, for arrival, increase value of net in and out. At the end, scan through the hash table to find +1, which is the destination, and -1, which is the departure.
*/
