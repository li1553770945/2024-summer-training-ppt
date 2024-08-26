#include <iostream>
using namespace std;

const int MAX_N = 100000; // 定义全局数组最大范围
int seq[MAX_N + 1];       // 用来存储序列，从1开始索引

int main()
{
    int n;
    cin >> n;

    // 用来记录每个数字是否出现过，初始化为0
    int freq[MAX_N + 1] = {0}; 

    // 读入序列并更新频率数组
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        freq[seq[i]]++;
    }

    // 检查每个数字是否恰好出现一次
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] != 1)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    // 如果所有数字都恰好出现一次
    cout << "Yes" << endl;
    return 0;
}
