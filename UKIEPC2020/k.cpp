#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;

int n, m, q;
vector <pll> adj[10010];
int vis[10010];
ll dis[10010];

void dfs (int x) {
	vis[x] = 1;
	for (int i = 0; i < adj[x].size(); i ++) {
		int to = adj[x][i].F;
		if (!vis[to]) {
			dis[to] = dis[x] ^ adj[x][i].S;
			dfs (to);
		}
	}
}

namespace LinearBase {
	const int N = 64;
	ll b[N];
	void clean_add (ll x) {
		for (int i = N - 1; i >= 0 && x; i --)
			if (x >> i & 1) {
				if (!b[i]) {
					b[i] = x;
					for (int j = i - 1; j >= 0; j --)	if (b[i] >> j & 1)	b[i] ^= b[j];
					for (int j = N - 1; j > i; j --)	if (b[j] >> i & 1)	b[j] ^= b[i];
					return ;
				}
				else
					x ^= b[i];
			}
	}
	ll query (ll x) {
		for (int i = N - 1; i >= 0 && x; i --)
			if (x >> i & 1)
				x ^= b[i];
		return x;
	}

} using namespace LinearBase;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i ++) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(MP(b, c));
		adj[b].push_back(MP(a, c));
	}

	dfs(1);

	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < adj[i].size(); j ++) {
			int t = adj[i][j].F;
			ll d = adj[i][j].S;
			clean_add (d ^ dis[i] ^ dis[t]);
		}
	}

	for (int i = 1; i <= q; i ++) {
		int x, y;
		cin >> x >> y;
		ll init = dis[x] ^ dis[y];
		cout << query(init) << '\n';
	}
    return 0;
}