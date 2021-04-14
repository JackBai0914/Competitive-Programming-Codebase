#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int S = 0;
int T = 120010;
const int oo = 1e9;

int n, m;
struct e {int to, next, flow;}edge[3000300];
int point[1000010], te = 1, cur[1000010], dis[1000010];
void add(int u, int v, int w)
{
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	edge[te].flow = w;
	point[u] = te;
}

int fans = 0;

bool bfs()
{
	queue <int> q;
	q.push(S);
	for (int i = 0; i <= T; i ++)
		dis[i] = 0;
	dis[T] = 0;
	dis[S] = 1;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for (int e = point[now]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (!dis[to] && edge[e].flow) {
				dis[to] = dis[now] + 1;
				q.push(to);
			}	
		}
	}
	return (dis[T]);
}

int dfs(int x, int mx)
{
	//cout << x << " " << mx << endl;
	if (x == T || !mx)
		return mx;
	int pans = 0;
	for (int &e = cur[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (dis[to] == dis[x] + 1) {
			int flow = dfs(to, min(mx, edge[e].flow));
			if (flow) {
				mx -= flow;
				pans += flow;
				edge[e].flow -= flow;
				edge[e ^ 1].flow += flow;
				if (!mx)
					return pans;
			}
		}
	}
	return pans;
}

void Dinic()
{
	while(bfs()) {
		for (int i = 0; i <= T; i ++)
			cur[i] = point[i];
		//cout << "ok" << endl;
		cur[T] = point[T];
		fans += dfs(S, oo);
	}
}

bool mp[502][502];

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	int ans = 0;
	cin >> n >> m;
	S = 0;
	T = n * m * 3 + 1;
	int allp = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			char c;
			cin >> c;
			mp[i][j] = (c == '#');
			allp += mp[i][j];
		}
	int alle = 0;
	for (int i = 1; i < n; i ++)
		for (int j = 1; j <= m; j ++) {
			if (mp[i][j] == 1 && mp[i + 1][j] == 1) {
				alle ++;
				int id = n * m + (i - 1) * m + j;
				int a = (i - 1) * m + j;
				int b = i * m + j;
				add (S, id, 1);add (id, S, 0);
				add (id, a, oo);add (a, id, 0);
				add (id, b, oo);add (b, id, 0);
			}
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < m; j ++) {
			if (mp[i][j] == 1 && mp[i][j + 1] == 1) {
				alle ++;
				int id = n * m * 2 + (i - 1) * m + j;
				int a = (i - 1) * m + j;
				int b = (i - 1) * m + j + 1;
				add (id, T, 1);add (T, id, 0);
				add (a, id, oo);add (id, a, 0);
				add (b, id, oo);add (id, b, 0);
			}
		}
	Dinic();
	alle -= fans;
	cout << allp - alle << endl;
	return 0;
}
/*

*/
