#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <complex>
#include <queue>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long double ld;

int n, m, mx_a = 0;
int point[100010], te = 1;
struct e {int to, next; int a, b;}edge[200020];

void add (int u, int v, int a, int b) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	edge[te].a = a;
	edge[te].b = b;
	point[u] = te;
}

int fans = 2e9;
int A;
int dis[100010];
int ver[100010];
int if_in[100010];
queue <int> q;
void spfa () {
	dis[1] = 0;
	ver[1] = A;
	dis[n] = 2e9;
	ver[n] = A;
	q.push(1);
	if_in[1] = 1;

	int lim = fans - A;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if_in[x] = 0;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (edge[e].a > A)
				continue ;
			if (edge[e].b >= lim)
				continue ;
			if (ver[to] != A) {
				dis[to] = 2e9;
				ver[to] = A;
			}
			int upd = max(dis[x], edge[e].b);
			if (upd < dis[to]) {
				dis[to] = upd;
				if (!if_in[to]) {
					if_in[to] = 1;
					q.push(to);
//					cerr << "push : " << to << " : " << dis[to] << endl;
				}
			}
		}
	}
	// for (int i = 1; i <= n; i ++)
	// 	cout << dis[i] << " "; cout << endl;
	if (A + dis[n] < fans) {
		// cerr << "yeah " << A << " " << dis[n] << " " << A + dis[n] << endl;
		fans = A + dis[n];
	}
}

int rt[100010];

int main() {
	srand(time(0));
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add (a, b, c, d);
		add (b, a, c, d);
		mx_a = max(mx_a, c);
	}
	for (int i = 1; i <= mx_a; i ++)
		rt[i] = i;
	random_shuffle(rt + 1, rt + mx_a + 1);

	for (int a = 1; a <= mx_a; a ++) {
		int aa = rt[a];
		// if (a % 1000 == 0) {
		// 	cerr << ": " << a << endl;
		// }
		A = aa;
		spfa ();
		// cerr << "end2 " << a << " " << fans << endl;
		while (TIME > 2.8) {
			cout << (fans == 2e9 ? -1 : fans) << endl;
			return 0;
		}
	}
	cout << (fans == 2e9 ? -1 : fans) << endl;
	return 0;
}