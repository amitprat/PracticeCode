/*Permute string with limitation that no uppercase characters are permuted*/

#include    <iostream>
#include    <string.h>
using namespace std;

void permute(char str[],int pos,int n)
{
    if(pos==n) {
        cout<<str<<" ";
        return;
    }
    for(int i=pos;i<=n;i++) {
        if(isupper(str[pos])) {
            permute(str,pos+1,n);
            break;
        }
        else {
            if(!isupper(str[i])) {
                swap(str[i],str[pos]);
                permute(str,pos+1,n);
                swap(str[i],str[pos]);
            }
        }
    }
}
int main()
{
    char str[] = "ADEDef";
    permute(str,0,strlen(str)-1);
    return 0;
}
