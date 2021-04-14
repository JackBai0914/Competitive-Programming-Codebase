#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[1010][1010];

int gcd (int a, int b) {return (b ? gcd (b, a % b) : a);}

int main() {
	ios::sync_with_stdio(false);
	dp[1][1] = 1;
	for (int i = 1; i <= 1000; i ++)
		for (int j = 1; j <= 1000; j ++) {
			bool if_p = (gcd(i, j) == 1);
			if (i == 1 && j == 1)
				continue ;
			if (i == 1)			dp[i][j] = if_p + dp[i][j - 1];
			else if (j == 1)	dp[i][j] = if_p + dp[i - 1][j];
			else				dp[i][j] = if_p + max (dp[i][j - 1], dp[i - 1][j]);
		}

	int t;
	cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;
		cout << dp[n][m] << '\n';
	}

	return 0;
}