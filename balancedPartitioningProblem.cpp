/*
Balanced Partitioning Problem;
Devide given set into two subsets such that the minimum difference between sum of two sets is minimum.
example  - 
[5,1,2,1]
Sum = 9
S1 = [5], S2 = [1,2,1]
*/

/*
Algorithm:
Firstly this algorithm can be viewed as knapsack problem where individual array elements are the weights and half the sum as total weight of the knapsack.

1.take a solution array as boolean array sol[] of size sum/2+1

2. For each array element,traverse the array and set sol [j] to be true if sol [j – value of array] is true

3.Let halfsumcloser be the closest reachable number to half the sum and partition are sum-halfsumcloser and halfsumcloser.

4.start from halfsum and decrease halfsumcloser once everytime until you find that sol[halfsumcloser] is true
*/
int minDiff ( int a[], int n ) {
  int s = sum(a,n);
  int d = s/2;
  
  while ( d > 0 && !subsetSum(a,n,d) )
    d--;
  return d;
}

bool subsetSum(int a[],int n,int d) {
  bool table[d+1][n+1];
  for(int i=0;i<=d;i++) table[0][i] = true;
  for(int i=1;i<=n;i++) table[i][0] = false;
  
  for(int i=1;i<=d;i++) {
    for(int j=1;j<=n;j++) {
      table[i][j] = table[i][j-1];
      if(i >= a[j-1])
        table[i]j] |=table[i-a[j-1]][j-1]
    }
  }
  return table[d][n];
}


/*
taken from  - http://algorithmsandme.in/2014/04/balanced-partition-problem/
Another good solution
It is using the idea that if at any row, we see that we can reach upton that sum, keep on minimizing the differnce.

I think, we really don't need to traverse the entire table again. We can just look at last column in each row and 
check if that is true and then minimize the differenc. ( Because, if any element in that row is true before last column
then last column will be TRUE by defualt
*/

int balancePartition(int set[], int n)
{
 /*The value of subset[i][j] will be true if there is a subset 
     of set[0..j-1] with sum equal to i */
        int i,j;
        int sum =0;

        for(i =0; i<=n; i++){
                sum += set[i];
        }

        int subset[sum+1][n+1];
        // If sum is 0, then answer is true
        for (i = 0; i <= n; i++)
                subset[0][i] = true;

        // If sum is not 0 and set is empty, then answer is false
        for (i = 1; i <= sum; i++)
                subset[i][0] = false;


        // Fill the subset table in botton up manner
        for (i = 1; i <= sum; i++)
        {
         for ( j = 1; j <= n ; j++)
         {
           subset[i][j] = subset[i][j-1];
           if (i >= set[j-1]){
              subset[i][j] = subset[i][j] ||subset[i-set[j-1]][j-1];
           }
         }
        }

        int min =INT_MAX;
    
        for(i=1; i<=sum; i++){
           for(j=1; j<=n; j++){
           /* If there is s subset with sum i, then check if the 
              difference between overall sum and twice this sum is least or not.
              If yes update the min */
              
              if(subset[i][j] == true){
                   if(abs(sum - 2*i) < min){
                       min  = abs(sum - 2 *i);
                   }
              }
           }
        }

        printf("\n Differece between two sub sets will be : %d\n", min);
}
int main(){
        int a[] = {1,7,4,11};
        int n = sizeof(a)/sizeof(a[0]);
        balancePartition(a,n-1);
        return 0;
}
