/*
Below question was asked in online coding exam for Palantir Technology, Palo Alto, CA. Time given was 100 min. I could not complete it by the time.

----------------------------- 

A group of farmers has some elevation data, and we’re going to help them understand how rainfall flows over their farmland. 
We’ll represent the land as a two-dimensional array of altitudes and use the following model, based on the idea that water flows downhill: 

If a cell’s four neighboring cells all have higher altitudes, we call this cell a sink; water collects in sinks. 
Otherwise, water will flow to the neighboring cell with the lowest altitude. If a cell is not a sink, you may assume it has a unique lowest neighbor and that this neighbor will be lower than the cell. 

Cells that drain into the same sink – directly or indirectly – are said to be part of the same basin. 

Your challenge is to partition the map into basins. In particular, given a map of elevations, your code should partition the map into basins and output the sizes of the basins, in descending order. 

Assume the elevation maps are square. Input will begin with a line with one integer, S, the height (and width) of the map. The next S lines will each contain a row of the map, each with S integers – the elevations of the S cells in the row. Some farmers have small land plots such as the examples below, while some have larger plots. However, in no case will a farmer have a plot of land larger than S = 5000. 

Your code should output a space-separated list of the basin sizes, in descending order. (Trailing spaces are ignored.) 

While correctness and performance are the most important parts of this problem, a human will be reading your solution, so please make an effort to submit clean, readable code. In particular, do not write code as if you were solving a problem for a competition. 

A few examples are below. 

Input: 
3 
1 5 2 
2 4 7 
3 6 9 


Output: 
7 2 





The basins, labeled with A’s and B’s, are: 
A A B 
A A B 
A A A 




Input: 
1 
10 

Output: 
1 


There is only one basin in this case. 




Input: 
5 
1 0 2 5 8 
2 3 4 7 9 
3 5 7 8 9 
1 2 5 4 2 
3 3 5 2 1 

Output: 
11 7 7 






The basins, labeled with A’s, B’s, and C’s, are: 
A A A A A 
A A A A A 
B B A C C 
B B B C C 
B B C C C 



Input: 
4 
0 2 1 3 
2 1 0 4 
3 3 3 3 
5 5 2 1 

Output: 
7 5 4 





The basins, labeled with A’s, B’s, and C’s, are: 
A A B B 
A B B B 
A B B C 
A C C C
*/
/*
Just another solution - 
1) For every element in matrix(at pos1), find smallest(pos2) in its surroundings and record its position in format (row*ROWS+col);
2) union the original position to this position. union1(pos1,pos2);
3)store in map and sort by frequency
4)print it
*/
#include    <iostream>
#include    <algorithm>
#include	<climits>
#include	<unordered_map>
#include	<vector>
#define NEIGHBOURS 4
using namespace std;
typedef vector< vector<int> > matrix;
int neighbour[NEIGHBOURS][2] = { {0,-1}, {-1,0},{0,1},{1,0} };
int find(int id[],int p) {
    while(p != id[p])
        p = id[p];
    return p;
}
void union1(int id[],int p,int q) {
    int proot = find(id,p);
    int qroot = find(id,q);
    if(proot != qroot)
        id[proot] = qroot;
}
bool issafe(int p,int S) {
    return (p>=0 && p < S);
}
int small(matrix m,int i,int j,int S) {
    int sm = m[i][j];
    int pos = i*S+j;
    for(int k=0;k<NEIGHBOURS;k++) {
        if( issafe(neighbour[k][0]+i,S) && issafe(neighbour[k][1]+j,S) ) {
            int tmp = min(sm, m[ neighbour[k][0]+i ] [ neighbour[k][1]+j ]);
            if(sm != tmp)
            	pos = S*(neighbour[k][0]+i) + neighbour[k][1]+j;
            sm = tmp;
        }
    }
    return pos;
}
int main()
{
    /*matrix mat = {
        {1, 5, 2},
        {2, 4, 7},
        {3, 6, 9}
    };*/
	matrix mat = {
		{1, 0, 2, 5, 8},
		{2, 3, 4, 7, 9 },
		{3, 5, 7, 8, 9},
		{1, 2, 5, 4, 2},
		{3, 3, 5, 2, 1}
	};
    int S = 5;
	unordered_map<int,int> m;
    vector<int> v;
    int id[S*S];
    for(int i=0;i<S*S;i++) {
        id[i] = i;
    }
    for(int i=0;i<S;i++) {
        for(int j=0;j<S;j++) {
            int s = small(mat,i,j,S);
            if( s != i*S +j)
                union1(id,i*S+j,s);
        }
    }
    for(int i=0;i<S*S;i++) {
        m[ find(id,id[i]) ]++;
    }
    for(auto i:m) {
        v.push_back(i.second);
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
}}}
