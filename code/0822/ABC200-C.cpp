#include <iostream>
#include <unordered_map>

using namespace std;

const int MAX_N = 200000;
int A[MAX_N + 1];

int main() 
{
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    // 使用一个哈希表来存储余数出现的次数
    unordered_map<int, int> remainder_count; // key: 余数，value: 余数出现的次数
    long long result = 0;

    for (int i = 1; i <= N; i++)
    {
        int remainder = A[i] % 200;
        
        // 查找有多少个已经存在的数与当前数相减可以是200的倍数
        
        
        // 更新余数出现的次数
        remainder_count[remainder]++;
    }

    cout << result << endl;

    return 0;
}
