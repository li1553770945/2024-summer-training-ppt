#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n; // 读取不含税的价格N

    // 计算含税价格，按照题目描述使用floor函数取整
    int taxed_price = 1.08 * n;

    // 根据含税价格与206的比较，输出对应结果
    if (taxed_price < 206)
    {
        cout << "Yay!" << endl;
    }
    else if (taxed_price == 206)
    {
        cout << "so-so" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }

    return 0;
}
