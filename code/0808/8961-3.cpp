#include<iostream>
using namespace std;
#define int long long
int n,m;
int a[405],b[405];
int pre[405][405];
int _max(int a,int b){
	return a>b?a:b;
}
bool check(int x){
	if(n*m<x)return false;
	for(int e=1;e<=x&&e<=n;e++){
		if(x%e==0&&x/e<=m){
			for(int i=e;i<=n;i++){
				for(int j=x/e;j<=m;j++){
					int sum=pre[i][j]-(pre[i-e][j]+pre[i][j-x/e])+pre[i-e][j-x/e];
					if(sum>=0)return true;
				}
			}
		}
	}return false;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a;
			cin>>a;
			pre[i][j]=a+pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1];
		}
	}
	for(int i=n*m;i>=1;i--){ // 枚举矩阵面积
		if(check(i)){ // 是否能找到一个矩阵，面积为i，并且求和大于0
			cout<<i;
			return 0;
		}
	}
	return 0;
}