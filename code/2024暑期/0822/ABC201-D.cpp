#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 2010;
int a[maxn][maxn];
int dp[maxn][maxn];
int h, w;

int main()
{
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char x;
            cin >> x;
            if (x == '+')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = -1;
            }
        }
    }

    // dp数组初始化为很小的数值
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[h][w] = 0;

    // 从终点开始倒推回起点
    for (int i = h; i >= 1; i--)
    {
        for (int j = w; j >= 1; j--)
        {
            if (i < h)
            {
                dp[i][j] = max(dp[i][j], -dp[i + 1][j] + a[i + 1][j]);
            }
            if (j < w)
            {
                dp[i][j] = max(dp[i][j], -dp[i][j + 1] + a[i][j + 1]);
            }
        }
    }

    if (dp[1][1] > 0)
    {
        cout << "Takahashi" << endl;
    }
    else if (dp[1][1] < 0)
    {
        cout << "Aoki" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }

    return 0;
}
