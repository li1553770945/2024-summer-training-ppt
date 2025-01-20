#include <iostream>
using namespace std;

bool check(int num)
{
    // 检查十进制中是否包含数字7
    for (int n = num; n > 0; n /= 10) // 每次mod 10,得到当前位十进制表示下的数字 ，然后除以10，去掉最后一位
    {
        if (n % 10 == 7) return false;
    }
    
    // 检查八进制中是否包含数字7
    for (int n = num; n > 0; n /= 8) // 8进制换成每次mod 8，然后除以8
    {
        if (n % 8 == 7) return false;
    }
    
    return true;
}

int main()
{
    int n;
    cin >> n;
    
    int count = 0;
    for (int i = 1; i <= n; i++) // 枚举i从1到N
    {
        if (check(i)) // 检查
        {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
