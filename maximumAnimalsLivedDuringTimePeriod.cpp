/*
Given life time of different animals. Find period when maximum number of animals lived. ex [5, 11], [6, 18], [2, 5],[3,12] etc. year in which max no animals exists.


Input intervals (or lifetimes): [5, 11], [6, 18], [2, 5], [3,12]

*/
/*

Solution1 - 
Explanation - 

1. Put the end and start times of the intervals in one array. Sort it!. Always put the start time before end time in case they are equal. Maintain flags to identify a start/end interval. For above input I'll do something like:
2S, 3S, 5S, 5E, 6S, 11E, 12E, 18E

2. Now scan the array from left to right keeping track of how many intervals we are in. (This would be equal to total numbers of start intervals - total number of end intervals encountered so far). For above input I'll get something like:
1, 2, 3, 2, 3, 2, 1, 0

3. Now pick the maxima points from step 2. All the maxima points will be Start intervals and the point next to a maxima point will always be an end interval (which will be the end of the maxima start interval). So we'll get:
[5S,5E] and [6S,11E].

Hence the result is [5,5], [6,11]
Time complexity = O(nLogn), because of sorting in step 1. 
Space complexity = O(n)
*/

vector<Intervals> solution( Interval in[], int n )  {
    int s[n], e[n];
    for(int i = 0;i<n;i++) {
        s[i] = in[i].start;
        e[i] = in[i].end;
    }
    sort(s,s+n);
    sort(e,e+n);
    
    int i=0,j=0;
    while(i<n && j<n) {
        maxDiff = max( maxDiff, i-j+1 );
        res.push_back( Interval(s[i],e[j]);
        if( s[i] <= e[j] )  i++;
        else j++;
    }
    
    return res;
}


/*
Solution 2 -
Explanation - 

but i think this will also work 
1.Firstly take an array arr[100],initialize it to zero.
2.for every interval do +1 for eg, [5, 7] ,do arr[5]++,arr[6]++.arr[7]++;
3.now traverse again and you got all intervals for max value.
i think in this case time complexity is O(n).
*/

/*
Solution 3 - 
Explanation - 
Time = O(nlogn)
Space = O(n)

1) Sort all intervals according to start time.
2) Select the ith[i ->1,n] interval and merge to all previous intervals and keep on counting.
Example - 
(2,5), (3,12) , (5,11) , (6,18) - [1,1,1,1]
(3,5), (3,12) , (5,11) , (6,18) - [2,1,1,1]
(5,5), (5,11) , (5,11) , (6,18) - [3,2,1,1]
(5,5), (6,11) , (6,11) , (6,18) - [3,3,2,1]

Pick up all the max intervals (5,5) and (6,11);
*/
