#include <iostream>
using namespace std;

const int MAX_N = 200000;  // 最大数据量

int p[MAX_N + 1];  // 存储置换P
int q[MAX_N + 1];  // 存储置换Q

int main()
{
    int n;  // 置换的长度
    cin >> n;
    
    // 读入置换P
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    // 根据题意生成置换Q
    for (int i = 1; i <= n; i++)
    {
        q[p[i]] = i;  // 对于每个i，Q的第p[i]个位置是i
    }

    // 输出置换Q
    for (int i = 1; i <= n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    return 0;
}
