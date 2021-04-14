#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;

int n, ans = 0;
pair <int, int> b[1000010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int x, l;
		cin >> x >> l;
		b[i] = make_pair(x + l, x - l);
	}
	sort(b + 1, b + n + 1);
	int last = -2000000001;
	for (int i = 1; i <= n; i ++) {
		if (b[i].second >= last) {
			last = b[i].first;
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}