//ref : careercup
/*
Assuming you have a binary tree which stores integers, count the number of nodes whose value is lower than the value of its upper nodes.
*/

/*
In a binary tree there can be any value on any node, so we need to keep track of the Min. value found so far for that depth branch and propagate it until you reach the leafs, be aware not to count duplicates in the way back, a HashSet would help to avoid that, 
and the final HashSet will hold all Nodes which are lesser than all their possible parents.
*/

public static int countNumLesserNodes(Node<Integer> root) {
	if(root == null) {
		return 0;
	}
	Set<Node<Integer>> set = new HashSet<>();
	countNumLesserNodes(root.left, root.data, set);
	countNumLesserNodes(root.right, root.data, set);		
	return set.size();
}

public static void countNumLesserNodes(Node<Integer> root, int pVal, Set<Node<Integer>> set) {
	if(root == null) {
		return;
	}
	if(root.data < pVal) {
		set.add(root);
		pVal = root.data;
	}				
	countNumLesserNodes(root.left, pVal, set);
	countNumLesserNodes(root.right, pVal, set);		
}
