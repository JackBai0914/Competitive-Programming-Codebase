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
int mp[10][10];

bool check() {
	
	int cnt = 0;
	for (int i = 1; i < n; i ++)
		for (int j = 1; j < m; j ++) {
			int x[4];
			x[0] = mp[i][j];
			x[1] = mp[i][j + 1];
			x[2] = mp[i + 1][j];
			x[3] = mp[i + 1][j + 1];
			sort(x, x + 4);
			if (x[0] == 1 && x[1] == 2 && x[2] == 3 && x[3] == 4)
				cnt ++;
			else
				return 0;
		}
	return 1;
}

void dfs(int x, int y) {
	if (x > n) {
		if (check ()) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++)
					cout << mp[i][j] << " ";
				cout << endl;
			}
			cout << endl;
		}
		return ;
	}
	if (x <= 2 && y <= 2) {
		dfs(x + (y == m), y % m + 1);
		return ;
	}
	mp[x][y] = 1;	dfs(x + (y == m), y % m + 1);
	mp[x][y] = 2;	dfs(x + (y == m), y % m + 1);
	mp[x][y] = 3;	dfs(x + (y == m), y % m + 1);
	mp[x][y] = 4;	dfs(x + (y == m), y % m + 1);
	
}

int main() {
	ios::sync_with_stdio(false);
	n = 3, m = 6;
	mp[1][1] = 1;
	mp[1][2] = 2;
	mp[2][1] = 3;
	mp[2][2] = 4;
	dfs(1, 1);
	return 0;
}
