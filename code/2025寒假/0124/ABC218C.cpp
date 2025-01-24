#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 210;

int n;
char s[MAX_N][MAX_N], t[MAX_N][MAX_N];
char rotated[MAX_N][MAX_N];

// 将图形S旋转90度
void rotate_90()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rotated[j][n - i + 1] = s[i][j];
        }
    }
}

// 检查旋转后的图形是否可以通过平移与T匹配
bool check_match()
{
    //cout<<"ABC"<<endl;
    // 找到旋转后图形的第一个#的位置
    int s_x = -1, s_y = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (rotated[i][j] == '#')
            {
                s_x = i;
                s_y = j;
                break;
            }
        }
        if (s_x != -1) break;
    }

    // 找到T的第一个#的位置
    int t_x = -1, t_y = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (t[i][j] == '#')
            {
                t_x = i;
                t_y = j;
                break;
            }
        }
        if (t_x != -1) break;
    }

    // 如果找不到#，说明图形为空，直接返回false
    if (s_x == -1 || t_x == -1) return false;

    // 计算平移的偏移量
    int dx = t_x - s_x;
    int dy = t_y - s_y;
    //cout<<s_x<<" "<<s_y<<endl;
    //cout<<t_x<<" "<<t_y<<endl;
    // 检查所有#是否匹配
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (rotated[i][j] == '#')
            {
                int new_x = i + dx;
                int new_y = j + dy;
                if (new_x < 1 || new_x > n || new_y < 1 || new_y > n || t[new_x][new_y] != '#')
                {
                    return false;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (t[i][j] == '#')
            {
                int new_x = i - dx;
                int new_y = j - dy;
                if (new_x < 1 || new_x > n || new_y < 1 || new_y > n || rotated[new_x][new_y] != '#')
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++)
        {
            s[i][j] = row[j - 1];
            rotated[i][j] = row[j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++)
        {
            t[i][j] = row[j - 1];
        }
    }

    // 尝试旋转0度、90度、180度、270度
    for (int r = 0; r < 4; r++)
    {
        if (check_match())
        {
            cout << "Yes" << endl;
            return 0;
        }
        rotate_90();
        // 将旋转后的图形赋值给s，以便下一次旋转
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                s[i][j] = rotated[i][j];
            }
        }
    }

    cout << "No" << endl;
    return 0;
}