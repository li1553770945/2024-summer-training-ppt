#include <cstdio>
using namespace std;
int n, q;
long long a[100001], k; // 十年 OI 一场空，不开 long long 见祖宗。

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]); // 处理输入
    while (q--) // 每次查询
    {
        scanf("%lld", &k); // 输入k
        int l = 0, r = n; // 二分查找的l和r
        while (l < r) // 二分查找
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid] - mid < k) // 题解给出的判断条件，就是mid之前缺失的数字有多少个
                l = mid;
            else
                r = mid - 1;
        }
        printf("%lld\n", k + l); // 输出
    }
    return 0;
}