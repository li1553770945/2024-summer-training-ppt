#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    string s; // 原字符串
    string t; // 映射后的字符串
    bool operator < (const Node &a) const // 要比较的是映射后的字符串，比较的是t
    {
        return t < a.t;
    }
};

int main()
{
    string s;
    cin >> s;
    map <char,char> m; // 字符到字符的映射，把名字中的字符映射到新的字符
    for (int i = 0; i < 26; i++)
    {
        m[s[i]] = 'a' + i; // 构建映射
    }
    int n;
    cin >> n;
    vector <Node> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string t = "";
        for (int j = 0; j < s.size(); j++)
        {
            t += m[s[j]]; // 每一个名字s都映射到新的名字t
        }
        Node u;
        u.s = s;
        u.t = t; // 用结构体保存
        v.push_back(u);
    }
    sort(v.begin(), v.end()); // 直接对所有结构体进行排序，排序的依据是t
    for (int i = 0; i < n; i++)
    {
        cout << v[i].s << endl; // 输出原来的名字，也就是s
    }
    return 0;
}