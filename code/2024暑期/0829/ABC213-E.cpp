#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int h, w;
//dis[i][j]表示从(1,1)出发到达(i,j)所消耗拳击技术次数的最小值
char a[1005][1005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int tt[1005][1005];
struct node
{ //从(1,1)出发到达(x,y)所消耗拳击技术次数的最小值t
	int x, y,t;
    bool operator < (const node &a) const
    {
        return t > a.t;
    }
};


void bfs()
{
    priority_queue<node> q;
	q.push(node{1, 1,0});
    tt[1][1] = 0;
	while(!q.empty())
	{
		node u = q.top();
        q.pop();
        int x = u.x, y = u.y, t = u.t;
        //cout<<endl<<x<<" "<<y<<" "<<dis<<" "<<t<<endl;
        if(x == h && y == w)
        {
            cout << t << endl;
            return;
        }
		for(int i = 0; i <= 3; i++)
		{
			int x_new = x + dx[i], y_new = y + dy[i];
			if(x_new < 1 || x_new > h || y_new < 1 || y_new > w) continue;
			if(a[x_new][y_new] == '#') continue;
			if(tt[x_new][y_new]<=tt[x][y]) continue;
            //cout<<x_new<<" "<<y_new<<" "<<dis+1<<" "<<t<<endl;
			q.push(node{x_new, y_new,t});
            tt[x_new][y_new] = tt[x][y];
		}
		
		//(x,y)拳击技术移动能达到的子结点插入队尾
		for(int x_new = x - 2; x_new <= x + 2; x_new++)
			for(int y_new = y - 2; y_new <= y + 2; y_new++)
			{
				if(x_new == x-2&& y_new == y-2) continue;
				if(x_new == x-2&& y_new == y+2) continue;
				if(x_new == x+2&& y_new == y-2) continue;
				if(x_new == x+2&& y_new == y+2) continue;
				if(x_new < 1 || x_new > h || y_new < 1 || y_new > w) continue;
				if(tt[x_new][y_new]<=tt[x][y]+1) continue;
				q.push(node{x_new, y_new,t + 1});
                tt[x_new][y_new] = tt[x][y]+1;
			}
	}
}

int main()
{
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			cin >> a[i][j];
    memset(tt, 0x3f, sizeof(tt));
	bfs();
	return 0;
}