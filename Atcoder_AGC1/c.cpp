#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int par[5050], dep[5050];
vector <int> sons[5050];
int  dp[2020][2020];

int point[5050], te = 1;
struct e {int to, next;} edge[5050];
void add (int a, int b) {
	te ++;
	edge[te].next = point[a];
	edge[te].to = b;
	point[a] = te;
}

int ans = 1e9;

void dfs (int x) {
	dep[x] = 1;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue;
		par[to] = x;
		sons[x].push_back(to);
		dfs (to);
		dep[x] = max (dep[x], dep[to] + 1);
	}
	dp[x][0] = 1;
	for (int j = 0; j < sons[x].size(); j ++)
		dp[x][0] += dp[sons[x][j]][0];
	for (int i = 1; i <= dep[x]; i ++) {
		int tg = i - 1;
		int rem = min (tg, k - tg);
		int max_loss = 0;
		for (int j = 0; j < sons[x].size(); j ++) {
			int s = sons[x][j];
			dp[x][i] += dp[s][rem];
			// cerr << "dp " << x << " " << i << " += " << "dp " << s << " " << rem << " : " << dp[x][i] << " " << dp[s][rem] << endl;
			max_loss = max (max_loss, dp[s][rem] - dp[s][tg]);
		}
		dp[x][i] -= max_loss;
	}
	// cerr << x << " ::: ";
	// for (int i = 1; i <= dep[x]; i ++)
		// cerr << dp[x][i] << " ";
	// cerr << endl;
	for (int i = 1; i <= dep[x]; i ++)
		dp[x][i] = min (dp[x][i], dp[x][i - 1]);
	int pans = min (dep[x], k + 1);
	// cerr << x << " : " << n - dp[x][0] + dp[x][pans] << endl;
	ans = min (ans, n - dp[x][0] + dp[x][pans]);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}
	dfs (1);
	cout << ans << endl;
	return 0;
}
/*
10 4
1 2
2 3
3 4
1 5
5 6
6 7
1 8
8 9
9 10
*/