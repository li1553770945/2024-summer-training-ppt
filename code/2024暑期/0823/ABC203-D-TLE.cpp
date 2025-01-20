#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=810;
int a[maxn][maxn];
int k,n;
bool check(int x)
{

    int cnt= k * k / 2;
    if(k%2==1)
    {
        cnt++;
    }
    int sum=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(a[i][j]<=x)
            {
                sum++;
            }
        }
    }

    // cout<<"x="<<x<<" start sum="<<sum<<endl;
    int row_sum = sum;
    for(int x1=1;x1<=n-k+1;x1++)
    {
       
        int x2=x1+k-1;
        if(x1>1)
        {
            for(int i=1;i<=k;i++)
            {
                if(a[x1-1][i]<=x)
                {
                    row_sum--;
                }
                if(a[x2][i]<=x)
                {
                    row_sum++;
                }
            }
        }
        sum = row_sum;
        for(int y1=1;y1<=n-k+1;y1++)
        {
            
            int y2=y1+k-1;
            if(y1>1)
            {
                for(int i=x1;i<=x2;i++)
                {
                    if(a[i][y1-1]<=x)
                    {
                        sum--;
                    }
                    if(a[i][y2]<=x)
                    {
                        sum++;
                    }
                }
            }
            if(sum>=cnt)
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
    while(l<r)
    {
        int mid = (l+r)/2;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    printf("%d\n",l);
    return 0;
}