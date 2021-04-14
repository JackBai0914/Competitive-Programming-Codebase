#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const int oo = 1e9;
int n, k;
int a[300030], s[300030];
int dp[300030];

int q[300030], st = 0, ed = 1;

int main() {
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		char c;
		cin >> c;
		a[i] = (c == 'H' ? 1 : -1);
		s[i] = s[i - 1] + a[i];
	}

	q[++ st] = 0;

	for (int i = 1; i <= n; i ++) {
		while (ed != st + 1 && q[ed] < i - k)
			ed ++;
		dp[i] = dp[q[ed]] + (s[i] - s[q[ed]] <= 0);
		while (ed != st + 1 && dp[q[st]] > dp[i])
			st --;
		while (ed != st + 1 && dp[q[st]] == dp[i]) {
			if (s[i] - s[q[st]] > 0)	break;
			else						st --;
		}
		q[++ st] = i;
	}
	cout << dp[n] << endl;
	return 0;
}