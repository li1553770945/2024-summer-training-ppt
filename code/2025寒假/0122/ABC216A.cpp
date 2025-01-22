#include <iostream>
using namespace std;

int main()
{
    double x;
    int y;
    cin >> x;
    int int_part = x; // X部分
    y = (x - int_part) * 10; // Y部分

    // 根据Y的值输出不同的符号
    if (y >= 0 && y <= 2)
    {
        cout << int_part << "-";
    }
    else if (y >= 3 && y <= 6)
    {
        cout << int_part;
    }
    else if (y >= 7 && y <= 9)
    {
        cout << int_part << "+";
    }

    return 0;
}
