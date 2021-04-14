#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int a[110], b[110];

int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int x = 1; x <= k; x ++) {
		for  (int i = 1; i <= n; i ++)
			b[i] = a[i];
		for (int j = x; j <= n; j += k)
			b[j] = 0;
		int num = 0;
		for (int i = 1; i <= n; i ++)
			num += b[i];
		ans = max(ans, abs(num));
	}
	cout << ans << endl;
	return 0;
}