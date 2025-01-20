#include<iostream>

using namespace std;

int main()
{
    int n, k; // 用于存储楼层数和每层房间数
    cin >> n >> k; //处理输入

    int total_sum = 0; // 用于存储所有房间号之和

    for (int i = 1; i <= n; ++i) // 从第1层到第N层
    {
        for (int j = 1; j <= k; ++j) // 从第1号房间到第K号房间
        {
            int room_number = i * 100 + j; // 计算房间号
            total_sum += room_number; // 累加房间号到总和
        }
    }

    cout << total_sum << endl; // 输出所有房间号之和

    return 0;
}
