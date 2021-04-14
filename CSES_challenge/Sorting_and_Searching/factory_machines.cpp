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

ll n, m;
ll k[1000010];

ll output (ll t) {
	ll ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += t / k[i];
		if (ans >= 1e9)
			return ans;
	}
	// cerr << t << " : " << ans << endl;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> k[i];

	ll st = 0, ed = 1e18;

	while (st < ed) {
		ll mid = (st + ed) >> 1;
		ll check = output(mid);
		if (check < m)
			st = mid + 1;
		else
			ed = mid;
	}
	cout << st << endl;

	return 0;
}
