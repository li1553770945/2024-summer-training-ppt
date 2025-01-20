#include <iostream>
using namespace std;

int main()
{
    int m, h;
    cin >> m >> h; // 输入

    // 检查怪物的生命值是否是 m 的倍数
    if (h % m == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
