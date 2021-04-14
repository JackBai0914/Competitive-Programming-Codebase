#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

priority_queue <pair <int, int> > q;
ll n, k;
ll a[200020]; 

const ld eps = 1e-7;
ld Floor (ld x) {return floor (x + eps);}
ld delta (ld a, ld b, ld c) {return b*b-4*a*c;}
ll calc (ld a, ld b, ld c) {
	if (delta(a, b, c) < -eps)
		return 0;
	if (a < 0)
		a = -a, b = -b, c = -c;
	// cout << "ans for " << a << "x^2+" << b << "x+" << c << "==0 : " << (-b+sqrt(delta(a, b, c)))/2/a << " :: " << (-b-sqrt(delta(a, b, c)))/2/a << endl;
	return Floor((-b+sqrt(delta(a, b, c)))/2/a);
}

int ans[200020], ans2[200020];

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	ll st = -(1ll<<62), ed = 1e10;
	while (st != ed) {
		ll mid = (st + ed) >> 1;
		// cout << "beg: " << st << " " << mid << " " << ed << endl;
		ll num = 0;
		for (int i = 1; i <= n; i ++) {
			// cout << "num=" << num << " ";
			num += min(a[i], calc (-3, -3, -1+a[i]-mid)+1);
			// cout << i << " : " << calc (-3, -3, -1+a[i]-mid)+1 << endl;
		}
		// cout << "res: " << st << " " << mid << " " << ed << " " << num << endl;
		if (num > k)
			st = mid + 1;
		if (num <= k)
			ed = mid;
	}
	ed --;
	int pay = k;
	for (int i = 1; i <= n; i ++) {
		ans[i] = min(a[i], calc (-3, -3, -1+a[i]-st) + 1);
		ans2[i] = min(a[i], calc (-3, -3, -1+a[i]-ed) + 1);
		pay -= ans[i];
	}
	for (int i = 1; i <= n; i ++) {
		if (pay && ans2[i] - ans[i] != 0) {
			ans[i] ++;
			pay --;
		}
	}
	for (int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}