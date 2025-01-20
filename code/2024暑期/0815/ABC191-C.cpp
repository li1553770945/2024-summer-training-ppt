#include <iostream>
using namespace std;
#define pb push_back
const int N = 1005;
string st;
int a[N][N],n,m,cnt=0;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>st;
        for (int j=1;j<=m;++j)
            if (st[j-1]=='.') 
                a[i][j]=0; // 0表示白色
            else 
                a[i][j]=1; // 1表示黑色，后面要统计黑色单元格的数量，所以直接用1表示黑色，计算时直接加即可
    }
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<m;++j) // 枚举所有四方格的子矩阵,i,j表示左上角的坐标
        {
            int c=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]; // 计算这个四方格的黑色单元格数量
            if (c==1 || c==3) ++cnt; // 如果有一个或者三个黑色单元格，那么这个四方格中间的点,i+1,j+1就是一个多边形的一条边
        }
    }
    cout<<cnt<<endl;
    return 0;
}