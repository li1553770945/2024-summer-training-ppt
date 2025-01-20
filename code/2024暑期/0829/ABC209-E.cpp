#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
const int M=2e5+7;
const int K=256;
int f[N];
queue<int>q;
vector<int>edge[N];
int g[N],idx;
map<string,int>mp;
string s[N];
main() 
{
	int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) 
	{
        
        char str[10];
        scanf("%s",str);
        s[i]=str;
        int m=s[i].length();
        string u = s[i].substr(0, 3);
        string v = s[i].substr(m-3, 3);
	    if(!mp[u])
            mp[u]=++idx;
        if(!mp[v])
            mp[v]=++idx;
        edge[mp[v]].push_back(mp[u]);
        g[mp[u]]++;
    }
    for(int i=1;i<=idx;i++)
        if(!g[i])
        {
            f[i]=1;
            q.push(i);
        }
    while(!q.empty()) 
	{
        int u=q.front();
        q.pop();
        for (int i=0;i<edge[u].size();i++) 
		{
            int v=edge[u][i];
            g[v]--;
            if (f[u]==1&&f[v]==0)
                f[v]=-1,q.push(v);
            if (f[v]==0&&!g[v]&&f[u]==-1)
                f[v]=1,q.push(v);  
        }
    }
    for (int i=1;i<=n;i++) 
	{
        int m=s[i].length();
        string v=s[i].substr(m-3,3);
        if(f[mp[v]]==1)
            puts("Takahashi");
        if(f[mp[v]]==-1)
            puts("Aoki");
        if(f[mp[v]]==0)
            puts("Draw");
    }
    return 0;
}