#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1010;

PII a[N], b[N];

bool cmp(PII x, PII y)
{
    return x.first < y.first;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].first, &b[i].first);
        a[i].second = i, b[i].second = i;
    }

    sort(a, a + n, cmp); // 排序
    sort(b, b + n, cmp);

    if (a[0].second == b[0].second) //完成A和B需要时间最短的是同一个人
    {
        int x = a[0].first + b[0].first; // 两个都交给这个人
       
        int y = max(b[1].first, a[0].first); // 第二个工作交给次快的人，第一个工作交给最快的人
        if (y < x)
        {
            x = y;
        }
        y = max(a[1].first, b[0].first); // 第一个工作交给次快的人，第二个工作交给最快的人
        if (y < x)
        {
            x = y;
        }
        cout << x << endl;
    }
    else
    {
        cout << max(a[0].first, b[0].first) << endl;
    }

    return 0;
}
