/*
  you have given a post-fix of a binary try in which either you have 0 child(leaf node) or 2 child(internal node). 
  one more condition that all internal node are denoted via "i" and leaf node via "l". 
  we have to create this binary tree with this posfix.
*/
if(nodetype.length == 1){ // array has only one element hence it is head
return ps[0];
}
//iterate thrugh array and if nodetype is 'L' push it into stack , else pop last two elements from the stack and make it as right and left child of the current element push current element on to stack , in the end only root will be in the stack
for(int i=0; i < nodeType.lenght;i++){
	if(nodeType[i]=='L'){
	stack.push(ps[i]);
	}else{
	node right = stack.pop();
	node left=stock.pop();
	node element=ps[i];
	element.right=right;
	element.left=left;
	stack.push(element);
	}
}
