    #include <iostream>
    using namespace std;
    char a[200010];
    int main()
    {
    
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='W')
            {
                cnt++;
            }
        }
        int ans = 0;
        for(int i=n-cnt+1;i<=n;i++)
        {
            if(a[i]=='R')
            {
                ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }