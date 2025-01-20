#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1e5 + 10;  // 假设最大排列数
bool used[MAXN];  // 用于标记字符是否已经使用
int cnt = 0;      // 记录当前排列的个数

// 递归实现全排列
void dfs(string& s, string& current, int& K)
{
    // 当current的长度等于s的长度时，记录当前排列
    if (current.length() == s.length())
    {
        cnt++;
        if (cnt == K)  // 如果已经找到了第K个排列，直接返回
        {
            cout << current << endl;
            exit(0);  // 结束程序
        }
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1]))  // 跳过重复字符
            continue;

        used[i] = true;  // 标记当前字符已使用
        current.push_back(s[i]);  // 选择该字符
        dfs(s, current, K);  // 递归
        current.pop_back();  // 回溯
        used[i] = false;  // 恢复标记
    }
}

int main()
{
    string s;
    int K;
    cin >> s >> K;

    // 排序字符串
    sort(s.begin(), s.end());

    string current;
    dfs(s, current, K);

    return 0;
}
