#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int mod = 1e9 + 7;
const int V = 1e9;
typedef long long ll;
int n, k;
int pst[100010], ped[100010];
ll v[100010], mx[100010];
ll q[100010], st = 0, ed = 1;

ll mi[100010], dp[100010], sdp[100010];
ll kmi (ll x, ll t) {
	ll ans = 1;
	while (t) {
		if (t % 2)	(ans *= x) %= mod;
		(x *= x) %= mod;
		t >>= 1;
	}
	return ans;
}
ll Dp (int len, ll v, ll x, ll y) {
	// cout << "Dp : " << len << " " << v << " " << x << " " << y << endl;
	dp[0] = sdp[0] = mi[0] = 1;
	for (int i = 1; i <= len; i ++)
		dp[i] = sdp[i] = 0, mi[i] = mi[i - 1] * (V - v) % mod;
	for (int i = 1; i <= len; i ++) {
		if (i - k - 1 < 0) {
			if (x != -1 && i > x)	dp[i] = (sdp[i - 1] - sdp[0] * mi[i - 1] % mod + mod) % mod;
			else					dp[i] = sdp[i - 1];
		}
		else
			dp[i] = (sdp[i - 1] - sdp[i - k - 1] * mi[k] % mod + mod) % mod;			
		sdp[i] = (sdp[i - 1] * mi[1] % mod + dp[i]) % mod;
		// cout << "dp " << i << " = " << dp[i] << ", sdp " << i << " = " << sdp[i] << endl;
	}
	ll ans = 0;
	if (y == -1) {
		for (int i = len; i >= max(1, len - k + 1); i --)
			(ans += dp[i] * mi[len - i] % mod) %= mod;
		return ans;
	}
	else {
		for (int i = len; i >= y; i --) {
			(ans += dp[i] * mi[len - i] % mod) %= mod;
			// cout << "cans : " << ans << endl;
		}
		return ans;
	}
}

int stk[100010], sst = 0, sed = 1;

int main() {
	freopen("tracking2.in", "r", stdin);
	freopen("tracking2.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		while (ed <= st && q[ed] <= i - k)
			ed ++;
		if (i <= n - k + 1) {
			cin >> v[i];
			pst[i] = v[i];
			ped[i + k - 1] = v[i];
			while (ed <= st && v[q[st]] <= v[i])
				st --;
			q[++ st] = i;
		}
		mx[i] = v[q[ed]];
	}

	ll ans = 1;
	for (int j = 1, i = 1; i <= n; i = j + 1, j = i) {
		while (j + 1 <= n && mx[j + 1] == mx[i])
			j ++;
		int x = -1, y = -1;
		for (int k = i; k <= j; k ++)	if (ped[k] == mx[i])	{x = k - i + 1; break;}
		for (int k = j; k >= i; k --)	if (pst[k] == mx[i])	{y = k - i + 1; break;}	
		(ans *= Dp(j - i + 1, mx[i], x, y)) %= mod;
		// cout << "ans : " << ans << endl;
	}
	// cerr << ans << endl;
	cout << ans << endl;
	return 0;
}