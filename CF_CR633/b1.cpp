#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;

int n, root = 1;
int ans1 = 1, ans2 = 0;
int point[100010], par[100010], dg[100010], te = 1;
struct e {int to, next;} edge[10000010];
void add (int u, int v) {te ++; edge[te].next = point[u]; edge[te].to = v; point[u] = te;}

int if_odd (int x, int l) {
	// cerr << "odd : " << x << " " << l << " " << dg[x] << " : " << (dg[x] == 1) << " " << (l == 1) << endl;
	if (dg[x] == 1 && l % 2 == 1)
		return true;
	bool ret = false;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (par[x] == to)
			continue ;
		par[to] = x;
		ret |= if_odd(to, l + 1);
	}
	// cerr << "ret " << x << " " << ret << endl;
	return ret;
}

void count (int x, int rt) {
	bool if_l = false;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue ;
		if (dg[to] == 1)
			if_l = true;
		else {
			ans2 ++;
			count (to, rt);
		}
	}
	if (par[x] != rt)
		ans2 += if_l;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int a, b, i = 1; i < n; i ++) {
		cin >> a >> b;
		add (a, b);
		add (b, a);
		dg[a] ++;
		dg[b] ++;
	}

	for (; dg[root] != 1; root ++) {}
	ans1 += if_odd (root, 0) * 2;
	count (root, root);

	cout << ans1 << " " << ans2 << endl;
	return 0;
}