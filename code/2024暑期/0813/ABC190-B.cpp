#include <iostream>
using namespace std;

int main()
{
    int n, s, d;
    cin >> n >> s >> d;

    bool can_damage = false;  // 用来记录是否有咒语能对怪物造成伤害
    for (int i = 1; i <= n; i++) 
    {
        int x, y;
        cin >> x >> y;
        
        // 判断咒语是否有效
        if (x < s && y > d)
        {
            can_damage = true;
            break; // 如果找到有效咒语，立即退出循环
        }
    }
    
    if (can_damage)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
    return 0;
}
