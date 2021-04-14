#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <ctime>
#include <cstdlib>
#include <queue>
using namespace std;

int n, m;

namespace MinCostFlow {
	typedef long long ll;
	const int oo = 2147483647;
	const int mxN = 1e5;
	const int mxM = 1e5;
	int S, T;
	int flow = 0, cost = 0;
	int point[mxN], te = 1, first[mxN];
	int dis[mxN];
	bool if_in[mxN];
	struct e {int to, next, flow, c;} edge[mxM << 1];
	void add (int u, int v, int w, int x) {
		te ++;
		edge[te].to = v;
		edge[te].flow = w;
		edge[te].c = x;
		edge[te].next = point[u];
		point[u] = te;
	}
	queue <int> q;
	bool spfa() {
		bool ret = 0;
		for (int i = 1; i <= n; i ++)
			dis[i] = oo;
		dis[S] = 0;
		q.push(S);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if_in[now] = 0;
			ret |= (now == T);
			// cout << "queueing " << now << " " << dis[now] << endl;
			for (int e = point[now]; e; e = edge[e].next) {
				int to = edge[e].to;
				if (edge[e].flow && dis[to] > dis[now] + edge[e].c) {
					dis[to] = dis[now] + edge[e].c;
					// cout << "suc update " << to << " " << dis[to] << endl;
					if (!if_in[to]) {
						q.push(to);
						if_in[to] = 1;
					}
				}
			}
		}
		return ret;
	}
	int dfs(int x, int mx) {
		if (x == T || !mx)
			return mx;
		int pans = 0;
		if_in[x] = 1;
		for (int &e = first[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (dis[to] == dis[x] + edge[e].c && edge[e].flow && !if_in[to]) {
				int flow = dfs(to, min(mx, edge[e].flow));
				if (flow) {
					edge[e].flow -= flow;
					edge[e ^ 1].flow += flow;
					pans += flow;
					mx -= flow;
					if (!mx) {
						if_in[x] = 0;
						return pans;
					}
				}
			}
		}
		if_in[x] = 0;
		return pans;
	}

	void proceed() {
		while (spfa()) {
			for (int i = 1; i <= n; i ++)
				first[i] = point[i];
			int pflow;
			pflow = dfs(S, oo);
			flow += pflow;
			cost += pflow * dis[T];
		}
	}
} using namespace MinCostFlow;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> S >> T;
	for (int a, b, c, d, i = 1; i <= m; i ++) {
		cin >> a >> b >> c >> d;
		add (a, b, c, d);
		add (b, a, 0, -d);
	}
	proceed();
	cout << flow << " " << cost << endl;
	return 0;
}