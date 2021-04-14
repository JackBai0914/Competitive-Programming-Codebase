#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;

int n;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		ll ans = 0;
		for (ll i = 1; i <= n / 2; i ++) {
			ans += 2 * i * 4 * i;
		}
		cout << ans << endl;
	}

	return 0;
}