//Reference : http://www.careercup.com/question?id=5825789740187648
Given a string say "ABCD". Now create a new string with duplicates of each character in the original string and append the reverse of the same string (with duplicates) excluding the last character. 

First iteration: AABBCCCCBBAA 
[ABC three types of chars; Here c is the last char.Ignore duplicates after the last char c] 

Second iteration: AABBBBAA 

[here b is the last char] 

Third iteration: AAAA 
[no second char left]

#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str="ABCDEFG";  //test subject 
    int N = strlen(str);  //length of it

    int resultN = 4*(N-1); //length result string (-1 excludes last char)
    char *result = malloc( resultN + 1 ); //space for result string 

    //check malloc failure if you desire

    //4 positions of result corresponding to every char of str
    int a,b,c,d;  

    int i;
    for( i=0; i < N-1; i++)
    {
        /* first two positions in first half of result array */
        a=i << 1; // 2*i       (first position)
        b=a+1;    // 2*i+1     (second)

        /* last two positions in last half of result array */    
        c=resultN-1-a;  //resultN - 2*i -1  (third)
        d=c-1;          //resultN - 2*i -2  (fourth)

        /* fill the result positions in with current input character */
        result[a]=result[b]=result[c]=result[d]= str[i];
    }

    result[resultN] = '\0'; //NUL terminate

    printf("%s\n", result);

    return 0;
}
