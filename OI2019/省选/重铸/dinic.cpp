#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <ctime>
using namespace std;
const int oo = 2e9;
int n, m, s, t;
int first[100010], point[100010], te = 1;
struct e {int to, next; int flow, cost;} edge[2000020];
void add (int u, int v, int w, int x) {
	te ++;
	edge[te].to = v;
	edge[te].flow = w;
	edge[te].cost = x;
	edge[te].next = point[u];
	point[u] = te;
}

int dis[100010];
bool if_in[100010];
int fans = 0, fcost = 0;;
queue <int> q;

bool spfa() {
	for (int i = 1; i <= n; i ++)
		if_in[i] = 0, dis[i] = oo;
	dis[s] = 0;
	if_in[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if_in[x] = 0;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (edge[e].flow && dis[to] > dis[x] + edge[e].cost) {
				dis[to] = dis[x] + edge[e].cost;
				if (!if_in[to]) {
					if_in[to] = 1;
					q.push(to);
				}
			}
		}
	}
	return (dis[t] != oo);
}

int dfs (int x, int mx) {
	if (x == t || mx == 0)
		return mx;
	int pans = 0;
	if_in[x] = 1;
	for (int &e = first[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (!if_in[to] && dis[to] == dis[x] + edge[e].cost && edge[e].flow) {
			int flow = dfs (to, min (edge[e].flow, mx));
			if (flow) {
				edge[e].flow -= flow;
				edge[e ^ 1].flow += flow;
				mx -= flow;
				pans += flow;
			}
		}
	}
	if_in[x] = 0;
	return pans;
}


int main () {
	cin >> n >> m >> s >> t;
	for (int a, b, c, d, i = 1; i <= m; i ++) {
		cin >> a >> b >> c >> d;
		add (a, b, c, d);
		add (b, a, 0, -d);
	}

	while (spfa()) {
		for (int i = 1; i <= n; i ++)
			first[i] = point[i], if_in[i] = 0;
		int cans = dfs(s, oo);
		fcost += cans * dis[t];
		fans += cans;
	}
	cout << fans << " " << fcost << endl;

	return 0;
}