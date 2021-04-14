#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
using namespace std;
typedef long long ll;
int n, m, S, T;
int point[1000010], te = 1;
struct e {int to, next, v, flow;} edge[2000020];
void add (int a, int b, int c, int d) {
	te ++;
	edge[te].to = b;
	edge[te].v = c;
	edge[te].flow = d;
	edge[te].next = point[a];
	point[a] = te;
}

ll fans = 0, fcost = 0;
int if_in[1000010], first[1000010], dis[1000010];

queue <int> q;
bool spfa () {
	for (int i = 1; i <= n; i ++)
		dis[i] = 1e9;
	dis[S] = 0;
	q.push(S);
	if_in[S] = 1;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		if_in[c] = 0;
		for (int e = point[c]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (edge[e].flow != 0 && edge[e].v + dis[c] < dis[to] ) {
				dis[to] = dis[c] + edge[e].v;
				if (!if_in[to]) {
					q.push(to);
					if_in[to] = 1;
				}
			}
		}
	}
	return (dis[T] != 1e9);
}

int dfs (int x, int mx) {
	if (x == T || mx == 0)
		return mx;
	ll pans = 0;
	if_in[x] = 1;
	for (int &e = first[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (dis[to] == dis[x] + edge[e].v && edge[e].flow && !if_in[to]) {
			int flow = dfs (to, min(mx, edge[e].flow));
			if (flow) {
				pans += flow;
				mx -= flow;
				edge[e].flow -= flow;
				edge[e ^ 1].flow += flow;
				if (!mx) {
					if_in[x] = 0;
					return pans;
				}
			}
		}
	}
	if_in [x] = 0;
	return pans;
}

void Dinic() {
	while (spfa ()) {
		for (int i = 1; i <= n; i ++)
			first[i] = point[i], if_in[i] = 0;
		int pans = dfs (S, 1e9);
		fans += pans;
		// cerr << ": " << pans << " : " << dis[T] << endl;
		fcost += pans * dis[T];
	}
}


int main() {
	cin >> n >> m >> S >> T;
	for (int i = 1; i <= m; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add (a, b, d, c);
		add (b, a, -d, 0);
	}

	Dinic();
	cout << fans << " " << fcost << endl;

	return 0;
}