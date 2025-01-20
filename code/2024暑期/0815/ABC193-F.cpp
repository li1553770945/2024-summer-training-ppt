#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int level[maxn];
int head[maxn], cnt;
int ss, ee;
struct edge
{
    int v, nex;
    ll w;
} e[maxm];

void init()
{
    cnt = 0;
    memset(head, -1, sizeof head);
}

void add(int u, int v, ll w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nex = head[u];
    head[u] = cnt++;
}

void add2(int u, int v, ll w, bool op) // 是否为有向图
{
    add(u, v, w);
    add(v, u, op ? 0 : w);
}

bool bfs(int s, int t)
{
    queue<int> q;
    memset(level, 0, sizeof level);
    level[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == t) return 1;
        for (int u = head[x]; ~u; u = e[u].nex)
        {
            int v = e[u].v;
            ll w = e[u].w;
            if (!level[v] && w)
            {
                level[v] = level[x] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}

ll dfs(int u, ll maxf, int t)
{
    if (u == t) return maxf;
    ll ret = 0;
    for (int i = head[u]; ~i; i = e[i].nex)
    {
        int v = e[i].v;
        ll w = e[i].w;
        if (level[u] + 1 == level[v] && w)
        {
            ll MIN = min(maxf - ret, w);
            w = dfs(v, MIN, t);
            e[i].w -= w;
            e[i^1].w += w;
            ret += w;
            if (ret == maxf) break;
        }
    }
    if (!ret) level[u] = -1; // 优化, 防止重搜, 说明u这一路不可能有流量了
    return ret;
}

ll Dinic(int s, int t)
{
    ll ans = 0;
    while (bfs(s, t))
    {
        ans += dfs(s, INF, t);
    }
    return ans;
}

char s[105][105];
int n;

int f(int x, int y)
{
    return x * n + y;
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (s[i][j] == '?') continue;
            if ((i + j) & 1)
            {
                s[i][j] ^= 'B' ^ 'W';
            }
        }
    }
    ss = n * n + 1, ee = n * n + 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j + 1 < n) add2(f(i, j), f(i, j + 1), 1, 0);
            if (i + 1 < n) add2(f(i, j), f(i + 1, j), 1, 0);
            if (s[i][j] == 'B') add2(ss, f(i, j), 4, 1);
            if (s[i][j] == 'W') add2(f(i, j), ee, 4, 1);
        }
    }
    printf("%lld\n", 2ll * n * (n - 1) - Dinic(ss, ee));
    return 0;
}
