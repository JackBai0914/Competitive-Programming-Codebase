#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

int t, n, m;
int p[110][110];

int dp[10010];

int main() {
	ios::sync_with_stdio(false);

	cin >> t >> n >> m;
	for (int i = 1; i <= t; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> p[i][j];

	int mx_in = m;
	for (int i = 1; i < t; i ++) {
		memset (dp, 0, sizeof dp);
		for (int j = 1; j <= mx_in; j ++) {
			dp[j] = dp[j - 1];
			for (int k = 1; k <= n; k ++)
				if (j >= p[i][k])
					dp[j] = max (dp[j], dp[j - p[i][k]] + p[i + 1][k] - p[i][k]);
		}
		mx_in = mx_in + dp[mx_in];
	}
	cout << mx_in << endl;
	return 0;
}