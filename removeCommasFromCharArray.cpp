#include    <iostream>
using namespace std;

char arr[] = "1,234,34,54";

char *RemoveCommas(char *arr) {
	char *curr = arr, *tail = arr;
         while (*tail) {
             if(*tail != ',')
                *curr++ = *tail++;
             else
                tail++;
         }
         *curr = '\0';
         return arr;
}

int main()
{
    RemoveCommas(arr);
    cout<<arr<<endl;
    return 0;
}
