/*
Given a list of products in a customer basket find the minimum number of seller required to deliver his order,so as to optimise shipping part. 

Assuming you have already have below data 

Customer orders products : P1,P2,P3,P4,P5,P6 
Products and seller mapping 
P1 = [1,2,3,4] 
P2=[2,4,5,6] 

where 1,2,3 etc denotes seller_ids. 
*/

Solution - 
This is an instance of minimum set cover problem;It is NP complete problem, but greedy approach can work fine also.
Otherwise, we can do ILP also to optimize it further.

1) derive the sets that a seller can conver like
  S2 = {p1,p2 ...}
  S1 = {p1,...};
  etc.
2) Define the cost function for each seller to be 1.  ( cost function is generally useful when a cost is associate with a set.
like a seller 1 charges more than seller 2. Or it can also be related to set size means if set size is n and |Si-I| is m, then n/m ratio can also be considered. and if all ratio are 1, then add the largest set )
3) I = {} , S = {Si...}
4) while I != U 
  for all i in n
    find c with min cost = cost(si)/|Si-I|
  I = I union Si
