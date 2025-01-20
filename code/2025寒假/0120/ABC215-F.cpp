#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, mi[N], mx[N];
pair<int,int> a[N];

bool check(int x) {
    int i = 1; // 双指针i,j
    for (int j = 2; j <= n; ) 
    {
        if (a[j].first - a[i].first >= x)  // j后面所有点，x与i的x的距离都是大于等于x的
        {
            // 存在一个点，y的差值的绝对值大于等于x
            if (mx[j] - a[i].second >= x)  
                return true;
            if (a[i].second - mi[j] >= x) 
                return true;
            i++;
        }
        else j++; // 如果x都不满足，j向右移动，增大x的距离
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
    cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);

    mi[n] = mx[n] = a[n].second;
    for (int i = n - 1; i >= 1; i --)  // 从后往前记录到i位置，y的最大值和最小值
    {

        mi[i] = min(mi[i + 1], a[i].second);
        mx[i] = max(mx[i + 1], a[i].second);
    }

    int l = 0, r = 2e9, mid;
    while (l < r) // 二分答案
    {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;
}