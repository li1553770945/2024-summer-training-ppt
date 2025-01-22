#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

const int MAX_N = 1000;

int main()
{
    int n;
    cin >> n;
    
    // 使用unordered_set来记录每对姓和名
    unordered_set<string> name_set;
    
    string s[MAX_N + 1], t[MAX_N + 1];
    
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> t[i];
        
        // 创建一个由姓和名组成的组合字符串
        string name_pair = s[i] + " " + t[i];
        
        // 检查这个组合是否已经存在
        if (name_set.find(name_pair) != name_set.end())
        {
            cout << "Yes" << endl;
            return 0;  // 找到重复，直接输出并结束
        }
        
        // 如果没有重复，加入集合中
        name_set.insert(name_pair);
    }
    
    cout << "No" << endl;
    return 0;
}
