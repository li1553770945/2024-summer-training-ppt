#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    // 计算最大 k，使得 2^k <= n
    long long k = 0;
    while (true)
    {
        if(pow(2LL, k) <= n)
        {
            //cout<<k<<" "<<pow(2LL, k)<<" "<<n<<" "<<((1LL << k) -n)<<endl;
            k++;
        }
        else
        {
            break;
        }
    }

    // 输出 k-1，因为在退出循环时 k 会多加一
    cout << k - 1 << endl;

    return 0;
}
