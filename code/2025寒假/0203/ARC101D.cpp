#include <iostream>
#include <algorithm>
#include <cstring>
const long long N=100005;
long long lb(long long x)
{
    return x&(-x);
}
using namespace std;
long long n,a[N],b[N],tmp[N],sum[N],c[N*2];
void add(long long k,long long x)
{
	for(;k<2*N;k+=lb(k)) c[k]+=x;
}
long long ask(long long k)
{
	long long s=0;
	for(;k;k-=lb(k)) s+=c[k];
	return s;
}
long long check(long long x)
{
	long long ans=0;
	memset(c,0,sizeof(c));
	for(long long i=1;i<=n;i++)
	{
		if(a[i]>=x) b[i]=1;
		else b[i]=-1;
		sum[i]=sum[i-1]+b[i];
	}
	add(N,1);
	for(long long i=1;i<=n;i++)
	{
		ans+=ask(sum[i]+N);
		add(sum[i]+N,1);
	}
	if(ans>=(n*(n+1)/2-1)/2+1)
        return 1;
	return 0;
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]),tmp[i]=a[i];
	sort(tmp+1,tmp+n+1);
	long long l=1,r=n,ans=0;
	while(l<=r) //二分 
	{
		long long mid=(l+r)/2;
		if(check(tmp[mid])) ans=tmp[mid],l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}