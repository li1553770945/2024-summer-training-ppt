#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    long long c;
    bool operator<(const Edge& rhs) const 
    {
        return c < rhs.c;
    }
};

vector<Edge> edges;
int parent[200005];

int find(int x) 
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

int main() 
{
    int n, m;
    cin >> n >> m;
    long long total = 0;
    
    for (int i = 0; i < m; ++i)  //输入
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
        if (c > 0) 
            total += c;  // 累加所有正权边的总和
    }
    
    // 按处理后的权值排序
    // kruskal算法求最小生成数
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) 
    {
        return a.c < b.c;
    });
    
    for (int i = 1; i <= n; ++i) 
        parent[i] = i;
    
    long long mst = 0;
    for (const Edge& e : edges) 
    {
        int u = find(e.u), v = find(e.v);
        long long w = max(e.c, 0LL);
        if (u != v) 
        {
            parent[u] = v;
            mst += w;  // 生成树中的边权总和 ，记录使用了哪些权值为正的边
            // 计算了使用的正边的权值总和
        }
    }
    
    cout << total - mst << endl;  // 总奖励 = 所有正权边 - 生成树中的正权边
}