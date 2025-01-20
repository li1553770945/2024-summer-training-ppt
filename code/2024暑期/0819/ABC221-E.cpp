#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int M=1e6+10;
const ll mod=998244353;
char s[30];
ll a[N],b[N];
ll ans[N];
ll tr[N];
int n;
ll dp[1005][1005];
ll lowbit(ll x){
   return x&(-x);
}
ll qpow(ll q,ll n)
{
   ll res=1;
   while(n){
      if(n&1){
         res=(res*q)%mod;
      }
      n>>=1;
      q=(q*q)%mod;
   }
   return res;
}
void add(ll x,ll c)
{
   for(ll i=x;i<=n;i+=lowbit(i)){
      tr[i]+=c;
   }
}
ll query(ll x)
{
   ll ans=0;
   for(ll i=x;i;i-=lowbit(i)){
      ans=(ans+tr[i])%mod;
   }
   return ans;
}

int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
      scanf("%lld",&a[i]);
      b[i]=a[i];
   }
   sort(b+1,b+1+n);
   ll idx=unique(b+1,b+n+1)-b;   
   for(int i=1;i<=n;i++)
   {
      a[i]=lower_bound(b+1,b+idx,a[i])-b; //排序，离散化，这个时候a[i]和原来的b[i]排序之后顺序是一致的
   }
   ll ans=0;
   for(int i=1;i<=n;i++)
   {
      ans=(ans+qpow(2,i-1)*query(a[i])%mod)%mod;
      add(a[i],qpow(qpow(2,mod-2),i)); 
   }
   printf("%lld\n",ans);
   return 0;
}