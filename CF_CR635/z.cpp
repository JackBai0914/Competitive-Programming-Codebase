//10:06-
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int n;
int point[100010], te = 1, par[100010];
struct e {int to, next;} edge[200020];
void add (int u, int v) {
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

int dp[100010][2]; //false-0. true-1
int ans = 0;

void dfs (int x) {
	dp[x][0] = d[x][1] = 0;
	for (int e = point[x]; e; e = edge[e].next) {
		
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

	dfs (1);
	ans = max (ans, max (dp[1][0], dp[1][1]));

	return 0;
}