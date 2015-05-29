#include<stdio.h>
#ifdef PRG1
// PROGRAM 1
int main()
{
    int x = 10;
    int y = 15;

    printf("%d", (x, y));
    getchar();
    return 0;
}

//Op : 15
#elif PRG2
// PROGRAM 2:  Thanks to Shekhu for suggesting this program
#include<stdio.h>
int main()
{
    int x = 10;
    int y = (x++, x++); //  int y = (x++, ++x);
    printf("%d", y);
    getchar();
    return 0;
}
// Op : 11 Or 12 in second case 
#elif PRG3
// PROGRAM 3:  Thanks to Venki for suggesting this program
int main()
{
    int x = 10, y;

    // The following is equavalent to y = x++
    y = (x++, printf("x = %d\n", x), ++x, printf("x = %d\n", x), x++);

    // Note that last expression is evaluated
    // but side effect is not updated to y
    printf("y = %d\n", y);
    printf("x = %d\n", x);

    return 0;
}
//Op : 11 \n 12  \n 12  \n 13
  
#endif

//Compilation
// gcc comma.c -DPRG1
// gcc comma.c -DPRG2
// gcc comma.c -DPRG3
