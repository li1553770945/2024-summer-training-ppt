#include <iostream>
using namespace std;

const int N = 405;
int n, m, p, i, j, k, l, s[N][N], a[N], b[N], A;
int main() 
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) 
            cin >> p, s[i][j] = s[i - 1][j] + p;

    for (i = 0; i < n; i++)
        for (j = i; j <= n; j++) 
        {
            l = 0;
            for (k = 1; k <= m; k++) 
                a[k] = a[k - 1] + s[j][k] - s[i][k], b[k] = std::min(b[k - 1], a[k]);
            // a[k]表示从第 i 行到第 j 行，第 1 列到第 k 列的累计和，b[k]表示累计到第k列时，前面所有a[k]的最小值。

            
            for (k = 1; k <= m; k++)
                while (l < k && a[k] > b[k - l - 1]) 
                    l++;
            /* 这里的思路是，
            如果 a[k]（到当前列的累计和）大于从当前列向左扩展 l 列的最小累计和 b[k - l - 1]，
            则意味着至少存在一个位置，累计和是非负的，可以尝试增加 l。
            */
            A = max(A, (j - i) * l);
        }
    cout << A;
}