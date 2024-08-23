#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,k,a[N],dp[N][105],can[N];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
    {
		can[i]=upper_bound(a,a+1+n,a[i]/2)-a-1; // 二分找can[i]，也就是小于等于a[i]/2的最大的数的下标
	}
	for(int i=1;i<=n;i++)
    {
		dp[i][0]=i; // 初始化dp[i][0]为i，表示高桥一次都不操作，青木需要预处理的草的数量
		for(int j=1;j<=55;j++)
        {
			dp[i][j]=min(dp[i-1][j]+1,dp[can[i]][j-1]); //状态转移
		}
	}
	for(int i=0;i<=55;i++)
    {
		if(dp[n][i]<=k) //如果青木需要预处理的草的数量小于等于k
        {
			cout<<i<<" "<<dp[n][i];
			return 0;
		}
	}
	return 0;
}
