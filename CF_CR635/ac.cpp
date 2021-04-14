#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#define debug(x) cerr << #x << " " << (x) << endl
using namespace std;

const int N = 200005, M = 150;
const long long mod = 998244353ll, inv2 = mod + 1 >> 1;

int n, m, half, dim = 0;
long long a[N], vec[M];

void fwt (long long *x) {
	for (int i = 1; i < (1 << half); i <<= 1) {
		for (int j = 0; j < (1 << half); j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				long long u = x[j + k], v = x[j + k + i];
				x[j + k] = (u + v) % mod;
				x[j + k + i] = (u + mod - v) % mod;
			}
		}
	}
}

void ifwt (long long *x) {
	for (int i = 1; i < (1 << half); i <<= 1) {
		for (int j = 0; j < (1 << half); j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				long long u = x[j + k], v = x[j + k + i];
				x[j + k] = (u + v) % mod;
				x[j + k + i] = (u + mod - v) % mod;
			}
		}
	}
	for (int i = 0; i < (1 << half); i++) {
		for (int j = 0; j < half; j++) x[i] = x[i] * inv2 % mod;
	}
}

struct base {
	long long c[M];
	void init () {
		for (int i = 0; i <= m - 1; i++) c[i] = 0ll;
	}
	void insert (long long x) {
		for (int i = m - 1; i >= 0; i--) {
			if ((x >> i) & 1) {
				if (!c[i]) {
					c[i] = x;
					break;
				}
				else x ^= c[i];
			}
		}
	}
	bool check (long long x) {
		for (int i = m - 1; i >= 0; i--) {
			if ((x >> i) & 1) {
				if (!c[i]) return false;
				x ^= c[i];
			}
		}
		return true;
	}
} ;

base b;
bool exist[1 << 18];
long long ans[40], tmp[1 << 18], tmp_[20][1 << 18], tmp2[1 << 18];

int main () {
	freopen ("e.in", "r", stdin);
	freopen ("ac.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	b.init();
	for (int i = 0; i < n; i++) b.insert(a[i]);
	for (int i = 0; i < m; i++) {
		if (b.c[i]) dim++; 
	}

	half = m / 2;
	for (int i = 0; i < (1 << half); i++) {
		long long val = 0;
		for (int j = 0; j < half; j++) {
			if ((i >> j) & 1) val ^= b.c[j];
		}
		tmp[val] = 1ll;
	}


	for (int i = 0; i < (1 << (m - half)); i++) {
		long long i_ = (1ll * i) << half;
		
		bool chk = true;
		long long val = 0ll;
		for (int j = m - 1; j >= half; j--) {
			if ((i_ >> j) & 1) {
				if (!b.c[j]) chk = false;
				val ^= b.c[j];
				i_ ^= b.c[j];
			}
		}
		if (!chk) continue;
		int cnt = 0;
		for (int j = 0; j < m - half; j++) {
			if ((i >> j) & 1) cnt++;
		}
		tmp_[cnt][val ^ ((val >> half) << half)]++;


	}


	fwt(tmp);
	for (int i = 0; i <= m - half; i++) {
		fwt(tmp_[i]);
		for (int j = 0; j < (1 << half); j++) tmp2[j] = tmp[j] * tmp_[i][j] % mod;
		ifwt(tmp2);
		for (int j = 0; j < (1 << half); j++) {
			int cnt = 0;
			for (int k = 0; k < half; k++) {
				if ((j >> k) & 1) cnt++;
			}
			ans[i + cnt] = (ans[i + cnt] + tmp2[j]) % mod;
		}
	}

	long long pw2 = 1ll;
	for (int i = 0; i < n - dim; i++) pw2 = pw2 * 2ll % mod;
	for (int i = 0; i <= m; i++) printf("%lld ", ans[i] * pw2 % mod);
	printf("\n");
	return 0;
}