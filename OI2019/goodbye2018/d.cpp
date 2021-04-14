#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

typedef long long ll;
int mod = 998244353;

ll n;

ll kmi (ll x, ll k) {
	ll ans = 1;
	while (k) {
		if (k & 1)	(ans *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return ans;
}
ll inv(ll x) {return kmi(x, mod - 2);}

ll fac[1000010], ifac[1000010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	fac[0] = 1;
	for (int i = 1; i <= n; i ++)		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for (int i = n - 1; i >= 1; i --)	ifac[i] = ifac[i + 1] * (i + 1) % mod;
	ifac[0] = 1;
	
	ll ans = 0;
	for (int i = 1; i <= n; i ++)	
		(ans += (fac[i - 1] - 1) * fac[n] % mod * ifac[i - 1] % mod) %= mod;
	cout << (ans + fac[n]) % mod << endl;
	return 0;
}
