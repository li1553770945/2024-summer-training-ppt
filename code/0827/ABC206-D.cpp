#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N],sum[N],n,m,x,y,fa[N],res;
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
    
    cin>>n;
    for(int i=0;i<n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n/2;i++)
    {
         if(a[i]!=a[n-i+1])
         {
             int x=find(a[i]),y=find(a[n-i+1]);
             if(x!=y)
             {
                 fa[x]=fa[y];
                 res++;
             }
         }
    }
    cout<<res<<endl;
    return 0;
}