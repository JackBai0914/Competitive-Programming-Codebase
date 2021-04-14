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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool reachable (int x, int y, int n) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll minus = 0;
	for (ll k = 1; k <= n; k ++) {
		ll all = k * k * (k * k - 1) / 2;
		for (int i = 2; i <= k; i ++) {
			int x = 1, y = i;
			minus += reachable (x + 1, y + 2, k);
			minus += reachable (x + 1, y - 2, k);
			minus += reachable (x + 2, y + 1, k);
			minus += reachable (x + 2, y - 1, k);
		}
		for (int i = 2; i <= k; i ++) {
			int x = i, y = 1;
			minus += reachable (x + 2, y + 1, k);
			minus += reachable (x - 2, y + 1, k);
			minus += reachable (x + 1, y + 2, k);
			minus += reachable (x - 1, y + 2, k);
		}
		if (k >= 3)
			minus -= 2;
		minus += reachable(1 + 2, 1 + 1, k);
		minus += reachable(1 + 1, 1 + 2, k);
		cout << all - minus << endl;
	}

	return 0;
}