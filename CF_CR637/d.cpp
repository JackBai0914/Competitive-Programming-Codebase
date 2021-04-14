#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;

const int mx = 1e6;
int n, dg[mx], point[mx], te = 1;
struct e {int to, next;} edge[mx * 2];
void add (int u, int v) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] ++;
	dg[u] ++;
}

int par[mx];



void dfs (int x) {
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (par[x] == to)
			continue ;
		par[to] = x;
		dfs (to);
	}
}

map <int, bool> mp[100010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}

	dfs (1);



	return 0;
}