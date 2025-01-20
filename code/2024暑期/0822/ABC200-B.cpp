#include <iostream>
#include <string>

using namespace std;

long long n, k;

int main()
{
    // 读取输入
    cin >> n >> k;

    // 执行 k 次操作
    for(int i = 1; i <= k; i++)
    {
        if(n % 200 == 0)
        {
            // 如果 N 是 200 的倍数，将其除以 200
            n /= 200;
        }
        else
        {
            // 否则，将 N 视为字符串并在末尾添加 200
            n = stoll(to_string(n) + "200");
        }
    }

    // 输出最终结果
    cout << n << endl;

    return 0;
}
