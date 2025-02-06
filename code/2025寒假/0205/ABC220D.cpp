#include <iostream>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 100005;

int n;
int a[MAX_N];
int dp[MAX_N][10];  // dp[i][j] 表示前 i 个数操作后，最终结果是 j 的方案数

// 计算 F 操作的结果
int f_operation(int x, int y)
{
    return (x + y) % 10;
}

// 计算 G 操作的结果
int g_operation(int x, int y)
{
    return (x * y) % 10;
}

int main()
{
    cin >> n;

    // 输入序列
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 初始化 dp 数组，dp[1][k] = 0
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 0;
    }
    dp[1][a[1]] = 1;// 除了dp[1][a_1] = 1

    // 动态规划处理
    for (int i = 2; i <= n; i++)
    {
        for (int k = 0; k < 10; k++) //初始化
        {
            dp[i][k] = 0;
        }
        
        for (int x = 0; x < 10; x++) // 对于每一个dp[i-1][x] ，对于每个x属于0-9，进行F和G操作，就能得到dp[i][计算结果]+dp[i-1][x]

        {
            if (dp[i - 1][x] == 0)
                continue;

            // F 操作
            int f_result = f_operation(x, a[i]);
            dp[i][f_result] = (dp[i][f_result] + dp[i - 1][x]) % MOD;

            // G 操作
            int g_result = g_operation(x, a[i]);
            dp[i][g_result] = (dp[i][g_result] + dp[i - 1][x]) % MOD;
        }
    }

    // 输出答案
    for (int i = 0; i < 10; i++)
    {
        cout << dp[n][i] << endl;
    }

    return 0;
}
