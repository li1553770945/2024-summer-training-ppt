#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 2010;
int a[maxn][maxn];
int dp[maxn][maxn];
int h,w;

int main()
{
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            char x;
            cin>>x;
            if(x=='+')
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=-1;
            }
        }
    }
    memset(dp,-0x3f3f3f3f,sizeof(dp));
    dp[1][1]=0;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(i==1&&j==1)
            {
                continue;
            }
            if((i+j)%2==0)
            {
                if(i>1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
                }
                if(j>1)
                {
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
                }
            }
            else
            {
                if(i>1)
                {
                    dp[i][j]=min(dp[i][j],dp[i-1][j]-a[i][j]);
                }
                if(j>1)
                {
                    dp[i][j]=min(dp[i][j],dp[i][j-1]-a[i][j]);
                }
            }
        }
    }
    if(dp[h][w]>0)
    {
        cout<<"Takahashi"<<endl;
    }
    else if(dp[h][w]<0)
    {
        cout<<"Aoki"<<endl;
    }
    else
    {
        cout<<"Draw"<<endl;
    }
}