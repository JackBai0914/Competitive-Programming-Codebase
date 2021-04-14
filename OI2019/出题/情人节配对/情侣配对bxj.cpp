#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
const int mod = 998244353;
const int mx = 1e5;
typedef long long ll;

namespace Inverse {
	ll fac[mx + 10], ifac[mx + 10], inv[mx + 10];
	ll kmi (ll x, ll t) {
		ll ans = 1;
		for (t %= mod - 1; t; (x *= x) %= mod, t >>= 1)
			if (t & 1)
				(ans *= x) %= mod;
		return ans;
	}
	ll inverse(ll x) {return kmi(x, mod - 2);}
	ll C(int n, int m) {return fac[n] * ifac[m] % mod * ifac[n - m] % mod;}
	void Inv_work() {
		fac[0] = ifac[0] = inv[0] = inv[1] = 1;
		for (int i = 1; i <= mx; i ++)
			fac[i] = fac[i - 1] * i % mod;
		ifac[mx] = inverse(fac[mx]);
		for (int i = mx - 1; i; i --)
			ifac[i] = ifac[i + 1] * (i + 1) % mod,
			inv[i + 1] = ifac[i + 1] * fac[i] % mod;
	}
}using namespace Inverse;

namespace NTT {
	const int MX = 4e5;
	const int RT = 3;
	int rev[MX], wn[MX];
	void prep (int len) {
		for (int i = 1; i < len; i ++)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? len >> 1 : 0);
		for (int i = 1; (1 << i) <= len; i ++)
			wn[i] = kmi(RT, (mod - 1) >> i);
	}
	void ntt(vector <ll> &a, int len, int I) {
		for (int i = 0; i < len; i ++)
			if (rev[i] > i)
				swap(a[i], a[rev[i]]);
		for (int id = 1, i = 1; i < len; i <<= 1, id ++) {
			ll now = wn[id];
			for (int j = 0; j < len; j += i << 1) {
				ll w = 1;
				for (int k = 0; k < i; k ++) {
					ll x = a[j + k], y = a[j + i + k] * w % mod;
					a[j + k] = (x + y) % mod;
					a[j + i + k] = (x - y + mod) % mod;
					(w *= now) %= mod;
				}
			}
		}
		if (I == -1) {
			for (int i = 0; i < len; i ++)
				(a[i] *= inv[len]) %= mod;
			for (int i = 1; i < (len >> 1); i ++)
				swap(a[i], a[len - i]);
		}
	}
	vector <ll> work(vector <ll> a, vector <ll> b) {
		vector <ll> c;
		int len;
		for (len = 1; len < a.size() + b.size() - 1; len <<= 1);
		a.resize(len);
		b.resize(len);
		c.resize(len);
		// cout << "NTT res : " << endl;
		// for (int i = 0; i < len; i ++)	cout << a[i] << " "; cout << endl;
		// for (int i = 0; i < len; i ++)	cout << b[i] << " "; cout << endl;
		prep(len);
		ntt(a, len, 1);
		ntt(b, len, 1);
		for (int i = 0; i < len; i ++)
			c[i] = a[i] * b[i] % mod;
		ntt(c, len, -1);
		// for (int i = 0; i < len; i ++)	cout << c[i] << " "; cout << endl;
		// cout << "Done " << endl;
		return c;
	}
};

ll n, m, sum = 0, fans = 0;
int main() {
	ios::sync_with_stdio(false);
	Inv_work();
	cin >> n >> m;
	for (int v, i = 1; i <= n; i ++)
		cin >> v, sum += v;
	sum %= mod;
	vector <ll> f, g, S;
	f.resize(n + 1);
	g.resize(n + 1);
	for (int i = 0; i <= n; i ++)
		f[i] = ((i & 1) ? -1 : 1) * ifac[i], 
		g[i] = kmi(i, m) * ifac[i] % mod;
	S = NTT::work(f, g);
	for (int i = 0; i <= n; i ++)
		(S[i] *= fac[i]) %= mod;
	for (int i = 0; i <= n; i ++) {
		(fans += S[i] * C(n, i) % mod * i % mod) %= mod;
		// cout << "contr : " << S[i] << " " << C(n, i) << " " << i << endl;
	}
	(fans *= sum) %= mod;
	(fans *= inverse(kmi(n, m))) %= mod;
	cout << fans << endl;
	return 0;
}