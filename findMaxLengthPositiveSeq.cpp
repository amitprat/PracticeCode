//Ref : http://www.careercup.com/question?id=5150558799265792
/*
Find the longest running positive sequence in an array - 
Eg - [1,2,-3,2,3,4,-6,1,2,3,4,5,-8,5,6] 

It should return 5, with start index : 8

The flag needs to set to true for the first +ve no of the sequence and set to false when -ve no is encountered
*/

public class LongestPositiveSequence {
	public void longestPositiveSequence(int[] a){
		
		int maxLength = 0;
		int currLength = 0;
		int maxIndex = 0;
		int currIndex = 0;
		boolean flag = false;
		for(int i = 0; i < a.length; i++){
			if(a[i] > 0){
				if(flag == true){
					currLength++;	
				}
				else{
					currIndex = i;
					currLength = 1;
					flag = true;
				}
			}else{
				if(currLength > maxLength){
					maxLength = currLength;
					maxIndex = currIndex;
				}
				flag = false;
			}
		}
		
		if(maxLength > 0){
			System.out.println("Max Length:" + maxLength + " || maxIndex: "+ ++maxIndex);
		}
		
	}
	
	public static void main(String[] args){
		LongestPositiveSequence sequence = new LongestPositiveSequence();
		int a[] = new int[] {1,2,-3,2,3,4,-6,1,2,3,4,5,-8,5,6};
		sequence.longestPositiveSequence(a);
		
	}
}
