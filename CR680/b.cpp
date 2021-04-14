/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-01 11:29:19
* @description: 
* /Users/jackbai/Desktop/cf/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int mod = 998244353 ; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

ll fac[1000010], ifac[1000010], inv[1000010];

ll kmi (ll x, ll t) {
	ll ans = 1;
	for(x %= mod; t; t >>= 1, (x *= x) %= mod)
		if (t & 1)
			(ans *= x) %= mod;
	return ans;
}
void init () {
	fac[0] = ifac[0] = 1, inv[0] = 0;
	for (int i = 1; i <= 1000000; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[1000000] = kmi (fac[1000000], mod - 2);
	for (int i = 999999; i >= 1; i --)
		ifac[i] = ifac[i + 1] * (i + 1) % mod;
	// cerr << "check: " << fac[233] * ifac[233] % mod << endl;
}
ll C (int n, int m) {
	if (m > n)
		return 0;
	if (m == n)
		return 1;
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int n;
ll a[1000010];

int main() {
	init();
	cin >> n;
	F0R(i, 2 * n)
		cin >> a[i];
	sort(a, a + 2 * n);

	ll fans = 0;

	for (int i = 0; i < 2 * n; i ++) {
		ll pans = 0;
		ll l = i, r = 2 * n - i - 1;
		//in ascending p
		if (r > n - 1)	pans -= a[i] * C(l + r, n - 1) % mod;
		else			pans += a[i] * C(l + r, n - 1) % mod;

		//in q
		if (l > n - 1)	pans += a[i] * C(l + r, n - 1) % mod;
		else			pans -= a[i] * C(l + r, n - 1) % mod;

		// cerr << i << " : " << pans << endl;
		(fans += (pans % mod + mod)) %= mod;
	}
	cout << fans << endl;

    return 0;
}