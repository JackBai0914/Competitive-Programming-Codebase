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
ll n, s, d;
ll mn[100010];

ll check(ll x, ll n) {
	ll cnt = 0;
	ll ti = 1, ci = 1;
	ll ss = 0;
	while (cnt < n) {
		ll num = min(ti, n - cnt);
		ss += num * ci;
		cnt += num;
		ci ++;
		ti *= x;
	}
	return ss;
}

ll D[100010];

ll cur = 0, all = 1;

void dfs(ll now, ll dep) {
	if (!s || now > n)
		return ;

	ll mn, mx;
	//same;
	if (cur) {
		mx = dep + dep * (n - now) + (n - now) * (n - now + 1) / 2;
 		if (s <= mx) {
			s -= dep;
			cur --;
			D[now] = dep;
			return dfs(now + 1, dep);
		}
	}

	s -= dep + 1;
	cur = all = all * d;
	D[now] = dep + 1;
	dfs(now + 1, dep + 1);

}

int dg[100010];


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> s;

	if (n * (n + 1) / 2 < s || s < 2 * n - 1) {
		cout << "No" << endl;
		return 0;
	}

	for (int i = 1; i <= n; i ++)
		mn[i] = check(i, n);

	int l = 1, r = n;
	while (l != r) {
		if (mn[(l + r) >> 1] <= s)	r = ((l + r) >> 1);
		else						l = ((l + r) >> 1) + 1;
	}
	D[1] = 1;
	d = l;
	for (int i = 1; i <= n; i ++)
		mn[i] = check(d, i);
	
	s --;
	dfs(2, 1);
	cout << "Yes" << endl;
	int pt = 1;
	for (int i = 2; i <= n; i ++) {
		while (dg[pt] == d || D[pt] != D[i] - 1)
			pt ++, dg[pt] ++;
		cout << pt << " ";
	}
	cout << endl;

	return 0;
}
