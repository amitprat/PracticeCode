/*
You are given an array of n unique integer numbers 0 <= x_i < 2 * n 
Print all integers 0 <= x < 2 * n that are not present in this array. 
Example: 
find_missing([0]) = [1] 
find_missing([0, 2, 4]) = [1, 3, 5] # because all numbers are [0, 1, 2, 3, 4, 5] 
find_missing([]) = [] 
find_missing([0, 1, 4, 5]) = [2, 3, 6, 7] # because all numbers are [0, 1, 2, 3, 4, 5, 6, 7] 

Quirks are about requirements: 

Time complexity O(n) - BUT there should be some fixed constant C independent of size of input such that every element of array is written/read < C times, so radix sorting the array is a no go. 

Space complexity O(1) - you may modify the initial array, BUT sorted(initial_array) must equal sorted(array_after_executing_program) AND you can't store integers outside range [0, 2n) in this array (imagine that it's an array of uint32_t).

1. Put numbers between 0 and n-1 to a[number] 
2. Process array and if (a[i] != i) -> number "i" is missing 
3. Put numbers between n to 2*n-1 to a[number-n] 
4. Process array and if (a[i] != i + n) -> number "i + n" is missing

*/
public class AbsentNumbers {

	public static void main(String[] args) {
		int[] array = new int[]{8,4,12,0,7,3,1};
		printAbsentNumbers(array);
	}

	private static void printAbsentNumbers(int[] array) {
		//sort 0 to n-1
		for (int i = 0; i < array.length; i++) {
			if (array[i] < array.length){
				int temp = array[array[i]];
				array[array[i]] = array[i];
				array[i] = temp;
			}
		}
		//check 0 to n-1
		for (int i = 0; i < array.length; i++) {
			if (array[i] != i){
				System.out.print(i + " ");
			}
		}
		//sort n to 2*n-1
		for (int i = 0; i < array.length; i++) {
			if (array[i] >= array.length){
				int temp = array[array[i] - array.length];
				array[array[i] - array.length] = array[i];
				array[i] = temp;
			}
		}
		//check n to 2*n-1
		for (int i = 0; i < array.length; i++) {
			if (array[i] != i + array.length){
				System.out.print(i + array.length + " ");
			}
		}
	}

}
