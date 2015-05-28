Given an unsorted array of integers find a minimum number which is not present in array. 
e.g -1 ,4, 5, -23,24 is array then answer should be -22.

How about maintaining a HashSet that covers the values that have already been encountered along with the minimal value found so far? O(n) memory and O(n) runtime:


public static int getSmallestUnfoundInInterval(int[] arr){
    if(arr == null){
        throw new NullPointerException();
    }
    if(arr.length == 0){
        throw new IllegalArgumentException();
    }
    
    //build the HashSet and get the min
    HashSet<Integer> set = new HashSet<Integer>();
    int minVal = Integer.MAX_VALUE;
    for(int i : arr){
        if(i < minVal){
            minVal = i;
        }
        set.add(i);
    }
    
    //search the HashSet for the first value counting up from the min that is NOT in the set
    while(set.contains(minVal)){
        minVal++;
    }
    return minVal;
