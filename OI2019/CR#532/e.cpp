#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dg[100010], point[100010], te = 0;
struct e {
	int fr, to, next, v, id;
} ins[100010], edge[100010];

void add (int x, int y) {
	te ++;
	edge[te].to = y;
	edge[te].next = point[x];
	point[x] = te;
	dg[y] ++;
}

bool cir = 0;
int if_in[100010], dfn[100010], low[100010], ti = 0;

void dfs(int x) {
	// cout << "dfs : " << x << endl;
	dfn[x] = low[x] = ++ ti;
	if_in[x] = 1;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (!dfn[to]) {
			// cout << "trans " << x << "to" << to << endl;
			dfs(to);
			low[x] = min(low[to], low[x]);
		}
		else if (if_in[to] == 1) {
			low[x] = min(low[x], dfn[to]);
		}
	}
	if (low[x] != dfn[x]) {
		// cout << "wrong : " << x << " " <<dfn[x] << " " << low[x] << endl;
		cir = 1;
	}
	if_in[x] = 0;
}
bool if_cir() {
	cir = ti = 0;
	for (int i = 1; i <= n; i ++)
		dfn[i] = low[i] = 0;
	for (int i = 1; i <= n; i ++)
		if (!dfn[i])
			dfs(i);
	return cir;
}

int ord[100010];
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> ins[i].fr >> ins[i].to >> ins[i].v;
		ins[i].id = i;
	}
	
	int l = 0, r = 1e9;
	while (l != r) {
		int mid = (l + r) / 2;
		for (int i = 1; i <= n; i ++)
			point[i] = dg[i] = 0;
		te = 0;
		for (int i = 1; i <= m; i ++)
			if (ins[i].v > mid)
				add (ins[i].fr, ins[i].to);
			// cout << "check " << mid << endl;
		bool check = if_cir();
		if (check)
			l = mid + 1;
		else
			r = mid;
	}
	//
	for (int i = 1; i <= n; i ++)
		point[i] = dg[i] = 0;
	te = 0;
	for (int i = 1; i <= m; i ++)
		if (ins[i].v > l)
			add (ins[i].fr, ins[i].to);
	//
	int ost = 0;
	for (int i = 1; i <= n; i ++)
		if (!dg[i])
			q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ord[now] = ++ ost;
		for (int e = point[now]; e; e = edge[e].next) {
			int to = edge[e].to;
			dg[to] --;
			if (!dg[to])
				q.push(to);
		}
	}
	// for (int i = 1; i <= n; i ++)
		// cout << ord[i] << " ";cout << endl;
	int num = 0;
	for (int i = 1; i <= m; i ++) {
		int a = ins[i].fr;
		int b = ins[i].to;
		if (ord[a] > ord[b])
			num ++;
	}
	cout << l << " " << num << endl;
	for (int i = 1; i <= m; i ++) {
		int a = ins[i].fr;
		int b = ins[i].to;
		if (ord[a] > ord[b])
			cout << i << " ";
	}
	cout << endl;
	return 0;
}