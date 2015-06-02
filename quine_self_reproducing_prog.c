#include <stdio.h> 
char str[] = "#include <stdio.h>%cchar str[] = %c%s%c;%cint main() { printf(str, 10, 34, str, 34, 10); return 0; }"; 
int main() { printf(str, 10, 34, str, 34, 10); return 0; }
/*10 new line, 34 quotes */
