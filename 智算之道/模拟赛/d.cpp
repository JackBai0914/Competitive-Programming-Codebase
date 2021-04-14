#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;

int n, m, Q;

int point[100010], te = 1;
struct e {int to, next;} edge[200020];
void add (int u, int v) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

int d[2][100010];

priority_queue <pair <int, int> > q; 
bool vis[2][100010];

void Dijkstra () {
	for (int i = 1; i <= n; i ++)
		d[0][i] = d[1][i] = 2e9;
	d[0][1] = 0;
	q.push (MP(0, 1));
	while (!q.empty()) {
		int x = q.top().S, dis = -q.top().F;
		q.pop();
		if (vis[dis%2][x])
			continue;
		vis[dis%2][x] = 1;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			int td = dis + 1, ind = td % 2;
			if (td < d[ind][to]) {
				d[ind][to] = td;
				q.push(MP(-td, to));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> Q;
	for (int i = 1; i <= m; i ++) {
		int u, v;
		cin >> u >> v;
		add (u, v);
		add (v, u);
	}

	Dijkstra();

	// for (int i = 1; i <= n; i ++)
		// cerr << i << " " << d[0][i] << " " << d[1][i] << endl;

	for (int i = 1; i <= Q; i ++) {
		int a, l;
		cin >> a >> l;
		cout << (d[l%2][a] <= l ? "Yes" : "No") << '\n';
	}

	return 0;
}