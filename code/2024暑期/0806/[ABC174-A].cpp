#include <iostream>
using namespace std;
int main()
{
    int x;
    cin>>x; // 输入一个整数 x，就是当前温度
    if(x>=30) // 如果温度大于或者等于30度，需要开空调，输出 Yes
    {
        cout<<"Yes";
    }
    else // 否则输出 No
    {
        cout<<"No";
    }
    return 0;
}