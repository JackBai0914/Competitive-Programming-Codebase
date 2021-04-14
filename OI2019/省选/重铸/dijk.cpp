#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

//42
int n, m, s;
struct e {int to, next, v;} edge[400040];
int point[200020], te = 0;
void add (int u, int v, int w) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	edge[te].v = w;
	point[u] = te;
}

typedef long long ll;
ll dis[200020];
bool done[200020];

#define F first
#define S second
#define MP make_pair
typedef pair <ll, int> pii;


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int a, b, c, i = 1; i <= m; i ++)
		cin >> a >> b >> c, add (a, b, c);
	priority_queue <pii, vector <pii>, greater<pii> > q;
	for (int i = 1; i <= n; i ++)
		dis[i] = 1e14;
	dis[s] = 0;
	q.push(MP(0, s));

	while (!q.empty()) {
		int x = q.top().S;
		q.pop();
		if (done[x])
			continue ;
		done[x] = 1;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (dis[to] > dis[x] + edge[e].v) {
				dis[to] = dis[x] + edge[e].v;
				q.push(MP(dis[to], to));
			}
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << dis[i] << " ";
	cout << endl;
	return 0;
}