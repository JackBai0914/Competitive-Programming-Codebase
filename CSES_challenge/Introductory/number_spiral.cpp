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



ll find (ll x, ll y) {
	ll lyer = max (x, y);
	ll pre = (lyer - 1) * (lyer - 1);
	if (lyer % 2) {
		if (x == lyer)
			return pre + y;
		return pre + lyer + lyer - x;
	}
	else {
		if (y == lyer)
			return pre + x;
		return pre + lyer + lyer - y;
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t --) {
		int x, y;
		cin >> x >> y;
		cout << find(x, y) << endl;
	}

	return 0;
}