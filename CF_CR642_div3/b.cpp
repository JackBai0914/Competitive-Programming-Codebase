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

int n, k;
int a[100010], b[100010];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++)	cin >> a[i];
		for (int i = 1; i <= n; i ++)	cin >> b[i];
		sort (a + 1, a + n + 1);
		sort (b + 1, b + n + 1);
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (i <= k) {
				sum += max (a[i], b[n - i + 1]);
			}
			else
				sum += a[i];
		}
		cout << sum << endl;
	}

	return 0;
}