#include <cstdio>
#include <algorithm>

#define int long long

using namespace std;

int geban(int x)
{
	if(x <= 2) return 0;
	return (x - 1) * (x - 2) / 2;
}


signed main()
{
	int n, k;
	scanf("%lld%lld", &n, &k);
	for(int s = 3; s <= n * 3; ++ s)
	{
		int t = geban(s) - 3 * geban(s - n) + 3 * geban(s - n * 2) - geban(s - n * 3); // 找到第K个数字对应的s
		if(k > t) // 当前s不符合条件
		{
			k -= t;
			continue;
		}
		for(int i = 1; i <= n; ++ i) // 找到了对应的s，开始枚举i
		{
			int mij = max(s - i - n, 1ll), maj = min(s - i - 1, n); // j的最小值和最大值
			if(mij > maj) continue;
			int num = maj - mij + 1; // 当前i对应的j有多少个，当前i对应的那一段的长度
			if(k > num)
			{
				k -= num;
				continue;
			}
			int j = mij + k - 1; // 计算第k个位置
			printf("%lld %lld %lld", i, j, s - i - j);
			return 0;
		}
	}
}