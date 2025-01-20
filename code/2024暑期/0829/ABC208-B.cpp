#include <iostream>
using namespace std;

// 预计算1!到10!的值
int factorial[11];

// 计算阶乘函数
void calculate_factorials() 
{
    factorial[0] = 1; // 0! = 1
    for (int i = 1; i <= 10; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
}

int main() {
    int P;
    cin >> P;

    calculate_factorials(); // 计算1!到10!的值

    int coins_needed = 0; // 需要的硬币数量

    // 从最大的硬币面值开始使用
    for (int i = 10; i > 0; --i) 
    {
        int use = min(100, P / factorial[i]); // 计算可以使用的硬币数量，不超过100枚
        P -= use * factorial[i]; // 减去已经使用的硬币总价值
        coins_needed += use; // 增加硬币计数
    }

    cout << coins_needed << endl;

    return 0;
}
