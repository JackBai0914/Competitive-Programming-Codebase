#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;

int n, a, b, da, db;
int te = 1, point[500050];
struct e {int to, next;} edge[1000010];
void add (int u, int v) {
	te ++;
	edge[te].next = point[u];
	edge[te].to = v;
	point[u] = te;
}

int dis[500050], par[500050];
int id1, mx1 = 0;
void dfs (int x) {
	if (dis[x] > mx1)
		mx1 = dis[x], id1 = x;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue;
		par[to] = x;
		dis[to] = dis[x] + 1;
		dfs (to);
	}
}

int id2, mx2 = 0;
void dfs2 (int x) {
	if (dis[x] > mx2)
		mx2 = dis[x], id2 = x;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue;
		par[to] = x;
		dis[to] = dis[x] + 1;
		dfs2 (to);
	}
}


int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T --) {
		cin >> n >> a >> b >> da >> db;
		te = 0;
		for (int i = 1; i <= n; i ++)
			point[i] = dis[i] = par[i] = 0;
		for (int a, b, i = 1; i < n; i ++)
			cin >> a >> b, add (a, b), add (b, a);
		mx1 = 0;
		dfs (a);
		if (db <= da * 2 || dis[b] <= da) {cout << "Alice" << '\n';continue ;}
		for (int i = 1; i <= n; i ++)
			par[i] = dis[i] = 0;
		mx2 = 0;
		dfs2 (id1);
		if (mx2 <= 2 * da) {cout << "Alice" << '\n';continue ;}
		else 				{cout << "Bob" << '\n';continue ;}

	}
	
	return 0;
}