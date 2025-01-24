#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    set<int>s;
    s.insert(0);
    s.insert(n);
    while(m--)
    {
        int x,y;
        scanf("%d%d", &x, &y); // 输入
        if(x==1) // 如果是操作一，直接把切割点加入到set中即可
        {
            s.insert(y);
        }
        else
        {
            auto l=s.upper_bound(y);
            //查找的其实是第一个大于当前位置的切割点
            auto r=l;
            l--;//指针左移一位，就是左边的切割点
            printf("%d\n", *r-*l);
        }
    }
 
    return 0;
}
