#include <iostream>
#include <string>
using namespace std;

// 定义全局变量，存储所有可能的比赛系列
string contests[5] = {"", "ABC", "ARC", "AGC", "AHC"};

// 定义全局变量，用于标记输入的比赛系列
bool used[5] = {false};

int main()
{
    // 输入三个比赛系列
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    // 标记输入的比赛系列
    for (int i = 1; i <= 4; i++)
    {
        if (s1 == contests[i] || s2 == contests[i] || s3 == contests[i])
        {
            used[i] = true;
        }
    }

    // 遍历所有比赛系列，找到未被标记的那个
    for (int i = 1; i <= 4; i++)
    {
        if (!used[i])
        {
            cout << contests[i] << endl;
            break;
        }
    }

    return 0;
}