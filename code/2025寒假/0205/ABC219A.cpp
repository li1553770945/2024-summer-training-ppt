#include <iostream>

using namespace std;

int main()
{
    int x; // 分数
    cin >> x;

    if (x >= 90) // 已是Expert等级
    {
        cout << "expert";
    }
    else if (x >= 70) // Advanced等级，需要升级到Expert
    {
        cout << 90 - x; // 计算升级到90分需要的分数
    }
    else if (x >= 40) // Intermediate等级，需要升级到Advanced
    {
        cout << 70 - x; // 计算升级到70分需要的分数
    }
    else // Novice等级，需要升级到Intermediate
    {
        cout << 40 - x; // 计算升级到40分需要的分数
    }

    return 0;
}
