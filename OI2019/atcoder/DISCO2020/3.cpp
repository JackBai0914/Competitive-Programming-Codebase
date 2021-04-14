#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
int h, w, k;
char c[330][330];
int ans[330][330], num[330];

int main () {
	ios::sync_with_stdio(false);
	cin >> h >> w >> k;
	int id = 0;
	int first = 1e9;
	for (int i = 1; i <= h; i ++) {
		int st = -1;
		for (int j = 1; j <= w; j ++) {
			cin >> c[i][j];
			if (c[i][j] == '#') {
				id ++, num[i] ++;
				if (st == -1) {
					st = 0;
					for (int l = 1; l < j; l ++)
						ans[i][l] = id;
				}
			}
			// cerr << i << " " << j << " : " << id << endl;
			ans[i][j] = id;
		}
		if (!num[i]) {
			for (int j = 1; j <= w; j ++)
				ans[i][j] = ans[i - 1][j];
		}
		else
			first = min (first, i);
	}
	for (int i = 1; i < first; i ++)
		for (int j = 1; j <= w; j ++)
			ans[i][j] = ans[first][j];
	for (int i = 1; i <= h; i ++) {
		for (int j = 1; j <= w; j ++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}