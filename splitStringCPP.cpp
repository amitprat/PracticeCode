/*tokenize string c++*/
/*split string into words*/

#include    <iostream>
#include    <string>
#include    <vector>
using namespace std;

vector<string> split(string str,char ch)
{
    vector<string> res;
    int start = 0;
    while(str.size())
    {
        int pos = str.find(ch);
        if(pos == -1)   break;
        res.push_back( str.substr(0,pos-start) );
        str = str.substr(pos+1);
    }
    res.push_back(str);
    return res;
}
int main()
{
    string result = "my name is amit so what";
    vector<string> res;
    res = split(result,' ');
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
~
