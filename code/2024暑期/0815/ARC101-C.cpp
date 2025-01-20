#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_N = 100005; // 定义数组的最大范围
int x[MAX_N]; // 存储每支蜡烛的位置

int main()
{
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    
    int min_time = 2147483647; // 初始化最短时间为极大值
    
    // 从左到右，尝试每种点燃 K 支蜡烛的可能性，枚举起点，左端点，start左端点
    for (int start = 1; start <= n - k + 1; ++start)
    {
        int end = start + k - 1; // 起点 + k -1，这一段的长度就是k
        int left = x[start]; // 最左侧蜡烛的位置
        int right = x[end]; // 最右侧蜡烛的位置
        int time = 0; // 计算时间
        
        // 比较从左边或右边开始点蜡烛的时间
        if (left < 0 && right > 0) // 如果蜡烛跨越了原点
        {
            // 点燃过程中计算移动时间的两种方案
            int time1 = abs(left) + (right - left); // 先向左再向右
            int time2 = right + (right - left); // 先向右再向左
            time = min(time1, time2);
        }
        else // 所有蜡烛都在一侧
        {
            time = max(abs(left), abs(right));
        }
        
        // 更新最小时间
        min_time = min(min_time, time);
    }
    
    cout << min_time << endl;
    return 0;
}
