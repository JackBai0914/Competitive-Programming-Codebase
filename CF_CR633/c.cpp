#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ll n;

ll fir, sec, thi;
void solve (ll x, ll phase, ll bef) {
	ll len = (1ll << (phase * 2 - 2));
	if (len + bef < x) {
		solve (x, phase + 1, len + bef);
		return ;
	}
	
	fir = len - 1 + (x - bef);
	ll id = x - bef - 1, extra = 0, basic = len * 2;

	// cerr << "id : " << id << endl;

	ll wei = 1;
	while (id) {
		int c = id % 4;
		if (c == 0)	extra += 0;
		if (c == 1)	extra += wei * 2;
		if (c == 2)	extra += wei * 3;
		if (c == 3)	extra += wei * 1;

		wei *= 4;
		id /= 4;
	}


	// cerr << "extra : " << extra << endl;
	// cerr << "basic : " << basic << endl;

	sec = basic + extra;
	thi = fir ^ sec;
	// cerr << "get it : " << fir << " " << sec << endl;
}

int main() {
	// freopen("text.out", "w", stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		solve ((n - 1) / 3 + 1, 1, 0);
		if (n % 3 == 1)	cout << fir << '\n';
		if (n % 3 == 2)	cout << sec << '\n';
		if (n % 3 == 0)	cout << thi << '\n';
	}


	return 0;
}
// cin >> n;
// 	for (int i = 1; i <= n; i += 3) {
// 		int find = false;
// 		for (int x = 1; x && !find; x ++)
// 			if (flag[x] == 0)
// 				for (int y = x + 1; y && !find; y ++)
// 					if (flag[y] == 0) {
// 						int z = x ^ y;
// 						if (flag[z] == 0) {
// 							flag[x] = flag[y] = flag[z] = 1;
// 							a[++ st] = x;
// 							a[++ st] = y;
// 							a[++ st] = z;
// 							cout << x << " " << y << " " << z << endl;
// 							find = true;
// 						}
// 					}
// 	}
// 	// for (int i = 1; i <= n; i ++) {
// 	// 	cout << a[i] << " ";
// 	// }
// 	// cout << endl;