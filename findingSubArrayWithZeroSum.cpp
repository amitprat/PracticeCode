/*
  4 2 -3 1 6
  1) 
    run two loops
    check if sum of zero, return
  2) 
    take a hashmap of size n
    initialize sum with zero
    calculate sum from 0 to i ( i from 0 to n)
    hash the sum
    if currrent element is zero or this element make sum as zero then return true;
    critical - if you find the sum already existing in hash, means the sum of elements inbetween must be zero and hence return true
     
    for each element in array
      sum += arr[i];
      if( arr[i] == 0 || sum == 0 || hash.find(sum) != hash.end() )
        return true;
*/
