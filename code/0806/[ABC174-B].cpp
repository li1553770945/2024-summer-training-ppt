#include <iostream>
using namespace std;
int main()
{
    long long N, D;
    cin >> N >> D; // 输入整数 N 和 D，点的数量和最大的距离
    int count = 0;
    for (int i = 0; i < N; ++i)  // 循环输入每个点的坐标
    {
        long long X, Y;
        cin >> X >> Y; // 输入点的坐标
        if (X * X + Y * Y <= D * D)  // 距离不超过D的点
        {
            ++count; // 计数加1
        }
    }
    cout << count << endl;
    return 0;
}