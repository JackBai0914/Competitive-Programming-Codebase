#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
typedef long long ll;

int n, k;
int point[200020], te = 1, par[200020];
struct e {int to, next;} edge[2000020];
void add (int u, int v) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

ll sum[200020], num[200020], pans[200020];
void dfs (int x) {
	// cerr << "dfs " << x << endl;
	num[x] = 1;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue ;
		par[to] = x;
		sum[to] = sum[x] + 1;
		dfs (to);
		num[x] += num[to];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int a, b, i = 1; i < n; i ++) {
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}

	sum[1] = 1;
	dfs (1);
	for (int i = 1; i <= n; i ++)
		pans[i] = sum[i] - num[i];
	sort (pans + 1, pans + n + 1);
	ll ans = 0;
	for (int i = n; i > n - k; i --)
		ans += pans[i];
	cout << ans << endl;

	return 0;
}
