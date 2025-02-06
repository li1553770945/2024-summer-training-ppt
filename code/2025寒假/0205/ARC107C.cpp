#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=510;
const int MOD=998244353;
int n,m,a[N][N],fa[N],cnt[N];
long long fac[N]={0,1},ans=1;
bool check_hang(int x,int y)
{
    for(int i=1;i<=n;i++)
    {
        if(a[x][i]+a[y][i]>m) return false;
    }
    return true;
}
bool check_lie(int x,int y)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][x]+a[i][y]>m) return false;
    }
    return true;
}
int set_find(int x)
{
	return x==fa[x]?x:fa[x]=set_find(fa[x]);
}
void set_merge(int x,int y)
{
	int gx=set_find(x),gy=set_find(y);
	if(gx!=gy) fa[gx]=gy;
}
int main()
{
	memset(a,0x3f,sizeof a);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=500;i++) 
        fac[i]=(fac[i-1]*i)%MOD;
    for(int i=1;i<=n;i++) 
        fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
            scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
        for(int j=i+1;j<=n;j++)
		{
            if(check_hang(i,j)) 
                set_merge(i,j);
        }
    }
    for(int i=1;i<=n;i++) 
        cnt[set_find(i)]++;
    for(int i=1;i<=n;i++)
	{
		if(cnt[i]) 
            ans=(ans*fac[cnt[i]])%MOD;
	}
	for(int i=1;i<=n;i++) 
        fa[i]=i,cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
        for(int j=i+1;j<=n;j++)
		{
            if(check_lie(i,j)) 
                set_merge(i,j);
        }
    }
    for(int i=1;i<=n;i++) 
        cnt[set_find(i)]++;
        
    for(int i=1;i<=n;i++)
	{
		if(cnt[i]) 
            ans=(ans*fac[cnt[i]])%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}