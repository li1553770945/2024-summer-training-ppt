#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll const N = 405 , M = 0x3f3f3f3f3f3f;
ll n , m , f[N][N][N] , ans;
signed main()
{
	ios::sync_with_stdio(false);
	scanf("%lld%lld" , &n , &m);
    //读入
	memset(f , 0x3f , sizeof(f));
    //初始化
	for (int i = 1 , u , v , w;i <= m;i++)
    {
		scanf("%lld%lld%lld",&u,&v,&w);
		f[u][v][0] = w;//单向图
	}
	for (int i = 1;i <= n;i++) 
		for (int j = 0;j <= n;j++) 
            f[i][i][j] = 0;//自己到自己的最短路为0。
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				f[i][j][k] = min(f[i][k][k - 1] + f[k][j][k - 1] , f[i][j][k - 1]);
 	//floyd模板
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
					if (f[i][j][k] < M) 
                        ans += f[i][j][k];//统计答案
	printf("%lld\n",ans);
	return 0;
}