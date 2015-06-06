/*
Array = {5, 2, 1} circular rotate array, calculate sum by multiplying each array elements with index and find minimum sum from all of rotated arrays. Time Complexity should be O(n) 

5x index + 2 x index + 1xindex = Sum 

Step 1: 5x1 + 2x2 + 1x3 = 5+4+3 ==> 12 

Step 2: (rotate array) {2,1,5} 
2x1 + 1x2 + 5x3 = 2+2+15 ==> 19 

Step 3: (rotate array) { 1,5, 2} 
1x1 + 5x2 + 2x3 = 1+10+ 6 ==> 17 

Step 4: (rotate array) {5,2,1} same as input array stop and print minimum sum 1.e 12
*/
First, start with the current value


1*A[0] + 2*A[1] + 3*A[2] ... A.length*A[A.length-1] = value
Then notice that rotating by one to the right is equivalent of adding the sum of all elements, and subtracting the last product.


A1 + A2+A2 + A3+A3+A3 .... => add sum => Alast + A1+A1 + A2+A2+A2 + A3+A3+A3+A3
So:


value += sumOfAll(A) - A[A.length-1];
In this example:
Step1: 1x5 + 2x2 + 3x1 = 12
Step2: value = 12 + (5+2+1) - 3x1 = 12 + 8 - 3 = 17
Step3: value = 17 + 8 - 3x2 = 19
(let's rotate again just for testing)
Step4: 19 + 8 - 3x5 = 12

Then simply look for the smallest value after going through A.length steps.
Going to the next step is O(1) so the algorithm is O(n)


function findMinSum(array) {
    var sum = 0;
    for(var i=0;i<array.length;i++) {
        sum += array[i];
    }
    
    // find current value
    var value = 0;
    for(var i=0;i<array.length;i++) {
        value += (i+1)*array[i];
    }
    
    var min = value;
    
    // keep changing rotation formula
    for(var i=array.length-1;i>=0;i--) {
        value += sum - array[i] * array.length;
        if(value<min)
            min = value;
    }
    
    return min;
}
