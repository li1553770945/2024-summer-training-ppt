#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 4005;
const int inf = 0x3f3f3f3f;
struct Edge {
    int v,next,w;
}e[N];
int dir[N];
struct Node {
    int u,dis;
    bool operator < (const Node &a) const {
        return dis>a.dis;
    }
};

int head[N],cnt=0;
int disc[N][N];
void add(int u,int v,int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dij(int s) // 迪杰斯特拉算法，求单源最短路径
{
    priority_queue <Node> q;
    Node temp;
    temp.u = s;
    temp.dis = 0;
    disc[s][s] = 0;
    q.push(temp);
    while(!q.empty())
    {
        Node top = q.top();
        q.pop();
        int u = top.u,dis=top.dis;
        for(int i  = head[u];i;i=e[i].next)
        {
            int v = e[i].v,w=e[i].w;
            if(disc[s][v]>disc[s][u]+w)
            {
                disc[s][v] = disc[s][u]+w;
                Node temp;
                temp.u = v;
                temp.dis = disc[s][v];
                q.push(temp);
            }
        }
    }

}
int main()
{
    memset(disc,inf,sizeof(disc));
    memset(dir,inf,sizeof(dir));
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w); // 处理输入
        if(u==v) // u==v，这是一条自环。对于我们求最短路是没有任何贡献的，直接记录下来即可，dir[u]表示u到u的自环的最短
        {
            dir[u] = min(dir[u],w);
            continue;
        }
        add(u,v,w); // 添加边，注意是单向边
    }
    for(int i =1;i<=n;i++) // 对于每个点，计算这个点到其他点的最短路径
    {
        dij(i);
    }
    for(int u=1;u<=n;u++)
    {
        int ans = dir[u]; // 答案可能是自环，
       
        for(int v=1;v<=n;v++) // 枚举所有u能到达的v
        {
            if(u!=v)
            {
                ans = min (ans,disc[u][v]+disc[v][u]); // 从u到v的最短路，加上从v到u的最短路
            }
        }
        
        if(ans==inf) // 如果答案是inf，没有找到路径
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
    return 0;
}
