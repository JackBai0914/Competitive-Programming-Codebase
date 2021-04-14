#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n, k;
ll a[100010], b[100010];
ll s[100010], dp[100010];

ll fans = 0;
ll pans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i];
		s[i - 1] = a[i] * b[i - 1];
		pans += s[i - 1];
	}
	dp[0] = 0;

	for (int i = 1; i <= n; i ++) {
		dp[i] = min (s[i - 1] * (k - 1) + s[i] * (k - 1),
			dp[i - 1] + s[i - 1] * (k * k - k) + s[i] * (k - 1));
		fans = min (fans, dp[i]);
	}

	cout << pans + fans << endl;
	// cerr << pans << " " << fans << endl;


	return 0;
}