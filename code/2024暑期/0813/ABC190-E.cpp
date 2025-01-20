#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<set>
#define iss ios::sync_with_stdio(false)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int>pii;
const int MAXN=1e5+200;
const int mod=77797;
const int inf=0x3f3f3f3f;
int n,m;
int k;
int c[20];
std::vector<int> v[MAXN];
ll dis[20][20];
int vis[MAXN];
ll d[MAXN];
ll dp[(1<<18)][20];
void bfs(int s)
{
    d[s]=0;
    dis[vis[s]][vis[s]]=0;
    queue<int >q;
    q.push(s);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        int len=v[now].size();
        for(int i=0;i<len;i++)
        {
            if(d[v[now][i]]==inf)
            {
                d[v[now][i]]=d[now]+1;
                q.push(v[now][i]);
                if(vis[v[now][i]]) 
                {
                    //cout<<s<<" "<<v[now][i]<<endl;
                    dis[vis[s]][vis[v[now][i]]]=d[v[now][i]];
                }
            }
        }
    }
}
int main()
{
    memset(dis,inf,sizeof dis);
    cin>>n>>m;
    for(int i=1;i<=m;i++) // 输入，建图
    {
        int uu,vv;
        cin>>uu>>vv;
        v[uu].push_back(vv);
        v[vv].push_back(uu);
    }
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        vis[c[i]]=i;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            d[j]=inf;
        }
        bfs(c[i]); // 通过bfs，计算出所有关键点，到其他关键点的最短距离
    }
    memset(dp,inf,sizeof dp);
    // dp[i][j] 状态为i，最后一个访问的宝石是j的最短距离
    for(int i=1;i<=k;i++)
    {
        dp[1<<(i-1)][i]=1; // 初始化仅访问一个宝石的状态
    }
    for(int i=1;i<=(1<<k)-1;i++) // 枚举所有的状态
    {
        for(int j=1;j<=k;j++) // 枚举当前状态i下，最后一个点是j的情况
        {
            if(dp[i][j]==inf) 
                continue; // 如果当前状态到不了j，就不用继续了
            for(int z=1;z<=k;z++)  // 假如下一个点是z
            {
                if(z==j) continue; // 下一个点不能和当前最后一个点相同
                if((1<<(z-1))&i) continue; // 当前状态i下面，z这个点已经走过了，下一个点只可能是状态i的时候还没有走过的点
                dp[i|(1<<(z-1))][z]=min(dp[i|(1<<(z-1))][z],dp[i][j]+dis[j][z]); // 从点j走到点z，更新最短距离
            }
        }
    }
    ll ans=inf;
    for(int i=1;i<=k;i++)  // 枚举最后到达的点
    {
        ans=min(ans,dp[(1<<k)-1][i]); // 取一个最小值
    }
    if(ans==inf)printf("-1\n");
    else printf("%lld\n",ans);
}
