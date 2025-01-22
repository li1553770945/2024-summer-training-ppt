#include <iostream>
#include <stack>
using namespace std;

const int maxn = 200010;
stack <int> s[maxn]; // s是圆柱体，s[i]表示第i个圆柱体上的球
int num2index[maxn]; //从颜色映射到第一个圆柱体，表示这个圆柱体的顶部是这个颜色
int anscnt;// 记录一共取走了多少对数字
void handle(int ia)
{
    if(s[ia].empty()) // 如果圆柱体已经空了，直接返回
    {
        return;
    }
    int num = s[ia].top();
    int ib = num2index[num]; // 查找当前颜色num是否已经出现过
    if(ib!=0) // 已经有这个数字了，ib就是上次出现num颜色的圆柱体的索引
    {
        anscnt++; // 找到了一个配对
        s[ia].pop(); // 把圆柱体顶部球拿掉
        s[ib].pop(); // 
        handle(ia); // 顶部发生变化，递归处理
        handle(ib);
    }
    else
    {
        num2index[num] = ia; // 记录一下已经出现过，并且索引是当前圆柱
    }
}   
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        
        int k;
        cin>>k;
        stack <int> temp;
        while(k--) //处理输入
        {
            
            int x;
            cin>>x;
            temp.push(x);
        }
        while(!temp.empty()) // 翻了一个顺序
        {
            s[i].push(temp.top());
            temp.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        handle(i); //处理圆柱体i
    }
    if(anscnt == n)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}