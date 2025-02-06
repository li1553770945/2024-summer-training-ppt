#include <iostream>
#include <string>
using namespace std;

// 定义全局字符串数组，S1, S2, S3分别对应三个字符串
string S[4];  // 注意索引从1开始使用

int main()
{
    // 读取输入
    cin >> S[1] >> S[2] >> S[3];
    string T;
    cin >> T;

    // 用于存储结果
    string result = "";

    // 按照T的顺序拼接S1, S2, S3
    for (int i = 0; i < T.length(); i++)
    {
        if (T[i] == '1')
        {
            result += S[1];  // 如果T[i]是'1'，连接S1
        }
        else if (T[i] == '2')
        {
            result += S[2];  // 如果T[i]是'2'，连接S2
        }
        else if (T[i] == '3')
        {
            result += S[3];  // 如果T[i]是'3'，连接S3
        }
    }

    // 输出最终的结果
    cout << result << endl;

    return 0;
}
