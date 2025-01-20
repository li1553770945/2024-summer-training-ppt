#include <iostream>
#include <vector>
using namespace std;
const int maxm = 2e6 + 5;
vector<long long> g[maxm];
long long r[maxm], c[maxm];
long long n, m, w;

struct BIT
{
    long long c[maxm];
    long long lowbit(int i)
    {
        return i & -i;
    }
    long long add(int i, int t)
    {
        while (i < maxm)
        {
            c[i] += t;
            i += lowbit(i);
        }
    }
    long long ask(int i)
    {
        int ans = 0;
        while (i)
        {
            ans += c[i];
            i -= lowbit(i);
        }
        return ans;
    }
} T;

void solve()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++)
    {
        r[i] = m + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        c[i] = n + 1;
    }
    for (int i = 1; i <= w; i++)
    {
        long long x, y;
        cin >> x >> y;
        r[x] = min(r[x], y);
        c[y] = min(c[y], x);
    }
    long long ans = 0;
    // 先向下再向右
    for (int i = 1; i < c[1]; i++)
    {
        ans += r[i] - 1;
    }
    for (int i = c[1]; i <= n; i++)
    {
        r[i] = 1;
    }
    // 先向右再向下
    for (int i = 1; i <= n; i++) // 桶排序
    {
        g[r[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (c[i] == 1) break;
        ans += T.ask(c[i] - 1);
        for (auto j : g[i])
        {
            T.add(j, 1);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
