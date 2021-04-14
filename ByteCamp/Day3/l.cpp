#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef pair <int, int> pii;

ll a, n, m, cur;
ll if_9 (ll x) {
	ll v = 1;
	ll ans = 0;
	while (x) {
		if (x % 10 == 9)
			ans = v;
		v *= 10;
		x /= 10;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> a >> m >> n;
	cur = a;

	ll rd = 0;
	while (n) {
		ll if_ = if_9 (cur);
		if (if_) {
			ll tg = cur / if_ * if_ + if_;
			ll ti = (tg - 1 - cur) / 9 + 1;
			if (a <= )
		}
	}

	return 0;
}