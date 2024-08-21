#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    long long b = 2147483647;
    int ans  = 0;
    ans += a*b; // int 和 long long 相乘，结果是 int
    cout<<ans<<endl;
}