#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
const int maxn = 2000 + 5;
const int mod = 1e9 + 7;
map<long long,vector<long long> > q; // 映射，map[k] = {a_p1,a_p2}，表示k的倍数有a_p1,a_p2

int _gcd(int x,int y)
{
    if(x<y) swap(x,y);
    return y==0?x:_gcd(y,x%y);
}

int main()
{
    ios::sync_with_stdio(false);
    int n; 
    cin >> n;
    long long d = 1e9;
    for (int i = 1 ; i <= n ; i++)
    {
        long long x ; cin >> x;
        d = min(d , x);
        for (long long j = 1 ; j * j <= x ; j++) //对于每一个x，我们枚举他的所有因子
        {
            if (x % j == 0) // 如果j是x的因子
            {
                q[j].push_back(x); //j对应的倍数的集合中
                if (j * j != x)  // 如果j不是x的平方根
                {
                    q[x/j].push_back(x); // x/j对应的倍数的集合中
                }
            }
        }
    }
    int ans = 0;
    for (auto g : q)
    {
        if (g.first > d)  //g.first，即k的值，刚刚分析得到，k的值不会大于d
            break;
        long long gcd = g.second[0];
        for (auto k : g.second)  // 遍历所有的k的倍数
            gcd = _gcd(gcd , k); // 求这个集合的gcd
        if (gcd == g.first)  // 如果这个集合的gcd等于k
            ans++;
    }
    cout << ans << endl;
    return 0;
}