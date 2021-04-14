#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;
ll a, b;



int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> m;
		ll ans = 1e12;
		for (int i = 1; i <= n; i ++) {
			cin >> a >> b;
			ans = min (ans, ((m - 1) / a + 1) * b);
		}
		cout << ans << endl;
	}

	return 0;
}