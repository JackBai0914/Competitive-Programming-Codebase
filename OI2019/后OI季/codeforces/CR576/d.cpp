#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include <set>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;

typedef long long ll;
int n;
int mp[55][55];
int sum[55][55], s[2][55][55];

int rec[55][55][55][55];

int dfs (int stx, int sty, int edx, int edy) {
	if (edx < stx || edy < sty)
		return 0;
	if (~rec[stx][sty][edx][edy])
		return rec[stx][sty][edx][edy];

	if (sum[edx][edy] - sum[stx - 1][edy] - sum[edx][sty - 1] + sum[stx - 1][sty - 1] == 0) {
		rec[stx][sty][edx][edy] = 0;
		return 0;
	}
	rec[stx][sty][edx][edy] = max (edx - stx + 1, edy - sty + 1);
	for (int x = stx; x <= edx; x ++) {
		if (s[0][x][edy] - s[0][x][sty - 1] != 0)
			continue ;
		rec[stx][sty][edx][edy] = min (rec[stx][sty][edx][edy], 
			dfs (stx, sty, x - 1, edy) + dfs (x + 1, sty, edx, edy));
		if (dfs (stx, sty, x - 1, edy) >= rec[stx][sty][edx][edy])
			break;
	}
	for (int y = sty; y <= edy; y ++) {
		if (s[1][edx][y] - s[1][stx - 1][y] != 0)
			continue ;
		rec[stx][sty][edx][edy] = min (rec[stx][sty][edx][edy], 
			dfs (stx, sty, edx, y - 1) + dfs (stx, y + 1, edx, edy));
		if (dfs (stx, sty, edx, y - 1) >= rec[stx][sty][edx][edy])
			break;
	}
	return rec[stx][sty][edx][edy];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			char c;
			cin >> c;
			mp[i][j] = (c == '#' ? 1 : 0);
			sum[i][j] = mp[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
			s[0][i][j] = s[0][i][j - 1] + mp[i][j];
			s[1][i][j] = s[1][i - 1][j] + mp[i][j];
		}

	memset(rec, -1, sizeof rec);
	cout << dfs (1, 1, n, n) << endl;
	// cerr << TIME << endl;
	return 0;
}