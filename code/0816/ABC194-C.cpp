#include <iostream>
using namespace std;

const int MAX_N = 300005;
int a[MAX_N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long sum = 0, sum_squares = 0; // sum是前i-1项求和，sum_squares是前i-1项的平方和
    long long result = 0;
    for(int i = 1; i <= n; i++)
    {
        result += (long long)(i - 1) * a[i] * a[i] - 2 * a[i] * sum + sum_squares;
        sum += a[i];
        sum_squares += (long long)a[i] * a[i];
    }

    cout << result << endl;

    return 0;
}
