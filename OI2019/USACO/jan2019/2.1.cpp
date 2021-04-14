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
	int st[mx], ed[mx], dfn[mx], ti = 0;
	int ve[mx];
	void set (int x) {
		st[x] = ++ ti;
		dfn[ti] = x;
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


int main() {
	freopen("exercise.in", "r", stdin);
	// freopen("exercise.out", "w", stdout);
	cin >> n >> m;
	m -= n - 1;
	for (int a, b, i = 1; i < n; i ++)	cin >> a >> b, add(a, b), add (b, a);
	for (int a, b, i = 1; i <= m; i ++)	cin >> ex[i].F >> ex[i].S;

	Tree_init();
	for (int i = 1;)


	return 0;
}