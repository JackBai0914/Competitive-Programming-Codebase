#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int mod = 1e9 + 7;
const int V = 1e9;
typedef long long ll;
int n, k, cnt = 0;
int v[100010];

int c[100010];

void dfs(int x) {
	if (x == n + 1) {
		for (int i = 1; i <= n - k + 1; i ++) {
			int mn = 1e9;
			for (int j = 0; j < k; j ++)
				mn = min(mn, c[i + j]);
			if (mn != v[i])
				return ;
		}
		cnt ++;
		return ;
	}
	for (int i = 999999995; i <= 1000000000; i ++) {
		c[x] = i;
		dfs(x + 1);
		c[x] = 0;
	}
}

int main() {
	freopen("tracking2.in", "r", stdin);
	freopen("force.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n - k + 1; i ++)
		cin >> v[i];
	dfs(1);
	// cerr << cnt << endl;
	cout << cnt << endl;
	return 0;
}