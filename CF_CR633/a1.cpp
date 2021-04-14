#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
int a[1000010];


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		int mx = -1e9;
		int gap = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			mx = max (mx, a[i]);
			gap = max (gap, mx - a[i]);
		}
		int ans = 0;
		while (gap) {
			ans ++;
			gap /= 2;
		}
		cout << ans << '\n';
	}

	return 0;
}