#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 200000;
long long candy_count[MAX_N + 1]; // 从1开始索引的糖果计数数组

struct Citizen
{
    int id;
    int index;
    bool operator<(const Citizen &other) const
    {
        return id < other.id;
    }
} citizens[MAX_N + 1]; // 存储每个公民的身份证号和原始索引

int main()
{
    long long N;
    long long K;
    scanf("%lld%lld", &N, &K);

    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &citizens[i].id);
        citizens[i].index = i;
    }

    // 根据身份证号排序
    sort(citizens + 1, citizens + N + 1);
    //cout<<K<<" "<<N<<" "<<K/N<<endl;

    long long full_rounds = K / N; // 完整分发轮数
    int remaining_candy = K % N;   // 剩余糖果数量

    // 全部公民按完整轮数分配糖果
    for (int i = 1; i <= N; ++i)
    {
        candy_count[i] = full_rounds;
    }

    // 剩余糖果分配给身份证号码最小的公民
    for (int i = 1; i <= remaining_candy; ++i)
    {
        candy_count[citizens[i].index]++;
    }

    // 输出每位公民得到的糖果数量
    for (int i = 1; i <= N; ++i)
    {
        printf("%lld\n", candy_count[i]);
    }

    return 0;
}
