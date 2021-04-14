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
using namespace std;
typedef long long ll;
typedef long double ld;

int a, b, c, d;
int ans = 0;

int score (int x) {
	if (x < 60)	return 0;
	if (x < 62)	return 10;
	if (x < 65)	return 17;
	if (x < 67)	return 20;
	if (x < 70)	return 23;
	if (x < 75)	return 27;
	if (x < 80)	return 30;
	if (x < 85)	return 33;
	if (x < 90)	return 37;
	if (x < 95)	return 40;
	else		return 43;
}

void dfs (int l, int s, int v) {
	if (s < 0)
		return ;
	if (l == 5) {
		ans = max (ans, v);
		return ;
	}
	dfs (l + 1, s, v);
	dfs (l + 1, s - 60, v + score(60));
	dfs (l + 1, s - 62, v + score(62));
	dfs (l + 1, s - 65, v + score(65));
	dfs (l + 1, s - 67, v + score(67));
	dfs (l + 1, s - 70, v + score(70));
	dfs (l + 1, s - 75, v + score(75));
	dfs (l + 1, s - 80, v + score(80));
	dfs (l + 1, s - 85, v + score(85));
	dfs (l + 1, s - 90, v + score(90));
	dfs (l + 1, s - 95, v + score(95));
}



int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		ans = 0;
		int n;
		cin >> n;
		dfs (1, n, 0);
		cout << ans/10 << '.' << ans%10 << endl;
	}

	return 0;
}