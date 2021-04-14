#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, a[550][550], x, y;
vector <int> source[550][550];

int dis (pii a, pii b)	{
	return abs (a.F - b.F) + abs(a.S - b.S);
}

int v[11], s[11], st = 0;
int pre[30], pt = 0;
int calc_date(int x, int y) {
	memset(v, 0, sizeof v);
	memset(s, 0, sizeof s);
	st = 0, pt = 0;
	for (int i = -3; i <= 3; i ++)
		for (int j = -3; j <= 3; j ++) {
			int x2 = x + i, y2 = y + j;
			if (x2 < 1 || x2 > n || y2 < 1 || y2 > n)
				continue ;
			if (i == 0 && j == 0)
				continue ;
			if (abs(i) + abs(j) > 3)
				continue ;
			pre[++ pt] = a[x2][y2];
		}

	sort (pre + 1, pre + pt + 1);
	for (int i = pt, j = 1; i >= 1 && j <= 9; i --, j ++) {
		v[++st] = pre[i];
		s[st] = s[st - 1] + v[st];
	}

	int food = 0, prod = 0, date = 0;
	for (int i = 1; i <= 8; i ++) {
		if (st >= i)
			prod += v[i];
		int lim = 8 * i * i;
		int dt = (lim - food - 1) / prod + 1;
		if (food >= lim)
			dt = 0;
		food += dt * prod;
		date += dt;
	}
	return date;
}


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		int fans = 1e9;
		cin >> n >> x >> y;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++) {
				fans = min (fans, calc_date(i, j) + (dis(MP(i, j), MP(x, y)) - 1) / 2 + 1);
				// cerr << i << ":" << j << " :: " << calc_date(i, j) << " + " << (dis(MP(i, j), MP(x, y)) - 1) / 2 + 1 << endl;
			}
		cout << fans + 1 << endl;
	}

	return 0;
}
/*
...*....
..***...
.*****..
..***...
...*....


...*....
..***...
.*****..
*******.
.*****..
..***...
...*....


*/