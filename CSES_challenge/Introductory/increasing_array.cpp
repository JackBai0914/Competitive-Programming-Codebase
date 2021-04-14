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

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	int a[1000010];
	cin >> n;
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (i != 1)
			ans += max (0, a[i - 1] - a[i]);
		a[i] = max (a[i], a[i - 1]);
	}
	cout << ans << endl;

	return 0;
}