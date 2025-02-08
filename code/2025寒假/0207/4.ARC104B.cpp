#include<iostream>
using namespace std;
const int maxm=1e6+5;
char s[maxm];
int sum1[maxm];
int sum2[maxm];
int n;

int main()
{
    cin>>n>>(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='A')
        {
            sum1[i]=1;
        }else if(s[i]=='T')
        {
            sum1[i]=-1;
        }else if(s[i]=='C')
        {
            sum2[i]=1;
        }else if(s[i]=='G')
        {
            sum2[i]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        sum1[i]+=sum1[i-1];
        sum2[i]+=sum2[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(sum1[j]-sum1[i-1]==0&&sum2[j]-sum2[i-1]==0)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}