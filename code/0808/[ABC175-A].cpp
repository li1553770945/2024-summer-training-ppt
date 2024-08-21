#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int maxRainyStreak = 0; // 最大连续下雨天数
    int currentStreak = 0; // 当前连续下雨天数

    for (int i = 0; i < 3; ++i)
    {
        if (S[i] == 'R') // 如果第i天下雨
        {
            ++currentStreak; // 当前连续下雨天数加1
            if (currentStreak > maxRainyStreak) // 检查是否大于最大连续下雨天数
            {
                maxRainyStreak = currentStreak;
            }
        }
        else // 如果第i天不下雨
        {
            currentStreak = 0; // 重置当前连续下雨天数
        }
    }

    cout << maxRainyStreak << endl;

    return 0;
}
