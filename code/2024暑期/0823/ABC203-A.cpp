#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b) // 如果a和b相等，则输出c
    {
        cout << c << endl;
    }
    else if (a == c) // 如果a和c相等，则输出b
    {
        cout << b << endl;
    }
    else if (b == c) // 如果b和c相等，则输出a
    {
        cout << a << endl;
    }
    else // 如果没有任何两个数相等，则输出0
    {
        cout << 0 << endl;
    }

    return 0;
}
