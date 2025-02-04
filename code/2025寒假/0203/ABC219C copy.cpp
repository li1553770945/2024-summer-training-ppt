#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    string s;
    string t;
    bool operator < (const Node &a) const
    {
        return t < a.t;
    }
};
char temp[30];
int main()
{
    string str;
    scanf("%s",temp);
    str = temp;
    map <char,char> m;
    for (int i = 0; i < 26; i++)
    {
        m[str[i]] = 'a' + i;
    }
    int n;
    cin >> n;
    vector <Node> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        scanf("%s",temp);
        s = temp;
        string t = "";
        for (int j = 0; j < s.size(); j++)
        {
            t += m[s[j]];
        }
        Node u;
        u.s = s;
        u.t = t;
        v.push_back(u);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        printf("%s\n",v[i].s.data());
    }
    return 0;
}