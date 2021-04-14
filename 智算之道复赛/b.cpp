#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n, k, w1, w2;
pii spe[2020];
ll dp[2020];

bool ord (pii a, pii b) {
	return (a.F == b.F ? a.S < b.S : a.F < b.F);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> w1 >> w2;
	ll pans = 2 * w1 * n;
	if (2 * w1 <= w2) {
		cout << pans << endl;
		return 0;
	}
	for (int i = 1; i <= k; i ++)
		cin >> spe[i].F >> spe[i].S;
	spe[++ k] = MP(n, n);
	sort (spe + 1, spe + k + 1, ord);
	for (int i = 1; i <= k; i ++) {
		dp[i] = 1;
		for (int j = 1; j < i; j ++)
			if (spe[i].F > spe[j].F && spe[i].S > spe[j].S)
				dp[i] = max (dp[i], dp[j] + 1);
	}
	cout << pans - (dp[k] - 1) * (2 * w1 - w2) << endl;

	return 0;
}