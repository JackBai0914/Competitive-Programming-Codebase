#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n;
vector <int> son[100010];
int p[100010], h[100010], s[100010], a[100010];

vector <int> nd[100010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	h[1] = 1;
	for (int i = 2; i <= n; i ++) {
		cin >> p[i];
		son[p[i]].push_back(i);
		h[i] = h[p[i]] + 1;
	}	

	for (int i = 1; i <= n; i ++)
		cin >> s[i];

	a[1] = s[1];
	for (int i = 2; i <= n; i ++) {
		if (s[i] != -1) {
			int g = p[p[i]];
			nd[p[i]].push_back(s[i] - s[g]);
		}
	}

	bool ok = 1;

	for (int i = 2; i <= n; i ++) {
		if (s[i] == -1) {
			int mn = 2e9;
			for (int j = 0; j < nd[i].size(); j ++) {
				int r = nd[i][j];
				if (r < 0)
					ok = 0;
				mn = min(mn, r);
			}
			if (mn == 2e9)
				a[i] = 0;
			else
				a[i] = mn;
		}
	}

	for (int i = 2; i <= n; i ++) {
		if (s[i] != -1) {
			int g = p[p[i]];
			a[i] = s[i] - s[g] - a[p[i]];
		}
	}

	if (ok == 0) {
		cout << -1 << endl;
		return 0;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += a[i];
	cout << ans << endl;
	return 0;
}
