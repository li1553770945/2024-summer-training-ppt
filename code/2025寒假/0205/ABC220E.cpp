#include <iostream> 
#include <algorithm>
#include <math.h>

using namespace std;

const long long N = 1e7 + 10;
const long long mod = 998244353;

long long n, d, ans;

long long power(long long a, long long b) // 快速幂
{
    long long ans = 1;
    while (b)
    {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main()
{
    cin >> n >> d; // 输入
    for (long long i = 0; i <= d; i++) // 左边长度
    {
        long long j = d - i; // 右边长度
        if (max(i, j) >= n)
            continue; // 如果左边或右边长度大于总深度则无法取到
        long long root = (power(2, n - max(i, j)) - 1) % mod; // 根节点选择数
        long long l = power(2, max(0LL, i - 1)) % mod; // 右子树节点选择数
        long long r = power(2, max(0LL, j - 1)) % mod; // 左子树节点选择数
        ans = (ans + 2 * root % mod * l % mod * r % mod) % mod; // 当前情况总方案数
    }
    cout << (ans + mod) % mod << endl; // 输出
    return 0; // 收场
}
