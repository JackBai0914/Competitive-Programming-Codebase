#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
ll a[1000010];

bool check (ll lim) {
	int cnt = 1;
	ll cur = 0;
	for (int i = 1; i <= n; i ++) {
		if (cur + a[i] > lim)
			cur = 0, cnt ++;
		cur += a[i];
		if (cur > lim)
			return false;
	}
	return (cnt <= k);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	ll st = 0, ed = 1e17;
	while (st != ed) {
		ll mid = (st + ed) >> 1;
		// cerr << st << " " << ed << " " << mid << " : " << check(mid) << endl;
		if (check(mid))
			ed = mid;
		else
			st = mid + 1;
	}
	cout << st << endl;
	return 0;
}
