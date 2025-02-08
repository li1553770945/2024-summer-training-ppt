#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    // 计算震级差
    int level_diff = a - b;

    // 计算能量倍数
    int result = 1;
    for (int i = 1; i <= level_diff; ++i)
    {
        result *= 32;
    }

    cout << result << endl;

    return 0;
}
