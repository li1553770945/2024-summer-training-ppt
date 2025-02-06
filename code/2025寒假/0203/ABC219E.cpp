#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int v[8][8], flag[8][8], f[8][8], ans = 0;
bool vis[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void flood(int x, int y)  // 条件1，护城河联通并且没有自交
{
	queue< pair<int, int> > q;
	q.push({x, y});
	while(!q.empty()) 
    {
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) 
        {
			int nx = xx + dx[i], ny = yy + dy[i];
			if(flag[nx][ny] && !f[nx][ny]) 
            {
				f[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}
bool flood_loop(int x, int y) 
{
	queue< pair<int, int> > q;
	q.push({x, y});
	memset(vis, false, sizeof(vis));
	vis[x][y] = true;
	while(!q.empty()) 
    {
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++) 
        {
			int nx = xx + dx[i], ny = yy + dy[i];
			if(!flag[nx][ny] && !vis[nx][ny]) 
            {
				if(nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4) 
                {
					vis[nx][ny] = true;
					q.push({nx, ny});
				}
				else return true;
			}
		}
	}
	return false;
}
int check() 
{
	int x = 0, y = 0, cnt = 0;
	for(int i = 1; i <= 4; i++) 
    {
		for(int j = 1; j <= 4; j++) 
        {
			if(flag[i][j]) cnt++, x = i, y = j;
		}
	}
	memset(f, 0, sizeof(f));
	f[x][y] = 1;
	flood(x, y);	//判断连通
	int sum = 0;
	for(int i = 1; i <= 4; i++) 
    {
		for(int j = 1; j <= 4; j++) 
        {
			if(f[i][j])  //f[i][j]为1，说明bfs能走到这个位置
                sum++; // 能走到的方块数+1
		}
	}
	if(sum != cnt)  // 有的方块走不通，护城河不联通
        return 0;	//不连通
	for(int i = 1; i <= 4; i++) 
    {
		for(int j = 1; j <= 4; j++) 
        {
			if(v[i][j] && !f[i][j]) 
                return 0;	//若有村庄没被包含
		}
	}
	for(int i = 1; i <= 4; i++) 
    {
		for(int j = 1; j <= 4; j++) 
        {
			if(!flag[i][j] && !flood_loop(i, j)) return 0;	//被护城河完全包围
		}
	}
	return 1;
}
void dfs(int x, int y) 
{	//暴力枚举
	if(y > 4) y = 1, x++;
	if(x > 4) 
    {
		ans += check();
		return;
	}
	flag[x][y] = 1; // 被护城河包围
	dfs(x, y + 1); // dfs
	flag[x][y] = 0; //没有被包围
	dfs(x, y + 1); //dfs
}
int main() 
{
	for(int i = 1; i <= 4; i++) 
    {
		for(int j = 1; j <= 4; j++) 
        {
			cin >> v[i][j];
		}
	}
	dfs(1, 1);
	cout << ans;
	return 0;
}