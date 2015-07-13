#include    <iostream>
#include    <vector>
using namespace std;


/*Nth gray code, Binary to Gray*/
int gray(int n) {
    return n^(n>>1);
}

/*Gray to Binary*/
int binary(int n) {
    for(int mask=(n>>1);mask;mask>>=1)
        n = n^mask;
    return n;
}

/*Generate first N gray codes*/
vector<string> generate_gkg_method(int n)
{
    vector<string> v;
    v.push_back("0"); v.push_back("1");
    for(int i=2;i<(1<<n);i<<=1) {
        for(int j=v.size()-1;j>=0;j--)
            v.push_back(v[j]);
        for(int j=0;j<i;j++)
            v[j] = "0" + v[j];
        for(int j=i;j<2*i;j++)
            v[j] = "1" + v[j];
    }
    return v;
}

/*Generate first N gray codes - Nootcoder method*/
vector<int> generate_nootcoder_method(int n) {
    vector<int> v;
    v.push_back(0);
    for(int i=0;i<n;i++) {
        int flipper = 1<<i;
        for(int j=v.size()-1;j>=0;j--)
            v.push_back(v[j]|flipper);
    }
    return v;
}
int main()
{
    int n = 3;
    cout<<"Gray upto "<<n<<endl;
    vector<string> res = generate_gkg_method(n);
    for(auto i : res)   cout<<i<<" ";
    cout<<endl;
    cout<<"Gray upto "<<n<<endl;
    vector<int> res1 = generate_nootcoder_method(n);
    for(auto i : res1)   cout<<i<<" ";
    cout<<endl;

    cout<<"Gray of "<<n<<" = "<<gray(n)<<endl;
    cout<<"Binary of "<<n<<" = "<<binary(3)<<endl;
    return 0;
}
