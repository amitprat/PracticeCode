There is a set of n bolts and n nuts given. You have only API that tells whether given nut is smaller or larger then for a bolt no any other relative number. You need to match all nuts and bolts in O(nlogn).

Solution - 
1. Randomly choose a nut and partition the bolts ( smaller bolt than the nut | matched bolt | larger bolt than the nut) 
2. Use the matched bolt at step 1 to partition the nuts (smaller nuts than the bolt | matched nut | larger nut than the bolt) 
Recursively partition each subset. 
Concept(same as quick-sort) compiled for people who just want the solution right here without the need to google for it. However this is average case (or randomized) nlogn solution. worst case is still n^2.
