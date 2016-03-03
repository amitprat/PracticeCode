/*
Number list compressing. 
Given an sorted array. Input: sorted number list 
1, 2, 3,10, 25, 26, 30, 31, 32, 33 

Output: find consecutive segments 
print: 1-3, 10, 25-26, 30-33
*/
void printCompression (int *array, int size) {
    int a, b;
    a= array[0];
    b = a;
    for (int i=1 ; i<size; i++) {
        if (array[i] == b+1)
        {
            b = array[i];
        } else {
            if (a == b) {
                printf("%d,", a);
            } else {
                printf("%d-%d,", a, b);
            }
            a = array[i];
            b = a;
        }
    }
    if (a == b) {
        printf ("%d\n", a);
    } else {
        printf("%d-%d\n", a, b);
    }
}
