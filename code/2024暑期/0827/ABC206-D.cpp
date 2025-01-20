#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N],sum[N],n,m,x,y,fa[N],res;
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]); // 并查集查询操作，每次查询x的祖先
}
int main()
{
    
    cin>>n;
    for(int i=0;i<n;i++)
        fa[i]=i; // 初始化并查集
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]; // 出入
    }
    for(int i=1;i<=n/2;i++) // 开始便利
    {
         if(a[i]!=a[n-i+1]) // 如果对称位置两个数不相等
         {
             int x=find(a[i]),y=find(a[n-i+1]); // 找到两个数的祖先
             if(x!=y) // 如果两个数的祖先不相等
             {
                 fa[x]=fa[y]; // 合并两个数的祖先
                 res++;    // 操作数+1
             }
         }
    }
    cout<<res<<endl;
    return 0;
}