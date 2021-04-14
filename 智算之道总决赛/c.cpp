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
typedef long long ll;
typedef unsigned long long ull;

int n, m, Q;
bool con[550][550];
struct e {int to, next, val;} edge[500010];
int te = 1, point[550];
void add (int u, int v, int w) {
	te ++;
	edge[te].next = point[u];
	edge[te].to = v;
	edge[te].val = w;
	point[u] = te;
}

int len[550][550], par[550][550], vis[550], ban = -1, sour, targ;
bool mp[550][550][550];
priority_queue <pair<int, int> > q;

void bfs () {
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i ++)
		len[sour][i] = -1, vis[i] = 0;
	len[sour][sour] = 0;
	q.push(MP(0, sour));
	while (!q.empty()) {
		int x = q.top().S;
		con[sour][x] = 1;
		q.pop();
		if (vis[x])
			continue ;
		vis[x] = 1;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (len[sour][to] != -1 && len[sour][to] <= len[sour][x] + edge[e].val)
				continue ;
			len[sour][to] = len[sour][x] + edge[e].val;
			par[sour][to] = x;
			q.push(MP(-len[sour][to], to));
		}
	}
}

int len2[501], par2[501];
void bfs2 () {
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i ++)
		vis[i] = par2[i] = 0, len2[i] = -1;
	len2[sour] = 0;
	q.push(MP(0, sour));
	while (!q.empty()) {
		int x = q.top().S;
		if (x == targ)
			return ;
		q.pop();
		if (vis[x])		continue ;
		if (ban == x)	continue ;
		vis[x] = 1;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (ban == to)	continue ;
			if (len2[to] != -1 && len2[to] <= len2[x] + edge[e].val)	continue ;
			if (!con[to][targ])	continue ;
			len2[to] = len2[x] + edge[e].val;
			par2[to] = x;
			q.push(MP(-len2[to], to));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	memset(len, -1, sizeof len);
	int last = 0;
	cin >> n >> m >> Q;
	for (int a, b, c, i = 1; i <= m; i ++) {
		cin >> a >> b >> c;
		add (a, b, c);
	}
	
	for (int i = 1; i <= n; i ++) {
		sour = i;
		bfs ();
		for (int j = 1; j <= n; j ++) {
			int k = j;
			while (k != sour && k != 0) {
				mp[sour][j][k] = 1;
				k = par[sour][k];
			}
			mp[sour][j][k] = 1;
		}
	}
	
	for (int i = 1; i <= Q; i ++) {
		int u, v, s, ans = 0;
		cin >> u >> v >> s;
		((u += last) %= n) += 1;
		((v += last) %= n) += 1;
		((s += last) %= n) += 1;
		sour = u, ban = s, targ = v;
		if (mp[u][v][s] != 1) {
			last = len[sour][v];
			if (last == -1)
				last = 0;
			cout << last << '\n';
			continue ;
		}
		bfs2 ();
		last = len2[v];
		if (last == -1)
			last = 0;
		cout << last << '\n';
	}
	return 0;
}