#include <iostream>
#include <unordered_set>
using namespace std;

int main() 
{
    int K;
    cin >> K; // 输入K

    if (K % 2 == 0 || K % 5 == 0) // 如果K是2或者5的倍数，输出-1
     {
        cout << -1 << endl;
        return 0;
    }

    int current = 7; // 序列中的第一个数字
    unordered_set<int> seen; // 用来存储已经出现过的余数

    for(int i=1;i<=1000000;i++)  
    {
        int remainder = current % K; // 余数
        if (remainder == 0)  // 如果余数为0，输出当前是第几个数字
        {
            cout << i << endl;
            break;
        }
        if (seen.count(remainder))  // 如果余数已经出现过，开始循环了，没有满足题目要求的数字
        {
            cout << -1 << endl;
            break;
        }
        seen.insert(remainder); // 记录出现过的余数
        current = (remainder * 10 + 7) % K; // 计算序列的下一个数字
    }

    return 0;
}
