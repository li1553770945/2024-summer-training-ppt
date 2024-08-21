#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    unordered_set<long long> expressed_numbers; // 保存已经表达过的数
    // unordered_set无序的集合，可以用来保存不重复的数据，查找速度快

    for (long long a = 2; a * a <= N; a++) // 枚举a，范围是[2, sqrt(N)]
    {
        for (long long b = 2; pow(a, b) <= N; b++) // 枚举b，一直到a的b次方大于N
        {
            expressed_numbers.insert(pow(a, b)); // 插入a的b次方，如果有重复的话，不会插入
        }
    }

    long long count_unexpressed = N - expressed_numbers.size(); // N 减掉集合的数量，也就是能被表示成a的b次方的数的数量

    cout << count_unexpressed << endl;

    return 0;
}
