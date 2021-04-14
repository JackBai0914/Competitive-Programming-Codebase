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
typedef long long ll;
int n, m;
ll v[110][110];
vector <ll> cand;

ll mn[110][110];

ll calc(ll v) {
	if (v > 0)
		return 1e18;
	else
		return -v;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		ll fans = 1e18;
		cand.resize(0);
		cin >> n >> m;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++) {
				cin >> v[i][j];
				cand.push_back(v[i][j] - i + 1 - j + 1);
			}
		for (int i = 0; i < cand.size(); i ++) {
			ll val = cand[i];
			for (int j = 1; j <= n; j ++)
				for (int k = 1; k <= m; k ++) {
					if (j == 1 && k == 1)	mn[j][k] = calc(val+j-1+k-1 - v[j][k]);
					else if (j == 1)		mn[j][k] = mn[j][k-1] + calc(val+j-1+k-1 - v[j][k]);
					else if (k == 1)		mn[j][k] = mn[j-1][k] + calc(val+j-1+k-1 - v[j][k]);
					else					mn[j][k] = min(mn[j-1][k], mn[j][k-1]) + calc(val+j-1+k-1 - v[j][k]);
					mn[j][k] = min (mn[j][k], (ll)1e18);
				}
			// cerr << ": " << val << endl;
			// for (int j = 1; j <= n; j ++) {
			// 	for (int k = 1; k <= m; k ++)
			// 		cerr << mn[j][k] << "(" << abs(val+j-1+k-1 - v[j][k]) << ") ";
			// 	cerr << endl;
			// }
			fans = min (fans, mn[n][m]);
		}
		cout << fans << endl;
	}

	return 0;
}