#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
ll a[100010];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		int ans = 1;
		cin >> n;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		ll mn = 1e10, mx = 0;
		for (int i = n; i >= 1; i --) {
			mn = min (mn, a[i]);
			mx = max (mx, a[i] - mn);
		}
		if (mx == 0) {
			cout << 0 << '\n';
			continue ;
		}
		ll gap = 2;
		for (; gap - 1 < mx; gap *= 2, ans ++) {}
		cout << ans << '\n';
	}
	return 0;
}