#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll kmi (ll x, ll t) {
	ll ans = 1;
	for (x %= mod; t; t >>= 1, (x *= x) %= mod)
		if (t & 1)
			(ans *= x) %= mod;
	return ans;
}
int n, k, x, y;
ll q;

ll dp[1010][1010];
ll sum[1010][1010];

ll calc(int mx) {
	memset(dp, 0, sizeof dp);
	memset(sum, 0, sizeof sum);
	for (int i = 1001; i >= 0; i --) {
		dp[0][i] = 1;
		sum[0][i] = 1;
		for (int j = 1; i * j <= mx && j <= n; j ++) {
			for (int k = 1; k <= j; k ++) {
				(dp[j][i] += sum[k - 1][i + 1] * sum[j - k][i] % mod * kmi (q, k - 1) % mod * (1 - q + mod) % mod) %= mod;
				// dp[j][i] += sum[k - 1][i + 1] * sum[j - k][i] * pow(q, i) * (1 - q);	
				// cerr << ": " << dp[k - 1][i + 1] << " " << dp[j - k][i] << " " << pow(q, i) << " " << (1 - q) << endl;
			}
			sum[j][i] = sum[j][i + 1] * kmi (q, j) + dp[j][i];
			// cerr << j << " " << i << " : " << dp[j][i] << endl;
		}
	}
	return sum[n][0];
}

int main() {
	cin >> n >> k >> x >> y;
	q = x * kmi(y, mod - 2) % mod;
	cout << (calc(k) - calc(k - 1) + mod) % mod << endl;
	return 0;
}