/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-05 16:13:21
* @description: 
* /Users/jackbai/Desktop/CR694/d.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv d.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, m;
int point[1000010], te = 1;
struct e {int to, next;} edge[1000010];
void add (int u, int v) {
	edge[++ te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

int c[1000010], vis[1000010];
int num = 0, ans = 0;

void dfs (int x, bool col) {
	// cerr << "dfs " << x << " " << col << endl;
	num ++;
	vis[x] = 1;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (vis[to]) {
			if (c[to] == 1)
				col = 0;
		}
	}

	if (col == 0) {
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (vis[to])
				continue ;
			dfs (to, 1);
		}
	}
	else {
		c[x] = 1;
		ans ++;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (vis[to])
				continue ;
			dfs (to, 0);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		num = ans = 0;
		cin >> n >> m;
		for (int i = 0; i <= n; i ++)
			point[i] = 0, c[i] = vis[i] = 0;
		te = 1;
		for (int a, b, i = 1; i <= m; i ++) {
			cin >> a >> b;
			add (a, b);
			add (b, a);
		}
		dfs (1, 1);
		if (num != n) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n' << ans << '\n';
			for (int i = 1; i <= n; i ++)
				if (c[i])
					cout << i << ' ';
			cout << '\n';
		}
	}

    return 0;
}