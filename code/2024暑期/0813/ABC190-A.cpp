#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    if (c == 0)  // 如果高桥先开始
    {
        if (a > b)
        {
            cout << "Takahashi";
        }
        else
        {
            cout << "Aoki";
        }
    }
    else  // 如果青木先开始
    {
        if (b > a)
        {
            cout << "Aoki";
        }
        else
        {
            cout << "Takahashi";
        }
    }
    
    return 0;
}
