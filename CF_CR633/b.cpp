#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
int point[100010], dg[100010], te = 1;
struct e {int to, next;} edge[1000010];
void add (int a, int b) {
	te ++;
	edge[te].to = b;
	edge[te].next = point[a];
	point[a] = te;
	dg[a] ++;
}

int par[100010];
bool odd = 0;
int find_odd (int x) {
	int ret = -1;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue ;
		par[to] = x;
		int cur = find_odd (to);
		if (ret != -1 && ret != cur)
			odd = true;
		if (ret == -1)
			ret = cur;
	}
	ret = (ret + 1) % 2;
	// cerr << "ret: " << x << " " << ret << endl;
	return ret;
}

int ans1, ans2 = 0;

void dfs (int x) {
	int bonus = 0;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue ;
		if (dg[to] != 1)
			ans2 ++;
		if (bonus == 0 && dg[to] == 1)
			ans2 ++, bonus = 1;
		dfs (to);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int a, b, i = 1; i < n; i ++) {
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}

	int root;
	for (int i = 1; i <= n; i ++)
		if (dg[i] != 1) {
			root = i;
			break;
		}

	int dis = find_odd (root);
	if (odd == true)	ans1 = 3;
	else				ans1 = 1;

	dfs (root);

	cout << ans1 << " " << ans2 << endl;

	return 0;
}