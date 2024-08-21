#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;
long long a[MAX_N + 1];

int main()
{
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; // 输入数组元素
    }
    
    // 对数组进行排序以便计算差值之和，就不用计算绝对值了
    sort(a + 1, a + n + 1);
    
    long long sum_diff = 0; // 答案
    long long sum_prefix = 0; // 前面数字求和
    
    // 遍历数组计算差值之和
    for (int j = 2; j <= n; j++)
    {
        sum_prefix += a[j - 1]; // 前面数字求和，O(1)时间复杂度
        sum_diff += a[j] * (j - 1) - sum_prefix;  // 利用刚刚的公式计算, O(1)时间复杂度
    }
    
    cout << sum_diff << endl;
    
    return 0;
}
