#include <iostream>
using namespace std;
const long long maxn=3050,mod=998244353;
long long a[maxn],b[maxn];
long long f[maxn][maxn];
long long n;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<=n;i++)
		cin>>b[i];

	for(long long i=a[1];i<=b[1];i++)
		f[1][i]=i-a[1]+1; // 初始化

	for(int i=2;i<=n;i++) // 枚举i，枚举前i个元素
    {
		for(long long j=a[i];j<=b[n];j++) //枚举j
        {
			if(j>b[i])
			{
				f[i][j] = f[i][b[i]];
			}
			else
			{
				f[i][j]=(f[i][j-1]+f[i-1][min(j,b[i-1])])%mod;
			}
		}
	}
	cout<<f[n][b[n]];
	return 0;
}