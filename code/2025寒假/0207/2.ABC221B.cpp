#include <iostream>
#include <string>
using namespace std;

const int MAX_LEN = 101;  // 最大字符串长度

// 判断 S 和 T 是否相等
bool can_swap_to_equal(string s, string t) 
{
    // 如果两个字符串已经相等，直接返回 Yes
    if (s == t) 
    {
        return true;
    }

    // 记录不同的字符位置
    int diff_index[2];  // 用来存储不同的字符下标，最多有两个
    int diff_count = 0; // 有几个不相等的位置

    // 找出两个字符串不同的位置
    for (int i = 1; i <= s.length(); i++) 
    {
        if (s[i - 1] != t[i - 1]) 
        {
            if (diff_count == 2) return false;  // 超过两个不同的位置，不能通过一次交换变相等
            diff_index[diff_count++] = i;  // 记录下标
        }
    }

    // 如果有两个不同位置的字符，并且它们是相邻的，交换后能变相等
    if (diff_count == 2 && diff_index[1] - diff_index[0] == 1) 
    {
        return s[diff_index[0] - 1] == t[diff_index[1] - 1] &&
               s[diff_index[1] - 1] == t[diff_index[0] - 1];
    }

    return false;
}

int main() 
{
    string s, t;
    cin >> s >> t;

    if (can_swap_to_equal(s, t)) 
    {
        cout << "Yes" << endl;
    } else 
    {
        cout << "No" << endl;
    }

    return 0;
}
