#include <iostream>
#include <map>
using namespace std;

const int N=1e6+100;

long long ma=1e18;


long long dp[2][3030][4];
map <int,int> a[3030];
int main()
{
    int r,c,k;
    scanf("%d%d%d",&r,&c,&k);
    for(int i=1;i<=k;i++)
    {
        int x,b,cc;
        scanf("%d%d%d",&x,&b,&cc);
        a[x][b]=cc;
    }

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            for(int rr=0;rr<=3;rr++)
            {
                dp[i%2][j][0]=max(dp[i%2][j][0],max(dp[(i-1)%2][j][rr],dp[i%2][j-1][0]));
            }

            for(int rr=0;rr<=3;rr++)
            {
                dp[i%2][j][1]=max(max(dp[(i-1)%2][j][rr]+a[i][j],dp[i%2][j][1]),max(dp[i%2][j-1][0]+a[i][j],dp[i%2][j-1][1]));
            }
            dp[i%2][j][2]=max(dp[i%2][j-1][1]+a[i][j],dp[i%2][j-1][2]);
            dp[i%2][j][3]=max(dp[i%2][j-1][2]+a[i][j],dp[i%2][j-1][3]);
        }
    }
    long long ans=0;
    for(int i=0;i<=3;i++)
    {
        ans=max(ans,dp[0][c][i]);
        ans=max(ans,dp[1][c][i]);
    }
    printf("%lld\n",ans);
    return 0;
}
