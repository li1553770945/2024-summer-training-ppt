#include <cstdio>
#include <algorithm>
#include <iostream> 
using namespace std;
const int maxn=5010;

long long p[maxn], c[maxn], t[maxn], d[maxn], mid[maxn]; // t[i]记录从位置i开始的周期内步数，d[i]记录周期内的总分，mid[i]记录周期内的最高分

int main()
{
    int n, k, i, now, cnt;
    long long mx = -1000000000, val;
    cin>>n>>k;
    for (i = 1; i <= n; i++)
    {
        cin>>p[i];
    }
    for (i = 1; i <= n; i++)
    {
        cin>>c[i];
    }
    for (i = 1; i <= n; i++) // 从每个位置出发
    {
        // 计算每个位置的周期、周期内分数及周期内最大分数
        now = p[i], d[i] = c[now], t[i] = 1, mid[i] = -1000000000;
        // now是当前位置，d[i]是当前周期走完的分数，t[i]是周期，mid[i]是周期内最大分数
        mid[i] = max(d[i], mid[i]);
        while (1) 
        {
            if (now == i) // 回到了起点，周期结束
                break;
            t[i]++; // 这个周期，走了多少步
            now = p[now]; // 走到下一个位置
            d[i] += c[now]; // 加上这个位置的分数
            mid[i] = max(d[i], mid[i]); // 更新最大分数
        }
    }
    for (i = 1; i <= n; i++) // 尝试从每个位置出发
    {
        if (k / t[i] > 0)  // 总步数超过当前周期，至少能走完一个周期
        {
            mx = max(mx, mid[i]); // 一个周期的最大分数
            if (k % t[i] == 0) // 正好走完最后一个周期
            {
                mx = max(mx, (k / t[i] - 1) * d[i] + mid[i]); // 前面的周期都走完，最后一个周期取最大
                continue;
            }
        }
        // 剩余步数，不能走完一个周期，直接模拟，最多走n步，
        val = k / t[i] * d[i];
        now = p[i], val += c[now], mx = max(mx, val), cnt = 1;
        while (1)
        {
            if (k % t[i] == cnt) break;
            cnt++;
            now = p[now];
            val += c[now];
            mx = max(mx, val);
        }
    }
    printf("%lld\n", mx);
    return 0;
}
