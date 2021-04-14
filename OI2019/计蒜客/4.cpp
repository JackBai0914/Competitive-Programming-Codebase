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
#define TIME (double)clock()/CLOCKS_PER_SEC
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int BL = 200;
int n, q;
pii a[200020], b[200020];
int bst = 0;

pii rec[2020][110];
int rst[2020];

void calc(int st, int ed, int id) {
	rst[id] = 0;
	for (int i = st; i < ed; i ++)
		b[i - st + 1] = a[i];
	sort(b + 1, b + ed - st + 1);
	for (int i = 1; i <= ed - st; i ++) {
		while (rst[id] != 0 && b[i].S >= rec[id][rst[id]].S)
			rst[id] --;
		rec[id][++ rst[id]] = b[i];
	}
}

pii hp[2020];
int hst = 0;
inline void combine(int id) {
	hst = 0;
	int pt0 = 1, pt = 1;
	while (pt0 <= rst[0] || pt <= rst[id]) {
		pii x;

		if (pt0 > rst[0])							x = rec[id][pt ++];
		else if (pt > rst[id])						x = rec[0][pt0 ++];
		else if (rec[id][pt].F <= rec[0][pt0].F)	x = rec[id][pt ++];
		else if (rec[id][pt].F > rec[0][pt0].F)		x = rec[0][pt0 ++];
		// cout << "chosen " << x.F << " " << x.S << " " << pt0 << " " << pt << endl;
		if (hst != 0 && x.F == hp[hst].F && x.S <= hp[hst].S) {
			if (x.S == hp[hst].S)
				hst --;
			continue ;
		}
		while (hst != 0 && x.S >= hp[hst].S)
			hst --;
		// cout << hst + 1 << " " << x.S << " " << hp[hst].S << endl;
		hp[++ hst] = x;
	}
	for (int i = 1; i <= hst; i ++)
		rec[0][i] = hp[i];
	rst[0] = hst;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].F >> a[i].S;
	for (int cnt = 1, i = 1; i <= n; i += BL, cnt ++) {
		calc(i, min(n + 1, i + BL), cnt);
		// cout << "len = " << rst[cnt] << " " << i << " " << min(n + 1, i + BL) << endl;
	}
	cin >> q;
	long long ans;
	for (int l, r, i = 1; i <= q; i ++) {
		cin >> l >> r;
		int st = (l - 1) / BL + 2;
		int ed = (r - 1) / BL;
		if (st - ed == 2) {
			rst[0] = 0;
			calc(l, r + 1, 0);
			ans = 1;
			for (int j = 1; j <= rst[0]; j ++) {
				(ans *= (rec[0][j].F ^ rec[0][j].S)) %= mod;
				// cout << ": " << rec[0][j].F << " " << rec[0][j].S << endl;
			}
			cout << ans << '\n';
			continue ;
		}	
		// cout << "C " << endl;
		bst = 0;
		for (int j = l; j < (st - 1) * BL + 1; j ++)
			b[++ bst] = a[j];
		for (int j = ed * BL + 1; j <= r; j ++)
			b[++ bst] = a[j];
		sort(b + 1, b + bst + 1);
		rst[0] = 0;
		for (int j = 1; j <= bst; j ++) {
			while (rst[0] != 0 && b[j].S >= rec[0][rst[0]].S)
				rst[0] --;
			rec[0][++ rst[0]] = b[j];
		}
		// for (int k = 1; k <= rst[0]; k ++)
				// cout << 0 << ": " << rec[0][k].F << " " << rec[0][k].S << endl;
		for (int j = st; j <= ed; j ++) {
			combine(j);
			// for (int k = 1; k <= rst[0]; k ++)
				// cout << j << ": " << rec[0][k].F << " " << rec[0][k].S << endl;
		}
		ans = 1;
		for (int j = 1; j <= rst[0]; j ++) {
			(ans *= (rec[0][j].F ^ rec[0][j].S)) %= mod;
			// cout << ": " << rec[0][j].F << " " << rec[0][j].S << endl;
		}
		cout << ans << '\n';
	}
	// cerr << TIME << endl;
	return 0;
}