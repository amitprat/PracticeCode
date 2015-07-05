// A C program to match wild card characters
#include <stdio.h>
#include <stdbool.h>
 
// The main function that checks if two given strings match. The first
// string may contain wildcard characters
bool match(char *first, char * second)
{
    // If we reach at the end of both strings, we are done
    if (*first == '\0' && *second == '\0')
        return true;
    /*
    this check fails for the case , s = ""; p = "*"; 
    if(!*first || !*second) return false;
    
    The below case check specially for s="", p = "*x";
    
    If we want to go in first way of return false,
    put extra check to return true;
    if(*first == '*' && *(first+1)=='\0' && !*second)
     return true;
    */
    if (*first == '*' && *(first+1) != '\0' && *second == '\0')
        return false;
 
    if (*first == '?' || *first == *second)
        return match(first+1, second+1);
 
    if (*first == '*')
        return match(first+1, second) || match(first, second+1);
        
    return false;
}

/*Dynamic Programming*/
bool isMatch(char *p, char *s)
{
    int plen = strlen(p);
    int slen = strlen(s);
    int table[plen+1][slen+1];
    for(int i=0;i<=plen;i++)
    {
        for(int j=0;j<=slen;j++) {
            table[i][j] = 0;
            if(i == 0 && j == 0 || (i && p[i-1] == '*') )
                table[i][j] = 1;
            if(i && j){
                if( p[i-1] == s[j-1] || (p[i-1] == '.') )
                    table[i][j] = table[i-1][j-1];
            }
        }
    }
    /*for(int i=0;i<=plen;i++) {
        for(int j=0;j<=slen;j++)
            printf("%d ",table[i][j]);
        printf("\n");
    }*/
    return table[plen][slen];
}
// A function to run test cases
void test(char *first, char *second)
{  
  match(first, second)? puts("Yes"): puts("No"); 
}
 
// Driver program to test above functions
int main()
{
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2 instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    return 0;
}
