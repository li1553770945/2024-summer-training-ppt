#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;  // 假设N的最大值
long long a[MAX_N];  // 存储每个游乐设施的初始乐趣值

int main()
{
    long long n, k;  // n: 游乐设施数量，k: 最大乘坐次数
    cin >> n >> k;

   
    // 输入乐趣值并放入优先队列
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    a[n+1] = 0;
    long long ans = 0;
    for(long long i=1;i<=n;i++)
    {
        long long t = a[i]-a[i+1];
        if(t*i<=k)
        {
            ans+=(a[i]+a[i+1]+1)*t*i/2;
            k-=t*i;
        }
        else
        {
            int x = k/i;
            ans+=(a[i]+a[i]-x+1)*x/2*i;
            ans+= (a[i]-x) * (k%i);
            k=0;
        }
    }
    cout<<ans<<endl;
}