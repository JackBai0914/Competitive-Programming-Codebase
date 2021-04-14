#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
int n, k, x[22];
int dp[22][1010];
int fac[1010], ifac[1010];

int kmi (int x, int t) {
	int ans = 1;
	for (; t; t >>= 1, x = (ll)x * x % mod) 
		if (t & 1)
			ans = (ll)ans * x % mod;
	return ans;
}

int C (int n, int m) {
	if (m > n)
		return 0;
	// cerr << "test2 : " << n << " " << m << " " << (ll)fac[n] * ifac[m] % mod * ifac[n - m] % mod << endl;
	return (ll)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int operation (int x, int z) {
	int ans = (ll)C(n - z, x - z) * ifac[z] % mod;
	// cerr << "test: " << x << " " << z << " " << n << " : " << ans << endl;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= k; i ++)
		cin >> x[i];
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <=n; i ++) {
		fac[i] = (ll)fac[i - 1] * i % mod;
		ifac[i] = kmi (fac[i], mod - 2);
	}

	dp[0][0] = 1;
	for (int i = 1; i <= k; i ++)
		for (int j = 0; j <= n; j ++) {
			for (int k = j; k >= 0 && k >= j - x[i]; k --)
				(dp[i][j] += (ll)dp[i - 1][k] * operation(x[i], j - k) % mod) %= mod;
			// cerr << "dp " << i << " " << j << " = " << dp[i][j] << endl; 
		}
	cout << (ll)dp[k][n] * fac[n] % mod << endl;
	return 0;
}