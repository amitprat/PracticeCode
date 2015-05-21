//Reference : http://www.careercup.com/question?id=4971117158596608
/*
Given a list of queries and their counts, write a function that returns one of the queries 
at random such that over time it returns an equal distribution based on the counts provided in the input.
*/

/*
My Sol :
do similar to probablistic to select as per frequency.

*/
Simply, since each query has a count, we build array of ranges and each range represent a query, then we use rand()%countSum , where countSum is the sum of all counts for all queries, after that we do binary search to see this fits in which range and we return the query that represent this range !

here is the code, O(N)


class Range : public pair<int,int>{
public:
	int queryIndex;

	Range(int f, int s, int qindex=0) : pair<int, int>(f, s), queryIndex(qindex){}



};


int binarySearch(vector< Range >& rangesList,int value, int L, int R){
	
	if (L <= R)
	{

		int m = (L + R) / 2;

		if (rangesList[m].first <= value && value <= rangesList[m].second)
			return m;
		else
		if (value > rangesList[m].second){
			return binarySearch(rangesList, value, m + 1, R);
		}
		else{
			return binarySearch(rangesList, value, L, m - 1);
		}
	}

	return -1;
}

string getRandomQuery(const vector< pair<string, int> >& queries){

	vector< Range > rangesList;

	int rangeCount = 0;

	int countSum = 0;

	for (int i = 0; i < queries.size(); i++){
		Range range(rangeCount, rangeCount + queries[i].second - 1, i);
		rangesList.push_back(range);

		countSum += queries[i].second;

		rangeCount += queries[i].second;
	}

	int randomValue = rand() % countSum;

	int index = binarySearch(rangesList, randomValue, 0, rangesList.size() - 1);

	return queries[index].first;
}
