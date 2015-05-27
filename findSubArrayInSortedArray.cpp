/*
Given an sorted array having duplicates and another which is not sorted and have duplicates.
Find array b is found continuously in array a. if so print position of array b in array a
*/
int bsearch(int a[],int l,int r,int e) {
    if( (r-l) > 1 ){
        int m = (l+r)/2;
        if ( e < a[m] )
            return bsearch(a,l,m-1,e);
        return bsearch(a,m,r,e);
    }
    return ( (a[r] == e ) ? r : ( (a[l] == e) ? l : -1 ) );
}
bool check(int a[],int n,int b[],int m,int &f,int &l) {
    int firstRightIndex = bsearch(a,0,n-1,b[0]);
    if( firstRightIndex == -1 ) {
        cout <<" Err : first index not found "<<endl;
        return false;
    }

    int prev = b[0];
    int i = 0,j;
    while(b[i] == prev) i++;

    if(firstRightIndex - i + 1 < 0 || a[ firstRightIndex - i + 1] != b[0] ) {
        cout << "out of Index "<<endl;
        return false;
    }

    f = firstRightIndex - i + 1;

    for(i=f,j=0;i<n && j<m;i++,j++) {
        if( b[j] != a[i] )  {
            cout << "Not proper subarray"<<endl;
            return false;
        }
    }
    l = i;
    return true;
}
int main()
{
    int a[] = {1,2,2,3,3,3,3,4,4,5,5,5,6,6,7,8};
    int sz_a = sizeof(a)/sizeof(a[0]);

    int b[] = {3,4,4,5,5,5,6,6,7};
    int sz_b = sizeof(b) / sizeof(b[0]);
    int f =-1,l = -1;
    cout << "Result : "<< ( check( a, sz_a, b , sz_b , f ,l) ? "True" : "False")<<endl;

    cout<<"Matched from "<<f<<" to "<<l<<endl;
    cout<<"Matched array : ";
    if( f != -1 && l != -1) {
        for(int i=f;i<l;i++)
            cout<<a[i]<<" ";
    }
    cout<<endl;

