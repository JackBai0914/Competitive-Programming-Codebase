#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, x, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> x;
	ll a, b;
	ans += n;
	a = x, b = n - x;
	while (a && b) {
		if (a < b)
			swap (a, b);
		ans += a / b * 2 * b;
		a %= b;
	}
	ans -= b;
	cout << ans << endl;

	return 0;
}