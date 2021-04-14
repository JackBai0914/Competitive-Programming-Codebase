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
typedef long long ll;
const int mod = 1e9 + 7;
ll n, k, q;
ll a[500050];

ll kmi (ll x, ll t) {
	ll ans = 1;
	for (x %= mod; t; t >>= 1, (x *= x) %= mod)
		if (t & 1)
			(ans *= x) %= mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	cout << kmi((1 << q), n * n - n - 1) << endl;
	return 0;
}