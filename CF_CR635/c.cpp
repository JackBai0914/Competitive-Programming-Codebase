#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
const int mod = 998244353;
string s, t;
int n, m;
ll dp[3030][3030];

int main() {
	ios::sync_with_stdio(false);
	cin >> s >> t;
	n = s.size(), m = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = m + 1; i <= n; i ++)
		t += '*';

	for (int i = 1; i <= n; i ++)
		if (s[1] == t[i] || t[i] == '*')
			dp[i][i] = 2;
	for (int gap = 1; gap < n; gap ++)
		for (int i = 1, j = i + gap; j <= n; i ++, j ++) {
			char c = s[gap + 1];
			if (c == t[i] || t[i] == '*')
				(dp[i][j] += dp[i + 1][j]) %= mod;
			if (c == t[j] || t[j] == '*')
				(dp[i][j] += dp[i][j - 1]) %= mod;
		}
	ll fans = 0;
	for (int j = m; j <= n; j ++)
		(fans += dp[1][j]) %= mod;
	cout << fans << endl;
	return 0;
}
