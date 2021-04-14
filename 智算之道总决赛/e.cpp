#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m, x;
struct e {int to, next;} edge[1000010];
int te = 1, point[1010];
void add (int u, int v) {
	te ++;
	edge[te].next = point[u];
	edge[te].to = v;
	point[u] = te;
}
int ban[1010][1010];

int vis[1010], par[1010], num = 0, if_back = false;

void check (int x, int col) {
	// cerr << "dfs " << x << " " << col << endl;
	num ++;
	vis[x] = col;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (ban[x][to])
			continue ;
		if (to == par[x])
			continue ;
		if (vis[to] == col) {
			if_back = true;
			continue ;
		}
		par[to] = x;
		check (to, col);
	}
}

int main() {
	cin >> n >> m >> x;
	for (int o, u, v, i = 1; i <= m; i ++) {
		cin >> o >> u >> v;
		if (o == 1) {
			if (ban[u][v] == 1)
				ban[u][v] = ban[v][u] = 0;
			else {
				add (u, v);
				add (v, u);
			}
		}
		else {
			ban[u][v] = ban[v][u] = 1;
		}
		bool fine = true;
		memset(vis, 0, sizeof vis);

		// cerr << "checking " << i << endl;
		for (int j = 1; j <= n; j ++) 
			if (!vis[j]) {
				if_back = false;
				num = 0;
				check(j, j);
				// cerr << "res for " << j << " : " << if_back << " " << num << endl;
				if (if_back && num != 3)
					fine = false;
			}
		cout << (fine ? "Yes" : "No") << endl;
	}
	return 0;
}