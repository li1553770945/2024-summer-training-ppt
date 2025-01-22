#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_Q = 200000;  // 最大查询数

int query_type[MAX_Q];  // 存储每个查询的类型
int x_values[MAX_Q];    // 存储查询类型为1时的x值
int A[MAX_Q];           // 序列A
int front = 0;          // 序列A的前端指针
int back = 0;           // 序列A的尾端指针

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Q;  // 查询数
    cin >> Q;
    
    // 读取查询
    for (int i = 0; i < Q; i++)
    {
        cin >> query_type[i];  // 查询类型
        if (query_type[i] == 1)
        {
            cin >> x_values[i];  // 查询类型为1时读取x值
        }
    }
    
    // 处理查询
    for (int i = 0; i < Q; i++)
    {
        if (query_type[i] == 1)
        {
            A[back++] = x_values[i];  // 将x追加到序列A末尾
        }
        else if (query_type[i] == 2)
        {
            cout << A[front++] << endl;  // 打印并删除A的第一个元素
        }
        else if (query_type[i] == 3)
        {
            // 按升序排序A
            sort(A + front, A + back);
        }
    }
    
    return 0;
}
