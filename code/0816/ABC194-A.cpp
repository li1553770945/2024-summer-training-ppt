#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b; // 输入非脂乳固体百分比A和乳脂百分比B
    
    int total_milk_solid = a + b; // 总乳固体百分比

    if (total_milk_solid >= 15 && b >= 8) // 判断是否为冰淇淋
    {
        cout << 1 << endl;
    }
    else if (total_milk_solid >= 10 && b >= 3) // 判断是否为冰奶
    {
        cout << 2 << endl;
    }
    else if (total_milk_solid >= 3) // 判断是否为乳冰
    {
        cout << 3 << endl;
    }
    else // 不属于以上任何类别，是调味冰
    {
        cout << 4 << endl;
    }

    return 0;
}
