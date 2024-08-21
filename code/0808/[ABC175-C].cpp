#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // 读取输入
    long long x, k, d;
    cin >> x >> k >> d;

    // 计算初始绝对值
    x = abs(x);

    // 计算到0的步数
    long long steps_to_zero = x / d;

    if (steps_to_zero >= k)
    {
        // 如果在k步内无法到达0，直接输出结果
        cout << x - k * d << endl;
    }
    else
    {
        // 计算剩余的步数
        long long remaining_steps = k - steps_to_zero;

        // 根据剩余步数判断最终位置
        if (remaining_steps % 2 == 0)
        {
            // 剩余步数为偶数，最终绝对值为直接到达的距离
            cout << x % d << endl;
        }
        else
        {
            // 剩余步数为奇数，最终绝对值为移动一次后的距离
            cout << abs((x % d) - d) << endl;
        }
    }

    return 0;
}
