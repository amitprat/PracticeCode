void populate(char **s);

int main() {
	char *s;
	populate(&s);
	printf("%s", s);	// should print "Prasad"
	free(s);
	return 0;
}

void populate(char **str) {
	// 1. The next two lines is one implementation
	*str = (char *)malloc(sizeof(char) * 7);
	strcpy(*str, "Prasad");

	// 2. This line seperately is another implementation
	*str = "Prasad";
}
What is wrong, if anything, with the two implementations of populate.


1)There will be no compilation error in any of the implementation. 
2) The first implementation there won't be any issues in memory allocation or free. 
3)second implementation you can't free(S) because s is pointing to constant memory you can modify s to another pointer but you can't free the current memory allocated.
