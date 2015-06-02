/*Search for substring or reverse of substring in text wihtout any inbuild substring or strstr function*/
Rabin Karp substring matching for both reverse pattern and actual pattern match
match for cd and dc in abcd
substring match problem

#include    <iostream>
using namespace std;

int d = 256;
int q = 101;

bool isMatch(char *p,char *q,int n) {
    int i = 0;
    while(i < n && *p && *(q+i) && (*p == *(q+i) || *p == *(q+n-i-1)))    i += 1, p += 1;

    return (i==n);
}
void find(char *txt,char *pat,int n,int m)
{
    int h = 1;
    int hr = 1;
    int p=0,pr=0,t=0,tr=0; // pattern, pattern reverse, txt hash

    //calculate h=d^(m-1)
    for(int i=0;i<m-1;i++)
         h = (h*d)%q;   //for overflow check

    //calculate p,pr,t for first txt and pat block
    for(int i=0;i<m;i++) {
        p = (p*d+pat[i])%q;
        t = (t*d+txt[i])%q;

        //for reverse match
        pr = (pr*d+pat[m-i-1])%q;
        tr = (tr*d + txt[n-i-1])%q;
    }


    //now check for starting pat at every location from i=0 to i<n-m, shifting the hash accordingly
    for(int i=0;i<=n-m;i++) {   //equal to condition to avoid putting last pat check out of loop
        if(p == t || pr == t) { //found a match
            if(isMatch(txt+i,pat,m)) //check with actual character match
                cout<<"Pattern found at "<<i<<endl;
        }
        if(i == n-m)    break;  //reached the end and printed the needed pattern match
        //update the hash accordingly to move to next block
        t = ( d*(t - txt[i]*h) + txt[i+m])%q;  if(t < 0) t += q; //hash can be negative also, make it positive
    }


    //for reverse check
    for(int i=n-1;i>=m-1;i--) { // for last pat match
        if(pr == tr || p == tr){
            if(isMatch(txt+n-m,pat,m))
                cout<<"Reverse Pattern found at "<<i<<endl;
        }
        if(i == m-1)break;
        tr = ( d*(tr - txt[i]*h) + txt[i-m] )%q;
        if(tr < 0)  tr += q;
    }

}
int main()
{
    char *txt = "dccd";
    char *pat = "dc";

    find(txt,pat,strlen(txt),strlen(pat));
    return 0;
}
