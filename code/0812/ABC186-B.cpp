#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_H = 101;
const int MAX_W = 101;
int a[MAX_H][MAX_W];

int main()
{
    int h, w;
    cin >> h >> w;
    int min_blocks = 101; // 由于块的数量不会超过100，设置初始最小值为101

    // 读取输入数据，并找到最小块数
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j]; // 输入块数
            if (a[i][j] < min_blocks)
            {
                min_blocks = a[i][j]; // 找到最小块数
            }
        }
    }

    int result = 0;
    // 计算需要移除的块数
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            result += a[i][j] - min_blocks; // 移除到最小块数的差值
        }
    }

    cout << result << endl;
    return 0;
}
