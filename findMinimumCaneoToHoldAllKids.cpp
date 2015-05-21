/*
Reference - http://www.careercup.com/question?id=6303093824159744
If a canoe can hold 2 kids and a max weight of 150 lbs, write a function that returns the minimum number of canoes needed,
given a list of kids and their weights.
*/
/*Solution - 
Algorithm is to sort the array (ascending) and walk indexes toward the middle, 
comparing the sum of the values at the two indexes with the max weight of the canoes (150). 
If the summed weight is less than 150, increment boat counter and move both indexes closer to middle of array. 
If summed weight is higher than 150, only increment boat counter if heaver child is less than max weight, 
then only move higher index toward center (decrement). The reasoning here is that we'll try to pair the lighter child 
with the next heaviest child on the list, so we want to leave the low index pointer where it is and then go to the 
next iteration.
I tried a few test cases and it seems to be working as expected.

Complexity would be O(nlogn) due to the sort at the beginning.
*/
private static int GetMaxBoats(List<int> arr)
        {
            arr.Sort();
            /*foreach (int n in arr)
            {
                Console.WriteLine(n);
            }*/

            int lowIndex = 0;
            int highIndex = arr.Count - 1;
            int boatCounter = 0;

            while(lowIndex < highIndex)
            {
                if(arr[lowIndex] + arr[highIndex] <= 150)
                {
                    //2 kids fit
                    boatCounter++;
                    lowIndex++;
                    highIndex--;
                }
                else
                {
                    
                    if(arr[highIndex] <= 150)
                    {
                        // only 1 kid fits, put the larger kid in the boat if he fits
                        boatCounter++;
                    }
                    // Else, larger kid is too heavy to go on boat.

                    // Either way, we've handled the heavier child
                    highIndex--;
                }

                // cover case where both pointers point to same child
                if(lowIndex == highIndex)
                {
                    if (arr[highIndex] <= 150)
                    {
                        boatCounter++;
                    }

                    break;
                }
            }

            return boatCounter;
        }
