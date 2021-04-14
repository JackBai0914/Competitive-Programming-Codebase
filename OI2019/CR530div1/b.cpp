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

int n, m;
string mp[300030];

char ch[4] = {'A', 'C', 'G', 'T'};

int ans = 1000000;
string rec[300030];

string gen[300030];

int exam () {
	int diff = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < m; j ++)
			diff += (gen[i][j] != mp[i][j]);
	if (diff < ans) {
		ans = diff;
		for (int i = 1; i <= n; i ++)
			rec[i] = gen[i];
	}
	return diff;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> mp[i];
		gen[i] = mp[i];
	}
	do {
		for (int i = 1; i <= n; i ++) {
			int x[2];
			if (i % 2)	x[0] = ch[0], x[1] = ch[1];
			else		x[0] = ch[2], x[1] = ch[3];
			int p1 = 0, p2 = 0;
			for (int j = 0; j < m; j ++) {
				p1 += (x[j % 2] != mp[i][j]);
				p2 += (x[(j % 2) ^ 1] != mp[i][j]);
			}
			if (p1 < p2)
				for (int j = 0; j < m; j ++)
					gen[i][j] = x[j % 2];
			else
				for (int j = 0; j < m; j ++)
					gen[i][j] = x[(j % 2) ^ 1];
		}
		exam();
		for (int j = 0; j < m; j ++) {
			int x[2];
			if (j % 2)	x[0] = ch[0], x[1] = ch[1];
			else		x[0] = ch[2], x[1] = ch[3];
			int p1 = 0, p2 = 0;
			for (int i = 1; i <= n; i ++) {
				p1 += (x[i % 2] != mp[i][j]);
				p2 += (x[(i % 2) ^ 1] != mp[i][j]);
			}
			if (p1 < p2)
				for (int i = 1; i <= n; i ++)
					gen[i][j] = x[i % 2];
			else
				for (int i = 1; i <= n; i ++)
					gen[i][j] = x[(i % 2) ^ 1];
		}
		exam();
	} while (next_permutation(ch, ch + 4));

	for (int i = 1; i <= n; i ++)
		cout << rec[i] << '\n';
	cout << endl;
//	cout << ans << endl;
	return 0;
}
