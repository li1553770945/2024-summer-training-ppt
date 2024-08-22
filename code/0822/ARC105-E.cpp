#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector < int >
#define eb emplace_back
#define pii pair < int, int >
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
int Mbe;
mt19937_64 rng(35);
constexpr int N = 1e5 + 10;
int n, m;
int fa[N], sz[N];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
ll calc(int x) {
	return x * 1ll * (x - 1) / 2;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		fa[find(u)] = find(v);
	}
	for(int i = 1; i <= n; ++i) ++sz[find(i)];
	ll x = find(1), y = find(n);
	if(x == y) {
		cout << "Second" << "\n";
		return;
	}
	if(n & 1) {
		if(calc(n) % 2 - m % 2) cout << "First" << "\n";
		else cout << "Second" << "\n";
		return;
	}
	if(sz[x] % 2 != sz[y] % 2) {
		cout << "First" << "\n";
		return;
	}
	if((calc(n) - m - sz[x] % 2) & 1) cout << "First" << "\n";
	else cout << "Second" << "\n";
} 
int Med;
int main() {
	fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	cerr << TIME << "ms\n";
	return 0;
}