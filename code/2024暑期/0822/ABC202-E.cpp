#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
int n, q, fa[N], Tin[N], Tout[N], timer;
vector<int> D[N], e[N];
void dfs(int u, int depth) //dfs，求时间戳
{
    Tin[u] = timer++;
    D[depth].push_back(Tin[u]);// 计算每个深度下的节点的时间戳，有序
    for (int i = 0; i < e[u].size(); i++)
        dfs(e[u][i], depth + 1);
    Tout[u] = timer++;
}
int main()
{

    scanf("%d", &n);
    for (int i = 2, fa; i <= n; i++)
    {
        scanf("%d", &fa);
        e[fa].push_back(i);
    }
    dfs(1, 0); //从根节点开始dfs，假设根节点深度为0
    int u, depth;
    cin >> q;
    while (q--)
    {
        scanf("%d%d", &u, &depth);
        int ans =  lower_bound(D[depth].begin(), D[depth].end(), Tout[u]) - lower_bound(D[depth].begin(), D[depth].end(), Tin[u]);
        printf("%d\n", ans);
    }
    return 0;
}