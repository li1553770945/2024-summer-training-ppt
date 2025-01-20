#include <iostream>
using namespace std;

int n, m, k;
int a[101], b[101];
int c[17], d[17];
int max_satisfied = 0;

void dfs(int index, int plates[101])
{
    if (index > k)  // 当所有人都放置了球之后
    {
        int count = 0;
        for (int i = 1; i <= m; i++)  // 遍历所有的条件，计算有多少条件被满足
        {
            if (plates[a[i]] > 0 && plates[b[i]] > 0)
            {
                count++;
            }
        }
        max_satisfied = max(max_satisfied, count); // 每次dfs结束都计算，所有dfs结果中最大的值就是最终结果
        return;
    }

    // 选择C_i位置放球
    plates[c[index]]++;
    dfs(index + 1, plates); // 递归调用dfs函数，继续放下一个球
    plates[c[index]]--; // 回溯

    // 选择D_i位置放球
    plates[d[index]]++;
    dfs(index + 1, plates);
    plates[d[index]]--;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
    }

    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i] >> d[i];
    }

    int plates[101] = {0};  // 初始化盘子数组，记录球的数量
    dfs(1, plates);  // 使用深度优先搜索（DFS）来尝试所有放球的可能

    cout << max_satisfied;  // 输出最大可以满足的条件数
    return 0;
}
