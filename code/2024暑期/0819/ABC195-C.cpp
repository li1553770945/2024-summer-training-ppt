#include <iostream>
using namespace std;

long long calculate_commas(long long n)
{
    long long total_commas = 0;
    long long range_start = 1000; // 范围的起始数字

    // 处理每一范围的数字，逐步增加逗号数量
    for (int digits = 3; range_start <= n; digits += 3) // 刚刚说的级别，或者说是多少位数
    {
        long long range_end = range_start * 1000 - 1; // 每个级别的结束位置
        if (range_end > n) // 如果当前n没有覆盖完整个范围，就把范围的结束位置设为n
        {
            range_end = n;
        }
        //cout<<range_start<<" "<<range_end<<endl;
        
        total_commas += (range_end - range_start + 1) * (digits / 3); // 每个范围的逗号数量
        //range_end - range_start + 1表示这个范围内的数字个数，digits / 3表示这个范围内的每个数字的逗号数量
        
        range_start *= 1000;
    }

    return total_commas;
}

int main()
{
    long long n;
    cin >> n;
    cout << calculate_commas(n) << endl;
    return 0;
}
