//st: 11:55
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;
typedef pair <int, int> pii;
#define F first
#define S second
#define MP make_pair
int n, m;
int ins[55][2][2];
vector <int> c, r;

namespace Flow {
	const int oo = 2e9 + 10;
	int N = 0;
	int first[1010], point[1010], te = 1;
	struct e {int to, next, flow;} edge[1000010];
	void add (int a, int b, int c) {
		te ++;
		edge[te].to = b;
		edge[te].next = point[a];
		edge[te].flow = c;
		point[a] = te;
	}
	int dis[1010];
	queue <int> q;
	bool bfs () {
		for (int i = 0; i <= N; i ++)
			dis[i] = oo;
		dis[0] = 0;
		q.push(0);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int e = point[x]; e; e = edge[e].next) {
				int to = edge[e].to;
				if (edge[e].flow && dis[to] == oo) {
					dis[to] = dis[x] + 1;
					q.push(to);
				}
			}
		}
		return (dis[N] != oo);
	}
	int dfs (int x, int mx) {
		if (x == N || mx == 0)
			return mx;
		int pans = 0;
		for (int &e = first[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (edge[e].flow && 1 + dis[x] == dis[to]) {
				int flow = dfs (to, min(mx, edge[e].flow));
				if (flow) {
					pans += flow;
					mx -= flow;
					edge[e ^ 1].flow += flow;
					edge[e].flow -= flow;
					if (!mx)
						return pans;
				}
			}
		}
		return pans;
	}
	int fans = 0;
	void Dinic() {
		while (bfs()) {
			for (int i = 0; i <= N; i ++)
				first[i] = point[i];
			fans += dfs (0, oo);
		}
	}
	void main(vector <int> L, vector <int> R, vector <pii> E) {
		N = L.size() + R.size() + 1;
		for (int i = 0; i < L.size(); i ++) {
			add (0, i + 1, L[i]);
			add (i + 1, 0, 0);
		}
		for (int i = 0; i < R.size(); i ++) {
			add (L.size() + i + 1, N, R[i]);
			add (N, L.size() + i + 1, 0);
		}
		for (int i = 0; i < E.size(); i ++) {
			add (E[i].F + 1, E[i].S + L.size() + 1, oo);
			add (E[i].S + L.size() + 1, E[i].F + 1, 0);
		}
		Dinic();
		cout << fans << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	vector <int> left, right;
	vector <pii> edge;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		c.push_back(x1);	c.push_back(x2 + 1);
		r.push_back(y1);	r.push_back(y2 + 1);
		ins[i][0][0] = x1, ins[i][0][1] = y1;
		ins[i][1][0] = x2, ins[i][1][1] = y2;
	}
	c.push_back(n + 1);
	r.push_back(n + 1);
	sort(c.begin(), c.end());
	sort(r.begin(), r.end());
	for (int i = 0; i < c.size() - 1; i ++)
		left.push_back(c[i + 1] - c[i]);
	for (int i = 0; i < r.size() - 1; i ++)
		right.push_back(r[i + 1] - r[i]);
	for (int i = 0; i < c.size() - 1; i ++)
		for (int j = 0; j < r.size() - 1; j ++)
			for (int k = 1; k <= m; k ++)
				if (ins[k][0][0] <= c[i] && c[i + 1] - 1 <= ins[k][1][0]
					&& ins[k][0][1] <= r[j] && r[j + 1] - 1 <= ins[k][1][1])
					edge.push_back(MP(i, j));
	Flow::main(left, right, edge);
	return 0;
}