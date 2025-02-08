#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 函数：计算最大乘积
long long compute_max_product(string s)
{
    long long max_product = 0;
    
    // 尝试每一个可能的分割点
    for (int i = 1; i < s.length(); i++)
    {
        string part1 = s.substr(0, i);
        string part2 = s.substr(i);
        if(part1[0]=='0'||part2[0]=='0') 
            continue;

        // 转换为整数并计算乘积
        long long num1 = stoll(part1);
        long long num2 = stoll(part2);
        if(num1==0||num2==0) 
            continue;
        long long product = num1 * num2;
        // 更新最大乘积
        if (product > max_product)
        {
            max_product = product;
        }
    }
    return max_product;
}

int main()
{
    string n;
    cin >> n; // 输入数字，当成字符串用
    long long ans = -1;
    sort(n.begin(), n.end()); // 从小到大排序，为了方便后面的全排列
    do
    {
        long long product = compute_max_product(n);
        ans = max(ans, product);
    } while (next_permutation(n.begin(), n.end())); // 生成下一个排列
    cout<<ans<<endl;
    return 0;
}
