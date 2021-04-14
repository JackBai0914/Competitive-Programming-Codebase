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
struct e {int to, next, v;} edge[500050];
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
bool if_in[200020];


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int a, b, c, i = 1; i <= m; i ++)
		cin >> a >> b >> c, add (a, b, c);
	queue <int> q;
	for (int i = 1; i <= n; i ++)
		dis[i] = 2147483647;
	dis[s] = 0;
	q.push(s);
	if_in[s] = 1;
	while (!q.empty()) {
		int x = q.front();
		if_in[x] = 0;
		q.pop();
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (dis[to] > dis[x] + edge[e].v) {
				dis[to] = dis[x] + edge[e].v;
				if (!if_in[to]) {
					if_in[to] = 1;
					q.push(to); 
				}
			}
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << dis[i] << " ";
	cout << endl;
	return 0;
}