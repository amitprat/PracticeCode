/* Assuming you have a binary tree which stores integers, count the number of nodes whose value is lower than
the value of its upper nodes.
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


int countNode(root) {
	if(root == null) 
		return 0;
	int cnt = 0;
	if(root.left != null && root.value > root.left.value)
		cnt += 1 + countNodes(root.left);
	if(root.right != null && root.value > root.right.value)
		cnt += 1 + countNodes(root.right);
	return cnt;
}
