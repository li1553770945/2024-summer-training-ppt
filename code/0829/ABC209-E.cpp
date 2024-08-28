#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
const int M=2e5+7;
const int K=256;
char s[M][20];
int f[N];
queue<int>q;
vector<int>edge[N];
int g[N],idx;
map<int,int>mp;
main() 
{
	int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) 
	{
        scanf("%s",s[i]+1);int m=strlen(s[i]+1);
        int u=(s[i][1]-'A')*K*K+(s[i][2]-'A')*K+(s[i][3]-'A');
		int v=(s[i][m-2]-'A')*K*K+(s[i][m-1]-'A')*K+(s[i][m]-'A');
	    if(!mp[u])mp[u]=++idx;
        if(!mp[v])mp[v]=++idx;
        edge[mp[v]].push_back(mp[u]);g[mp[u]]++;
    }
    for(int i=1;i<=idx;i++)
        if(!g[i])f[i]=1,q.push(i);
    while(!q.empty()) 
	{
        int u=q.front();
        q.pop();
        for (int i=0;i<edge[u].size();i++) 
		{
            int v=edge[u][i];g[v]--;
            if (f[u]==1&&f[v]==0)f[v]=-1,q.push(v);
            if (f[v]==0&&!g[v]&&f[u]==-1)f[v]=1,q.push(v);  
        }
    }
    for (int i=1;i<=n;i++) 
	{
        int m=strlen(s[i]+1);
        int v=(s[i][m-2]-'A')*K*K+(s[i][m-1]-'A')*K+(s[i][m]-'A');
       // cout<<mp[v]<<endl;
        if(f[mp[v]]==1)puts("Takahashi");
        if(f[mp[v]]==-1)puts("Aoki");
        if(f[mp[v]]==0)puts("Draw");
    }
    return 0;
}