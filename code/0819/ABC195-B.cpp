#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, w;
    cin >> a >> b >> w;

    // 将千克转换为克
    w *= 1000;

    // 初始化最小和最大可能数量
    int min_count = 1e9, max_count = -1;

    // 遍历可能的橙子数量
    for (int i = 1; i <= 1000000; i++)
    {
        int min_weight = i * a;
        int max_weight = i * b;

        if (min_weight <= w && w <= max_weight)
        {
            min_count = min(min_count, i);
            max_count = max(max_count, i);
        }
    }

    // 根据条件输出结果
    if (max_count == -1)
    {
        cout << "UNSATISFIABLE";
    }
    else
    {
        cout << min_count << " " << max_count;
    }

    return 0;
}
