#include <iostream>
using namespace std;

const int MAX_N = 100000;  // 假设最大N为10^5
long long a[MAX_N + 1];    // 存储序列A

int main()
{
    int n;             // 序列A的长度
    long long x;      // 要超过的累加和X
    cin >> n;

    // 输入序列A
    long long sum_A = 0;  // A序列的总和
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum_A += a[i]; // 累加A序列的和，也就是题解里面说的一个完整的A
    }

    cin >> x;

    long long total_sum = 0;  // 当前B序列的总和
    long long k = 0;                // 当前找到的k值

    // 计算需要多少个完整的A序列
    long long full_repeats = (x / sum_A);  // 完整A序列的个数
    total_sum = full_repeats * sum_A; // 加上这么多个完整的A
    k = full_repeats * n;  // k加了full_repeats个完整的A序列
    

    // 加上剩余部分，直到总和超过x
    while (total_sum <= x) // 最多只会进行n次
    {
        k++;
        total_sum += a[(k - 1) % n + 1];
    }

    cout << k << endl;

    return 0;
}
