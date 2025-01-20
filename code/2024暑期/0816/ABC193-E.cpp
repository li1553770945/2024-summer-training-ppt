#include<bits/stdc++.h>
#define N 200006
#define LL __int128
#define int long long 
using namespace std;
 
int T,t;
int X,Y,P,Q;
int mod1,mod2;
int a1,a2,b1,b2;
 
inline int qr()
{
	char a=0;int w=1,x=0;
	while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return w*x;
}
 
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
 
LL mul(LL a,LL b,LL mod)
{
	LL ans=0;
	for(;b;a=(a+a)%mod,b>>=1)
		if(b&1) ans=(ans+a)%mod;
	return ans;
}
 
LL excrt()
{
    LL x,y,M=b1,ans=a1;
    LL a=M,b=b2,c=(a2-ans%b+b)%b;
    LL gcd=exgcd(a,b,x,y);
    LL bg=b/gcd;
    if(c%gcd!=0) return -1; 
    x=mul(x,c/gcd,bg);
    ans+=x*M;M*=bg;
    ans=(ans%M+M)%M;
    return (ans%M+M)%M;
}
 
signed main()
{
	T=qr();
	while(T--)
	{
		X=qr();Y=qr();
		P=qr();Q=qr();
		b1=(X+Y)<<1ll;
		b2=P+Q;
		LL ans=2e18;
		int opl=0;
		for(int i=0;i<Y;i++)
			for(int j=P;j<P+Q;j++)
			{
				a1=i+X;a2=j;
				LL ans1=excrt();
				if(ans1==-1) continue;
				opl=1;
				ans=min(ans1,ans);
			}
		if(opl) printf("%lld\n",(long long)ans);
		else printf("infinity\n");
	}
	return 0;
}