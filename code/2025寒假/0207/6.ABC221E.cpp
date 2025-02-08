#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e6+10;
const int M=1e6+10;
const long long mod=998244353;
char s[30];
long long a[N],b[N];
long long ans[N];
long long tr[N];
int n;
long long dp[1005][1005];
long long lowbit(long long x){
   return x&(-x);
}
long long qpow(long long q,long long n)
{
   long long res=1;
   while(n){
      if(n&1){
         res=(res*q)%mod;
      }
      n>>=1;
      q=(q*q)%mod;
   }
   return res;
}
void add(long long x,long long c)
{
   for(long long i=x;i<=n;i+=lowbit(i)){
      tr[i]+=c;
   }
}
long long query(long long x)
{
   long long ans=0;
   for(long long i=x;i;i-=lowbit(i)){
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
   long long idx=unique(b+1,b+n+1)-b;   
   for(int i=1;i<=n;i++)
   {
      a[i]=lower_bound(b+1,b+idx,a[i])-b;
   }
   long long ans=0;
   for(int i=1;i<=n;i++)
   {
      ans=(ans+qpow(2,i-1)*query(a[i])%mod)%mod;
      add(a[i],qpow(qpow(2,mod-2),i)); 
   }
   printf("%lld\n",ans);
   return 0;
}