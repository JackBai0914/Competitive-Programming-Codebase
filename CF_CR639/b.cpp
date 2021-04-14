#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, m;
bool mp[1010][1010];
int cban[1010], rban[1010];
int col[1010][1010];

int bst = 0;
int cnum[1010][1010], cmn[1010][1010], cmx[1010][1010], rnum[1010][1010], rmn[1010][1010], rmx[1010][1010];

void dfs (int x, int y, int c) {
	// cerr << "dfs : " << x << " " << y << endl;
	cmn[c][y] = min (cmn[c][y], x);
	cmx[c][y] = max (cmx[c][y], x);
	rmn[c][x] = min (rmn[c][x], y);
	rmx[c][x] = max (rmx[c][x], y);
	cnum[c][y] ++;
	rnum[c][x] ++;

	col[x][y] = c;
	if (x != 1 && !col[x - 1][y] && mp[x - 1][y])	dfs (x - 1, y, c);
	if (x != n && !col[x + 1][y] && mp[x + 1][y])	dfs (x + 1, y, c);
	if (y != 1 && !col[x][y - 1] && mp[x][y - 1])	dfs (x, y - 1, c);
	if (y != m && !col[x][y + 1] && mp[x][y + 1])	dfs (x, y + 1, c);
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n >> m;
	char c;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> c;
			mp[i][j] = (c == '#');
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (col[i][j] == 0 && mp[i][j] == 1) {
				bst ++;
				for (int k = 1; k <= n; k ++)
					rmx[bst][k] = 0, rmn[bst][k] = 1e9;
				for (int k = 1; k <= m; k ++)
					cmx[bst][k] = 0, cmn[bst][k] = 1e9;
				dfs (i, j, bst);

				bool fake = false;

				for (int x = 1; x <= n; x ++)
					if (rnum[bst][x]) {
						// cerr << "check " << x << " : " << rnum[bst][x] << " " << rmx[bst][x] << " " <<  rmn[bst][x] << endl;
						fake |= (rnum[bst][x] != rmx[bst][x] - rmn[bst][x] + 1);
						fake |= rban[x];
						rban[x] = 1;
					}
				for (int y = 1; y <= m; y ++)
					if (cnum[bst][y]) {
						// cerr << "check " << y << " : " << cnum[bst][y] << " " << cmx[bst][y] << " " << cmn[bst][y] << endl;
						fake |= (cnum[bst][y] != cmx[bst][y] - cmn[bst][y] + 1);
						fake |= cban[y];
						cban[y] = 1;
					}
				if (fake) {
					cout << -1 << endl;
					return 0;
				}
			}
	bool have_n = false, have_m = false;
	for (int i = 1; i <= n; i ++)
		have_n |= (!rban[i]);
	for (int i = 1; i <= m; i ++)
		have_m |= (!cban[i]);
	if ((have_n == 1 && have_m == 0) ||
		(have_m == 1 && have_n == 0)) {
		cout << -1 << endl;
		return 0;
	}
	cout << bst << endl;
	return 0;
}