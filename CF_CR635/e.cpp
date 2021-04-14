#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
const int mod = 998244353;

int popcount(ll x) {if (!x) return 0; return (x&1)+popcount(x>>1);}



int n, m;
ll a[200020], pow2[200020];

namespace LinearBase {
	const int maxLen = 37;
	int num = 0, spare;
	ll b[maxLen];
	void add (ll x) {
		for (int i = m - 1; i >= 0 && x; i --)
			if (x >> i & 1) {
				if (!b[i]) {
					num ++;
					b[i] = x;
					for (int j = i - 1; j >= 0; j --)
						if (b[i] >> j & 1)
							b[i] ^= b[j];
					for (int j = m - 1; j > i; j --)
						if (b[j] >> i & 1)
							b[j] ^= b[i];
					return ;
				}
				else
					x ^= b[i];
			}
	}

	int extract (ll x) {
		int ans = 0;
		for (int i = 0; i < m; i ++, x >>= 1) {
			if (b[i]) {
			}
			else
				(ans *= 2) += (x & 1);
		}
		return ans;
	}
} using namespace LinearBase;

ll dp[2][maxLen][1<<16];

ll fans[maxLen];
ll pans[maxLen];

void dfs (int id, ll x) {
	if (id == m) {
		pans[popcount(x)] ++;
		return ;
	}
	dfs (id + 1, x);
	if (b[id])
		dfs (id + 1, x ^ b[id]);
}

int main() {
	ios::sync_with_stdio(false);
	pow2[0] = 1;
	for (int i = 1; i <= 200000; i ++)
		pow2[i] = pow2[i - 1] * 2 % mod;
	memset (b, 0, sizeof b);

	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		add (a[i]);
	}

	if (num <= 23) {
		dfs (0, 0);
		for (int i = 0; i <= m; i ++)
			cout << pans[i] * pow2[n - num] % mod << ' ';
		cout << endl;
		return 0;
	}

	spare = (1ll << (m - num + 1));

	dp[1][0][0] = 1;
	bool ter = 0;
	for (int i = 0; i < m; i ++)
		if (b[i]) {
			int v = extract(b[i]);
			for (int j = 0; j <= num; j ++)
				for (int k = 0; k < spare; k ++) {
					dp[ter][j][k] = dp[ter ^ 1][j][k];
					if (j)
						(dp[ter][j][k] += dp[ter ^ 1][j - 1][k ^ v]) %= mod;
				}
			ter ^= 1;
		}

	memset (fans, 0, sizeof fans);
	for (int j = 0; j <= num; j ++)
		for (int k = 0; k < spare; k ++)
			(fans[j + popcount(k)] += dp[ter ^ 1][j][k]) %= mod;
	for (int i = 0; i <= m; i ++) {
		(fans[i] *= pow2[n - num]) %= mod;
		cout << fans[i] << ' ';
	}
	cout << endl;
	return 0;
}