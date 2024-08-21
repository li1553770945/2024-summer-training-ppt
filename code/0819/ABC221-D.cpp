#include<iostream>
#include <algorithm>
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=4e5+10;
LL n,ans[N],x,y,tot,s;
pii p[N];
bool cmp(pii a,pii b){
	return a.first<b.first;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		p[++tot]={x,1},p[++tot]={x+y,-1}; // 离散化差分
	}
	sort(p+1,p+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		s+=p[i].second; //s是当前的实际值，每次加上差分值
		ans[s]+=p[i+1].first-p[i].first; // p_i,p_{i+1}这个区间的值都是s，ans[s]表示值为s的有多少个位置，ans[s]加上区间长度
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	return 0;
}