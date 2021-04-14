#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m;
ll fac[1000010];

ll ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	fac[1] = 1;
	for (int i = 2; i <= n; i ++)
		fac[i] = fac[i - 1] * i % m;
	for (int i = 1; i <= n; i ++) {
		ll pans = (n - i + 1);
		(pans *= fac[i] * fac[n - i + 1] % m) %= m;
		(ans += pans) %= m;
	}
	cout << ans << endl;
	return 0;
}