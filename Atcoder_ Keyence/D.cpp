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

int n;
int a[110], b[110];

int ha[110], hb[110];

void Swap (int x) {
	swap (ha[x], hb[x]);
	swap (ha[x + 1], hb[x + 1]);
	swap (ha[x], ha[x + 1]);
	swap (hb[x], hb[x + 1]);
}

int flag[22];
int x[22], y[22];

int find () {
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int tg = y[i];
		int find = -1;
		for (int j = i; j <= n; j ++)
			if (x[j] == tg)
				if ((flag[j] == 1 && (j - i) % 2 == 0) || (flag[j] == -1 && (j - i) % 2 == 1)) {
					find = j;
					break;
				}
		// for (int j = 1; j <= n; j ++)
			// cerr << "[" << x[j] << " " << y[j] << " " << flag[j] << "]";
		// cerr << endl;
		if (find == -1) {
			// cerr << "cannot find: " << i << " " << tg << endl;
			return -1;
		}
		// cerr << "find: " << find << endl;
		ans += find - i;
		flag[find] = -100;
		for (int j = find; j > i; j --) {
			swap (x[j], x[j - 1]);
			flag[j] *= -1;
			flag[j - 1] *= -1;
			swap (flag[j], flag[j - 1]);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i ++)	cin >> a[i];
	for (int i = 1; i <= n; i ++)	cin >> b[i];

	int st = (1 << n);
	int fans = 10000;
	for (int msk = 0; msk < st; msk ++) {
		int pans = 0;
		int _m = msk;
		memset(flag, 0, sizeof flag);
		memset(x, 0, sizeof x);
		memset(y, 0, sizeof y);
		for (int i = 1; i <= n; i ++, _m >>= 1)
			if (_m & 1) {
				x[i] = a[i];
				y[i] = a[i];
				flag[i] = 1;
			}
			else {
				x[i] = b[i];
				y[i] = b[i];
				flag[i] = -1;
			}
		sort (y + 1, y + n + 1);

		// for (int i = 1; i <= n; i ++)
			// cout << "(" << a[i] << " " << b[i] << " " << flag[i] << " - " << y[i] << ")";
		// cout << endl;
		pans = find();
		// cout << pans << endl;
		if (pans != -1)
			fans = min (fans, pans);
	}
	cout << (fans == 10000 ? -1 : fans) << endl;
	return 0;
}