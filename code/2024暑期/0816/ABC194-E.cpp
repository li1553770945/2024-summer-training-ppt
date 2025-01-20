#include <iostream>
#include <set>
using namespace std;
const int inf = 0x3f3f3f3f;
int a[2000000];
set < int > not_have; // 有序集合，可以在logn的时间内完成插入，删除，查找操作
int cnt[2000000];
int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    int max_a = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        max_a = max(max_a, a[i]);
    }
    int ans = inf;
    for(int i=0;i<=max_a+1;i++)
    {
        not_have.insert(i); //把0到max_a+1插入到not_have中
    }
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++; // 当前数字出现次数+1
        if(cnt[a[i]]==1) // 第一次出现，之前的集合中有这个数字，现在没有了
        {
            not_have.erase(a[i]); // 移除这个数字
        }
        if(i>m)
        {
            cnt[a[i-m]]--; // 移除最前面的超出窗口的数字
            if (cnt[a[i-m]] == 0)  // 如果这个数字之前只有一个，现在没有了
            {
                not_have.insert(a[i-m]);  // 添加到集合中
            }
        }
        if(i>=m)
        {
            ans = min(ans, *not_have.begin()); // 取出集合中最小的数字，就是当前窗口的mex
        }
        
    }
    printf("%d\n", ans);
    return 0;
}