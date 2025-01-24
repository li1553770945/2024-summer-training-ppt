#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 定义输入字符串S和T
    string s, t;
    
    // 读取输入
    cin >> s >> t;
    
    // 比较S和T的字典序
    if (s < t)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}
