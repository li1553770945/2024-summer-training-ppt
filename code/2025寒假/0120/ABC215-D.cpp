#include<iostream>
using namespace std;

const int maxn = 1e6+5;

int n,m,i,j,x,ans,t,a[maxn],p[maxn];
bool f[maxn];

void find_factors(int x)
{
	f[x] = 1;	// x 一定是 x 的因数 
	for (int i=2; i*i<=x; i++)
		if (x%i == 0)	// i 是 x 的因数 
		{
			f[i] = true;
			f[x/i] = true;
		}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for (i=1; i<=n; i++)
	{
		cin >> x;
		find_factors(x);	//求出所有因数 
	}
	for (i=2; i<=maxn; i++)
		if (f[i]) 
            p[++t] = i;	//因数存放到数组p中 
	for (i=1; i<=m; i++)	//暴力枚举可能性 
	{
		for (j=1; j<=t; j++)
			if (i%p[j] == 0) 
                break;
		if (j == t+1) 
            a[++ans] = i; 
	}
	cout << ans << endl;
	for (i=1; i<=ans; i++)
		cout << a[i] << endl;
	return 0 ;
}