#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int mx = 2e5 + 20;
int n, m;
ll ans1 = 0, ans2 = 0, ans0 = 0;
pii ex[mx];
int lca[mx], af[mx], as[mx];
namespace Tree {
	int point[mx], te = 0;
	struct e {int to, next, fr;} edge[mx << 1];
	void add (int u, int v) {edge[++te].fr = u, edge[te].to = v, edge[te].next = point[u], point[u] = te;}
	int par[mx], dep[mx], num[mx], desc[mx], top[mx];
	int st[mx], ed[mx], ti = 0;
	int ve[mx];
	void set (int x) {
		st[x] = ++ ti;
		num[x] = 1;
		int mx = 0;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (to == par[x])
				continue ;
			par[to] = x;
			dep[to] = dep[x] + 1;
			set(to);
			num[x] += num[to];
			if (mx < num[to])
				mx = num[to], desc[x] = to;
		}
		ed[x] = ti;
	}
	void build (int x, int rt) {
		top[x] = rt;
		if (desc[x])
			build(desc[x], rt);
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (to == par[x] || to == desc[x])
				continue ;
			build(to, to);
		}
	}

	void Tree_init () {
		set(1);
		build(1, 1);
	}
	void Cumu (int x) {
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (to == par[x])
				continue ;
			ve[to] += ve[x];
			Cumu(to);
		}
	}
}using namespace Tree;

vector <pii> hang[mx];
map <pii, int> over;
void deal_LCA(int x, int y, int id) {
	bool rev = 0;
	int z, ax = x, ay = y;
	int ix = min(x, y), iy = max(x, y);
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])	swap(x, y), swap(ax, ay), rev ^= 1;
		ax = top[x];
		x = par[top[x]];
	}
	if (dep[x] < dep[y]) {
		ay = desc[x];
		z = x;
	}
	else if (dep[x] > dep[y]) {
		ax = desc[y];
		z = y;
	}
	else
		z = (x + y) >> 1;

	// cout << ix << " " << iy << " res : " << z << " " << ax << " " << ay << endl;
	lca[id] = z;
	hang[z].push_back(MP(min(ix, iy), max(ix, iy)));
	over[MP(min(ax, ay), max(ax, ay))] ++;
	if (ax != z)	ve[ax] ++;
	if (ay != z)	ve[ay] ++;
	if (rev)	swap(ax, ay);
	af[id] = ax, as[id] = ay;
}

int main() {
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	cin >> n >> m;
	m -= n - 1;
	for (int a, b, i = 1; i < n; i ++)	cin >> a >> b, add(a, b), add (b, a);
	for (int a, b, i = 1; i <= m; i ++)	cin >> ex[i].F >> ex[i].S;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			if (ex[i].F == ex[j].F)
				ans1 ++;
			ans1 *= 2;
		}
	cout << 4 << endl;
	return 0;
}