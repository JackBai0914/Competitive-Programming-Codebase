#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int n, ins[2020];

const int mod = 998244353;
long long dp[2020][2020];
int eq = 1;

bool flag[2020];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T --) {
		memset(flag, 0, sizeof flag);
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> ins[i];
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dp[i][j] = 0;
		eq = 1;
		int mx = 0;
		for (int i = 1; i <= n; i ++) {
			if (eq) {
				int neq = 0;
				mx = max(mx, ins[i - 1]);
				flag[ins[i - 1]] = 1;
				int mn = 1e9;
				for (int j = mx; j >= 1; j --)
					if (flag[j] == 0)
						mn = j;
				if (mn != 1e9) {
					if (mn > ins[i])	dp[i][mx] ++;
					if (mn == ins[i])	neq = 1;
				}
				for (int j = mx + 1; j <= n; j ++) {
					if (j > ins[i])	dp[i][j] ++;
					if (j == ins[i])	neq = 1;
				}
				eq = neq;
			}

			long long sum = 0;

			for (int j = i - 1; j <= n; j ++) {
				int rem = j - (i - 1);
				(dp[i][j] += dp[i - 1][j] * (rem != 0)) %= mod;
				(dp[i][j] += sum) %= mod;
				(sum += dp[i - 1][j]) %= mod;
			}
		}

		// for (int i = 1; i <= n; i ++) {
		// 	for (int j = 1; j <= n; j ++)
		// 		cerr << dp[i][j] << " ";
		// 	cerr << endl;
		// }
		cout << dp[n][n] << endl;
	}

	return 0;
}