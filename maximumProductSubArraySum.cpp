Given an array of integers and a length L, find a sub-array of length L such that the products of all integers are the biggest. 
Example: 
Input: {4, 1, -7, -8, 9}, 3 
Output: {-7,-8,9}

int maxProductSubArray(int a[],int n){
    int maxSoFar = 1;
    int maxEndingHere = 1;
    int minEndingHere = 1;
    
    for(int i=0;i<n;i++) {
        if( a[i] > 0 ) {
            maxEndingHere *= a[i];
            minEndingHere = min( minEndingHere*a[i], 1); 
        } else if (a[i] == 0) {
            maxEndingHere = minEndingHere = 1;
        } else {
            int tmp = maxEndingHere;
            maxEndingHere = max( minEndingHere * a[i], 1);
            minEndingHere = tmp * a[i];
        }
        if(maxEndingHere > maxSoFar)
            maxSoFar = maxEndingHere;
    }
    return maxSoFar;
}
