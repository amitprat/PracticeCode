/*
TAGS - 
Trapped Rain Water
Collected Rain Water between bars
Histogram area approach for rain water harvestation
*/
#include    <iostream>
#include    <stack>
using  namespace std;
int collectedWaterStackMethod(int h[],int n)
{
    int i = 0;
    int maximum = 0;
    stack<int> st;
    while(i < n)
    {
        if(st.empty() || h[i] <= h[st.top()])
            st.push(i++);
        else {
            int l = st.top(); st.pop();
            if(st.empty())  continue;
            int r = st.top(); st.pop();
            maximum = max( maximum, ((min(h[r],h[i])-h[l])*(i-r-1)));
        }
    }
    return maximum;
}

int collectedWaterArrayMethod(int h[],int n)
{
    int vol = 0;
    int hl[n],hr[n];
    hl[0] = h[0];
    hr[n-1] = h[n-1];
    for(int i=1;i<n;i++)    hl[i] = max(hl[i-1],h[i]);
    for(int i=n-2;i>=0;i--) hr[i] = max(hr[i+1],h[i]);
    for(int i=0;i<n;i++)    vol += ( min(hl[i],hr[i]) - h[i] );
    return vol;
}
int main()
{
    int a[] = {1,5,3,7,2};
    cout<< collectedWaterStackMethod(a,5) <<endl;
    cout<< collectedWaterArrayMethod(a,5) <<endl;
    return 0;
}
