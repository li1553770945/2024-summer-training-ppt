#include <iostream>
#include <algorithm>
using namespace std;

// 定义最大范围的数组
const int MAX_N = 100000;
int A[MAX_N + 1];
int P[MAX_N + 1];
int X[MAX_N + 1];

int main()
{
    int N;
    cin >> N;

    // 输入各商店的数据
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i] >> P[i] >> X[i];
    }

    int min_price = -1;  // 最终答案

    // 遍历所有商店，计算高桥能购买到的最低价格
    for(int i = 1; i <= N; i++)
    {
        // 计算高桥到达时商店的库存
        if(X[i] > A[i]) // 如果到达的时候还有库存
        {
            if(min_price == -1 || P[i] < min_price)
            {
                min_price = P[i];
            }
        }
    }

    // 输出结果
    cout << min_price << endl;

    return 0;
}
