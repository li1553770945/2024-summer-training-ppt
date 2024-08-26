#include <cstdio>
using namespace std;
int n, q;
long long a[100001], k; // 十年 OI 一场空，不开 long long 见祖宗。

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    while (q--)
    {
        scanf("%lld", &k);
        int l = 0, r = n;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid] - mid < k)
                l = mid;
            else
                r = mid - 1;
        }
        printf("%lld\n", k + l); // 输出
    }
    return 0;
}