#include <iostream>
#include <cstring>
using namespace std;

int n, x, y;
int a[305];
int b[305];
int dp[305][305][305];

int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) 
    {
        cin >> a[i] >> b[i];
    }
    
	memset(dp, 0x3f, sizeof(dp));

	dp[0][0][0] = 0; // 初始条件，没有任何饭盒，自然只能满足0个物品A和0个物品B所需的最少餐盒数量是0

	for (int i = 1; i <= n; i++)
    {
		for (int j = 0; j <= x; j++)
        {
			for (int k = 0; k <= y; k++) // dp的过程
            {
				if (dp[i - 1][j][k] != 0x3f3f3f3f)  // 不取第i个物品，也能满足条件（不少于j个A和k个B）
                {
                    dp[i][j][k] = dp[i - 1][j][k]; // 不取第i个物品
                }
				dp[i][j][k] = min(dp[i][j][k], dp[i - 1][max(j - a[i], 0)][max(k - b[i], 0)] + 1);
                //dp[i - 1][max(j - a[i], 0)][max(k - b[i], 0)] + 1 取第i个物品，所以要+1
			}
		}
	}
    if(dp[n][x][y] == 0x3f3f3f3f)
    {
        cout << -1;
    }
    else
    {
        cout << dp[n][x][y]; // 选完前n个物品，不少于x个A，不少于y个B
    }
	return 0;
}