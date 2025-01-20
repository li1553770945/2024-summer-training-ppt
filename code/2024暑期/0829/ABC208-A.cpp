#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; // 输入a和b

    int min_sum = a;      // 最小和：全部掷出1
    int max_sum = 6 * a;  // 最大和：全部掷出6

    // 判断B是否在最小和与最大和之间
    if (b >= min_sum && b <= max_sum)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
