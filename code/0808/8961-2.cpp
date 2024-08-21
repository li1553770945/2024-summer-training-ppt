#include<iostream>
using namespace std;
long long sum=0,m,n,a[500][500]={0},x;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			a[i][j]=x+a[i][j-1];
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			a[i][j]+=a[i-1][j];
		}
	}
	for(long long i=1;i<n;i++){
		for(long long i2=i+1;i2<=n;i2++){
			for(long long j=1;j<m;j++){
				for(long long j2=j+1;j2<=m;j2++){
					if(a[i2][j2]-a[i-1][j2-1]-a[i2-1][j-1]+a[i-1][j-1]>=0)sum=max(sum,(i2-i+1)*(j2-j+1));
				}
			}
		}
	}
	cout<<sum;
	return 0;
}