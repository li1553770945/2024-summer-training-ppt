#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;
    
    int century;
    
    // 计算世纪数，如果年份能整除100，则世纪数为年份除以100，否则为年份除以100再加1
    if (N % 100 == 0)
    {
        century = N / 100;
    }
    else
    {
        century = N / 100 + 1;
    }

    /*
     int century = (N + 99) / 100;
     */
    
    // 输出结果
    cout << century << endl;
    return 0;
}
