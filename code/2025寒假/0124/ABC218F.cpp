#include<iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;
const int N = 410;
int n, m, d[N], d1[N];
bool flag[N][N * N], flag1[N][N * N];
pair<int, int> e[N * N];
struct node {
	int v, id;
};
vector<node> g[N], g1[N];
void bfs() {
	queue<int> q;
	q.push(1); memset(d, 0x3f, sizeof(d)); d[1] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto it : g[u]) {
			int v = it.v, id = it.id;
			if(d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				for(int i = 1; i <= m; i++) flag[v][i] = flag[u][i];
				flag[v][id] = true;
				q.push(v);
			}
		}
	}
}
void bfs1() {
	queue<int> q;
	q.push(n); memset(d1, 0x3f, sizeof(d1)); d1[n] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto it : g1[u]) {
			int v = it.v, id = it.id;
			if(d1[v] > d1[u] + 1) {
				d1[v] = d1[u] + 1;
				for(int i = 1; i <= m; i++) flag1[v][i] = flag1[u][i];
				flag1[v][id] = true;
				q.push(v);
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		g[u].push_back({v, i}); g1[v].push_back({u, i}); 
		e[i] = {u, v};
	}
	bfs(); bfs1();
	for(int i = 1; i <= m; i++) {
		int ans = 2e9;
		for(int j = 1; j <= n; j++) {
			if(!flag[j][i] && !flag1[j][i]) ans = min(ans, d[j] + d1[j]);
		}
		if(ans < 1e9) cout << ans << '\n';
		else cout << "-1\n";
	}
	return 0;
}