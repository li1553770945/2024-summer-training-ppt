#include <iostream>
#include <string>

using namespace std;

// 定义一个全局数组来存储输入的 P 数组
int p[27];  // p[0] 不使用，p[1] 到 p[26] 存储数据

int main()
{
    // 读取输入的 P 数组
    for (int i = 1; i <= 26; i++)
    {
        cin >> p[i];
    }

    // 创建一个字符串来存储结果
    string result = "";

    // 根据 P 数组的顺序，生成相应的字符
    for (int i = 1; i <= 26; i++)
    {
        result += char('a' + p[i] - 1); // 生成字母，p[i] 对应字母的位置
    }

    // 输出结果
    cout << result << endl;

    return 0;
}
