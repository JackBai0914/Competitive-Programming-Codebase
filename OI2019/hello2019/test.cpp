#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
ll n, k;
ll a[100010], b[100010], f[100010], fst = 0;
ll dp[100010];
ll dp2[100010];

ll inv[100010];

ll kmi(ll x, ll k) {
	ll ans = 1;
	while (k) {
		if (k & 1) (ans *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	for (int i = 1; i <= 100000; i ++)
		inv[i] = kmi(i, mod - 2);
	cin >> n >> k;
	for (ll i = 1; i * i <= n; i ++) {
		if (n % i == 0) {
			a[++ fst] = i;
			if (i * i != n)
				b[fst] = n / i;
		}
	}
	for (int i = 1; i <= fst; i ++)	f[i] = a[i];
	for (int i = 1; i <= fst; i ++)	f[fst + i] = b[fst - i + 1];

	fst <<= 1;

	for (int i = 1; i <= fst; i ++)
		dp[i] = f[i];
	for (int t = 1; t <= k; t ++) {
		for (int i = 1; i <= fst; i ++) {
			int cnt = 0;
			for (int j = 1; j <= i; j ++)
				if (f[i] % f[j] == 0) {
					cnt ++;
					(dp2[i] += dp[j]) %= mod;
				}
//			cout << "B : " << dp2[i] << endl;
			(dp2[i] *= inv[cnt]) %= mod;
		}
		for (int i = 1; i <= fst; i ++) {
			dp[i] = dp2[i], dp2[i] = 0;
			cout << dp[i] << " ";
		}
		cout << endl;
	}
	cout << dp[fst] << endl;
	return 0;
}