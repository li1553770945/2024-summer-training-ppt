#include <iostream>
#include <algorithm>

using namespace std;
const int maxn=2e5+10;
struct Node{ // 结构体，就是每个朋友，a就是朋友的位置，b是朋友能给他多少钱
    long long a,b;
    bool operator < (const Node &A) const{ //按照朋友的位置进行排序
        return a<A.a;
    }
}node[maxn];

int main()
{
    long long n, k;
    cin >> n >> k; //输入n和k，n是朋友的个数，k是开始的钱
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].a >> node[i].b; //输入每个朋友的位置和能给他多少钱
        
    }
    node[n+1].a=1e18; //朋友的位置最大是1e18
    sort(node+1,node+n+1); //按照位置从小到大排序
    long long cur = 0; // 当前位置
    for(int i=1;i<=n+1;i++) // 遍历每一个朋友
    {
        if(cur+k<node[i].a) //k就是有多少钱，cur+k就是他能走到的最大位置，如果位置小于下一个朋友的位置，他就不能到达下一个朋友
        {
            cout<<cur+k<<endl; //输出他能到达的最大位置
            return 0;
        }
        k = k - (node[i].a-cur); // 计算他走到这个朋友的花费
        cur = node[i].a; //更新当前位置
        k += node[i].b; //加上这个朋友给他的钱
    }    
    
    return 0;
}
