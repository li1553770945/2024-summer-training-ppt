#include <iostream>
using namespace std;

int main()
{
    // 输入A, B, C
    long long a, b, c;
    cin >> a >> b >> c;

    // 当C为0时, 任何数的0次幂都是1, 此时A和B的0次幂相等
    if (c == 0)
    {
        cout << "=" << endl;
        return 0;
    }

    // 检查A和B的符号
    // 当C为偶数时, 负数的幂变为正数
    if (c % 2 == 0)
    {
        a = abs(a);
        b = abs(b);
    }

    // 比较A和B
    if (a == b)
    {
        cout << "=" << endl;
    }
    else if (a > b)
    {
        cout << ">" << endl;
    }
    else
    {
        cout << "<" << endl;
    }

    return 0;
}
