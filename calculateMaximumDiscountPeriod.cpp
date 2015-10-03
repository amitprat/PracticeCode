There are discounts on particular time period 
suppost 
Day1 - Day5 => 10% 
Day2 - Day 8 => 5% 
Day4 - Day6 => 20 % 

find the period where maximum discounts is available. 

For above example the period is Day4 - Day5 => 10+5+20 

that means 35% 

Provide the generalize solution. Period can be time also.

1st Approach: 
convert periods into pairs
{day#, discount change}
start day of period has a positive discount change value, end day negative.
sort by day.
scan pairs, updating max total discount. when max is changed that is the starting day of the max period and the end day of the period is reset.
when we have max starting day and find a drop in total discount we set that pair as the end of the period.
O(nlgn)
