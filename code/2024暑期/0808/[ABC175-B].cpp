#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 判断三个长度是否可以组成三角形
bool can_form_triangle(int a, int b, int c)
{
    return a + b > c && a + c > b && b + c > a; // 任意两边之和大于第三边
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> lengths(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> lengths[i];
    }
    
    
    
    int count = 0;
    
    // 三重循环枚举所有三元组 (i, j, k)
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k) 
            {
                // 确保长度不同
                if (lengths[i] != lengths[j] && lengths[j] != lengths[k] && lengths[i] != lengths[k])
                {
                    if (can_form_triangle(lengths[i], lengths[j], lengths[k])) // 判断是否可以组成三角形
                    {
                        ++count;
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
