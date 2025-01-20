#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=810;
int a[maxn][maxn];
int b[maxn][maxn];
int k,n;
bool check(int x)
{

    int cnt= k * k / 2; // 第几个位置，index
    if(k%2==1)
    {
        cnt++;
    }
    memset(b,0,sizeof(b)); // b数组用于计算前缀和
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]<=x)
            {
                b[i][j]=1;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1]; // 计算二维前缀和
        }
    }
    for(int x1=1;x1<=n-k+1;x1++) //枚举所有的k*k的矩形
    {
       
        int x2=x1+k-1;
        for(int y1=1;y1<=n-k+1;y1++)
        {
            
            int y2=y1+k-1;
            int sum = b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1]; // 有多少个位置的数字是小于或者等于x的
            if(sum>=cnt) // 如果这个矩形中有至少cnt个位置的数字小于或者等于x，当前的x大于等于中位数
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int l=0,r=1e9;
    while(l<r) // 二分答案，直接二分可能的中位数
    {
        int mid = (l+r)/2;
        if(check(mid)) // 如果mid能是中位数，尝试更小的
        {
            r=mid;
        } 
        else // 尝试更大的
        {
            l=mid+1;
        }
    }
    printf("%d\n",l);
    return 0;
}