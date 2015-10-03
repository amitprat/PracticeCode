Implement a stack that supports push, pop and mode(the one from statistics) operation in the most efficient way



Keep 2 stacks, one that works as normal, and another that contains elements of max freq (and which only gets a value pushed or popped if the current max freq changes - this works similarly to the question in CTCI on maintaining 2 stacks to track the max or min value in a stack).

Also have a hash from elements to their count.

push: add element to 1st stack and increase element's frequency in hash. If element's freq > current max freq (freq of top element on 2nd stack), push added element to 2nd stack.

pop: remove top element of 1st stack and decrease element's frequency in hash. If popped element equals the element on the top of the 2nd stack, see if it's frequency falls below the next element below in the 2nd stack. If so, pop the element from the 2nd stack.

mode: return top element of 2nd stack

All operations are O(1).
