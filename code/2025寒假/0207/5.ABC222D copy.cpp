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

	for(long long i=a[1];i<=b[n];i++)
	{
		if(i>b[1])
		{
			f[1][i]=f[1][b[1]];
		}
		else
		{
			f[1][i]=i-a[1]+1;
		}
	}
		

	for(int i=2;i<=n;i++)
    {
		for(long long j=a[i];j<=b[n];j++)
        {
			if(j>b[i])
			{
				f[i][j] = f[i][b[i]];
			}
			else
			{
				f[i][j]=(f[i][j-1]+f[i-1][j])%mod;
				//cout<<i<<" "<<j<<" "<<f[i-1][j]<<" "<<f[i-1][b[i-1]]<<endl;
			}
		}
	}
	cout<<f[n][b[n]];
	return 0;
}