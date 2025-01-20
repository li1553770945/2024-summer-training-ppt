#include <iostream>
#include <algorithm>
using namespace std;
int h,w,a,b;
int ans;
bool have[20][20]; // have[i][j]表示第i行第j列是否被覆盖

void dfs(int x,int y,int pos,int aa,int bb) //x,y表示当前位置，pos表示当前访问了多少个方块，aa,bb表示还剩多少个1*1和2*1的方块
{
    
    if(pos==h*w+1) //访问完所有方块
    {
        ans++; //方案数加1
        return;
    }
   
    int nx = x +1; //下一个位置,尝试往下走
    int ny = y;
    if(nx>h)
    {
        nx = 1;
        ny++;
    }
    if(have[x][y])
    {
        dfs(nx,ny,pos+1,aa,bb);
        return;
    }
    
    if(aa) // 如果1*2的还有剩余
    {
        if(x+1<=h&&!have[x][y]&&!have[x+1][y]) // 竖着摆放
        {
            have[x][y]=1;
            have[x+1][y]=1;
            dfs(nx,ny,pos+1,aa-1,bb);
            have[x][y]=0;
            have[x+1][y]=0;
        }
      
        if(y+1<=w&&!have[x][y]&&!have[x][y+1])
        {
            have[x][y]=1;
            have[x][y+1]=1;
            dfs(nx,ny,pos+1,aa-1,bb);
            have[x][y]=0;
            have[x][y+1]=0;
        }
    }
    if(bb)
    {
        have[x][y]=1;
        dfs(nx,ny,pos+1,aa,bb-1);
        have[x][y]=0;
    }

    
}
int main()
{
    cin>>h>>w>>a>>b;
    dfs(1,1,1,a,b);
    cout << ans << endl;
    return 0;
}