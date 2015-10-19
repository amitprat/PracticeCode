/*
Josephus problem | Set 1 (A O(n) Solution)
In computer science and mathematics, the Josephus Problem (or Josephus permutation) is a theoretical problem. Following is the problem statement:

There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, and person at position 4 survives.

The problem has following recursive structure.

  josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
  josephus(1, k) = 1
After the first person (kth from begining) is killed, n-1 persons are left. So we call josephus(n – 1, k) to get the position with n-1 persons. But the position returned by josephus(n – 1, k) will consider the position starting from k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1, k).
*/


int josephus( int n, int k) {
  if(n == 1) return 1;
  
  return (josephus(n-1,k)+(k-1))%n+1;
}

/*
Explanation - 
In every execution, we remove one element, so we need to shift next loop elements by (k-1) as we
leave (k-1) elements inbetween.
For example, initially we leave(k-1) [ 1 ], and execute 2. So, for next iteration, we need to adjust position of [3] as 
( cur_indx(0) + (k-1) )%n i.e 1  plus (add the count of executed person) 1 = 2;
which gives the index of 3 in original array.

when, we have only one element left, we execute the same and return.
As the array is 1 index based, so the base case return value will be 0.
*/


/*
Queue based iterative solution for much clarity
*/


int find( int a[], int n ) {
  queue<int> q;
  for(int i=1;i<=n;i++) q.push(i);
  int org = k;
  while( q.size() > 1 ) {
    while( k > 1 )  {q.push(q.front()); q.pop();k--;}
    k = org;
    q.pop();
  }
  return q.front();
}


/*
Explanation - 
n = 5, k = 2;

q = [1,2,3,4,5]

rounds - 
1 : [3,4,5,1]
2 : [5,1,3]
3 : [3,5]
4 : [3]

return 3;

n = 5, k = 3;

rounds : 
1 : [4,5,1,2]
2 : [2,4,5]
3 : [2,4]
4 : [4]

return 4;
*/
