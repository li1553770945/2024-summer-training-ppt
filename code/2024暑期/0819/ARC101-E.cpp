#include <bits/stdc++.h>
using namespace std;

int n, hed[5010], sz[5010], cnt;
long long f[5010][5010], g[5010], dp[5010];
const long long mod = 1e9 + 7;
struct node
{
    int to, next;
} a[200010];
inline void add(int from, int to)
{
    a[++cnt].to = to;
    a[cnt].next = hed[from];
    hed[from] = cnt;
}
inline void dfs(int x, int fa)
{
    sz[x] = 1;
    f[x][1] = 1;
    for (int i = hed[x]; i; i = a[i].next)
    {
        int y = a[i].to;
        if (y == fa)
            continue;
        dfs(y, x);
        for (int j = 0; j <= sz[x] + sz[y]; ++j)
            dp[j] = 0;
        for (int j = 1; j <= sz[x]; ++j)
        {
            for (int k = 0; k <= sz[y]; ++k)
            {
                dp[j + k] = (dp[j + k] + f[x][j] * f[y][k] % mod) % mod;
            }
        }
        sz[x] += sz[y];
        for (int j = 1; j <= sz[x]; ++j)
            f[x][j] = dp[j];
    }
    for (int i = 2; i <= sz[x]; i += 2)
        f[x][0] = (f[x][0] + mod - f[x][i] * g[i] % mod) % mod;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    g[0] = 1;
    for (int i = 2; i <= n; i += 2)
        g[i] = g[i - 2] * (i - 1) % mod;
    dfs(1, 0);
    printf("%lld\n", (mod - f[1][0]) % mod);
    return 0;
}