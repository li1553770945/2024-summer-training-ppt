#include <iostream>
#define int long long
using namespace std;
main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	int x[n+1][m+1];
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>x[i][j];
	int maxv=INT_MIN;
	for(int x1=1;x1<=n;++x1)
		for(int y1=1;y1<=m;++y1)
			for(int x2=x1+1;x2<=n;++x2)
				for(int y2=y1+1;y2<=m;++y2)
				{
					int sum=0,cnt=0;
					for(int i=x1;i<=x2;++i)
                        for(int j=y1;j<=y2;++j,++cnt)
                            sum+=x[i][j];
					if(sum>0)maxv=max(cnt,maxv);
				}
	cout<<maxv;
	return 0;
}