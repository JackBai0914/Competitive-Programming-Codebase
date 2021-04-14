#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll oo = 1e12;
int n, T;
pii f[200020];

vector <int> ord[200020];
int mn[200020], mx = 0;
ll ans[200020];

ll get_ans(int p, int x, int y) {
	ll pans = oo;
	for (int i = ord[p].size() - 1; i >= 0 && f[ord[p][i]].S <= y; i --)
		pans = min(pans, ans[ord[p][i]] + (ll)(y - f[ord[p][i]].S) * (x - f[ord[p][i]].F));
	return pans;
}

int dich(int v) {
	int l = 0, r = mx;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		if (f[mn[mid]].S <= v)	l = mid;
		else					r = mid - 1;
	}
	return l;
}

int main() {
	freopen("mowing.in", "r", stdin);
	freopen("force.out", "w", stdout);
	cin >> n >> T;
	for (int i = 1; i <= n; i ++)
		cin >> f[i].F >> f[i].S;
	f[++ n] = MP(T, T);
	sort(f + 1, f + n + 1);

	ord[0].push_back(0);
	for (int i = 1; i <= n; i ++) {
		if (f[i].S >= f[mn[mx]].S) {
			ans[i] = get_ans(mx, f[i].F, f[i].S);
			mx ++;
			mn[mx] = i;
			ord[mx].push_back(i);
		}
		else {
			int p = dich(f[i].S) + 1;
			ans[i] = get_ans(p - 1, f[i].F, f[i].S);
			mn[p] = i;
			ord[p].push_back(i);
		}
		// cout << ": " << i << " " << f[i].F << " " << f[i].S << " " << ans[i] << endl;
	}
	cout << ans[n] << endl;
	return 0;
}