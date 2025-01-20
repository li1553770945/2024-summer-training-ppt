
#include <cstdio>
#include <algorithm>
#define maxn 500010
using namespace std;
int n,m;
int c[maxn],book[maxn],tree[maxn],ans[maxn];
struct node{
	int l,r,seq;
}q[maxn];

int lowbit(int x)
{
	return x&-x;
}
void add(int pos,int val)
{
	while(pos<=n){
		tree[pos]+=val;
		pos+=lowbit(pos);
	}
}
int sum(int pos)
{
	int ret=0;
	while(pos>0){
		ret+=tree[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
int cmp(node a,node b)
{
	return a.r<b.r;
}
int main()
{
	int i,j,start;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
	for(i=1;i<=m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
    }

	sort(q+1,q+1+m,cmp);//按右边界自小到大排序

	start=1;

	for(i=1;i<=m;i++)
    {
		for(j=start;j<=q[i].r;j++)
        {//以r为边界，进行处理。
			if(book[c[j]]) // 如果这个颜色已经出现过
            {
                add(book[c[j]],-1);//删除之前的颜色，只保留最后出现的位置
            }
			add(j,1); // 标记当前颜色出现过
            book[c[j]]=j;//标记该颜色现在位置
		}
		start=q[i].r+1;//连续区间处理
		ans[q[i].seq]=sum(q[i].r)-sum(q[i].l-1);
	}
	for(i=1;i<=m;i++)
    {
        printf("%d\n",ans[i]);
    }
	return 0;
}