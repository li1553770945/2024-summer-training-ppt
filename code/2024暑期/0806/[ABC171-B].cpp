#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    int N, K;
    cin >> N >> K;

    vector<int> prices(N); // 价格数组，存储每种水果的价格
    for (int i = 0; i < N; ++i) 
    {
        std::cin >> prices[i]; // 输入每种水果的价格
    }

    // 将价格数组排序
    std::sort(prices.begin(), prices.end()); 

    // 计算最低的 K 个价格的总和
    int min_total_price = 0;
    for (int i = 0; i < K; ++i) // 取前 K 个价格
    {
        min_total_price += prices[i]; // 计算前K个价格的总和
    }

    cout << min_total_price << std::endl;

    return 0;
}
