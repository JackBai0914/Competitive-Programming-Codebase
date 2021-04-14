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
typedef long long ll;
const int mod = 1e9 + 7;
int n;
ll fac[100010];
ll x[100010];
ll fans = 0;

ll kmi (ll x, ll t) {
	ll ans = 1;
	for (x %= mod; t; t >>= 1, x = (x * x) % mod)
		if (t % 2)
			(ans *= x) %= mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ll cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
		if (i == 1)
			continue ;
		(cnt += fac[n - 1] * kmi (i - 1, mod - 2) % mod) %= mod;
		(fans += cnt * (x[i] - x[i - 1]) % mod) %= mod;
	}
	cout << fans << endl;
	return 0;
}