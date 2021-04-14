#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <queue>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-6;
int n, fans = 0;
ld c1, c2, c3;
pair <int, int> v[2020];
ld key[2020];

pair <ld, int> x[2020], y[2020], z[2020];


int work (int fix) {
	// cerr << "new: " << fix << endl;
	int pans = 0, cans = 0;
	int xst = 0, zst = 0;

	for (int i = 1; i <= n; i ++) {
		if (fix <= v[i].F && v[i].F <= c3/c1 + eps) {
			x[++ xst] = MP(-v[i].S, i);
			z[++ zst] = MP(-key[i], i);
		}
	}

	sort(x + 1, x + xst + 1);
	sort(z + 1, z + zst + 1);

	while (xst != 0 && zst != 0) {
		int x1 = x[xst].S, x2 = z[zst].S;
		ld cand1 = v[x1].S;
		ld cand2 = v[x2].S + (v[x2].F - fix) * c1 / c2 - c3 / c2;
		if (cand1 < cand2 - eps) {
			xst --;
			cans --;
		}
		else {
			zst --;
			cans ++;
		}
		pans = max(pans, cans);
	}
	return pans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> c1 >> c2 >> c3;
	for (int i = 1; i <= n; i ++) {
		cin >> v[i].F >> v[i].S;
		key[i] = v[i].S + v[i].F * c1 / c2;
	}

	for (int i = 1; i <= n; i ++) {
		fans = max(fans, work (v[i].F));
	}

	cout << fans << endl;
	return 0;
}