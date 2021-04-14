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
ll v[1010], num[1010], st = 0;
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

ll dp[110], dp2[110];

ll fans = 1;

void pro() {
	ll pans = 0;
	memset(dp, 0, sizeof dp);
	memset(dp2, 0, sizeof dp2);
	dp[num[st]] = 1;
	for (int t = 1; t <= k; t ++) {
		for (int a = 0; a <= num[st]; a ++)
			for (int b = 0; b <= a; b ++)
				(dp2[b] += dp[a] * inv[a + 1] % mod) %= mod;
		for (int a = 0; a <= num[st]; a ++)
			dp[a] = dp2[a], dp2[a] = 0;
	}
	ll val = 1;
	for (int a = 0; a <= num[st]; a ++, (val *= v[st]) %= mod)
		(pans += val * dp[a] % mod) %= mod;
	fans = fans * pans % mod;
}

int main() {
	ios::sync_with_stdio(false);
	inv[0] = 1;
	for (int i = 1; i <= 100000; i ++)
		inv[i] = kmi(i, mod - 2);
	cin >> n >> k;
	for (ll i = 2; i * i <= n; i ++) {
		if (n % i == 0) {
			v[++ st] = i;
			while (n % i == 0)
				n /= i, num[st] ++;
			pro();
		}
	}
	if (n != 1) {
		v[++ st] = n;
		num[st] = 1;
		pro();
	}
	cout << fans % mod << endl;
	return 0;
}
