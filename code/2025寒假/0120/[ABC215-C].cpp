#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1e5+10;
string ans[MAXN];
int main() 
{
    string s;
    vector <int> v;
    int K;
    cin>>s>>K;

    int cnt=0;
    do 
    {
        cout<<s<<endl;
        ans[++cnt]=s;
    } while (prev_permutation(s.begin(), s.end()));
    cout<<ans[K]<<endl;
    return 0;
}