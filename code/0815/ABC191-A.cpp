#include <iostream>

using namespace std;

int main()
{
    // 定义输入变量
    int V, T, S, D;
    
    // 读取输入
    cin >> V >> T >> S >> D;
    
    // 计算球在T秒和S秒时的距离
    int distance_at_T = V * T;
    int distance_at_S = V * S;
    
    // 判断球在距离D时是否可见
    if(D < distance_at_T || D > distance_at_S)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}
