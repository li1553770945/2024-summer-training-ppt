#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010, mod = 998244353;
int f[N][11][1 << 11];//前i场比赛,在二进制下打过k中数位为1的场次，且最后一场打j的方案数
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    
    for(int i = 1; i <= n; i ++)
    {
        int c = s[i - 1] - 'A'; 
        f[i][c][1 << c] = 1;//初始化第一场比赛
        for(int k = 0; k < 10; k ++)
        {//枚举上一场参加的比赛
            for(int j = 1; j < (1 << 10); j ++)
            {//枚举之前参加的所有比赛

                f[i][k][j] = (f[i][k][j] + f[i - 1][k][j]) % mod; //第i场比赛不打

                if(!(j >> c & 1) || c == k)
                {//第i场比赛打，前提是之前没打过或者之前最后一场打的就是s[i],可以接着打
                    int tmp = j + (1 << c) * (!(j >> c & 1));
                    f[i][c][tmp] = (f[i][c][tmp] + f[i - 1][k][j]) % mod;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < 10; i ++)
    {
        for(int j = 1; j < (1 << 10); j ++)
        {
            ans = (ans + f[n][i][j]) % mod;
        }
    }
    cout << ans;
    return 0;
}