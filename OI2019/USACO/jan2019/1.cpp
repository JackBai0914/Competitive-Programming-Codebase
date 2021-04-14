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
const int mx = 300001;
int sum[mx], dp[mx], n, k;
int stk[mx];

int main() {
	freopen("redistricting.in", "r", stdin);
	freopen("redistricting.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		char c;
		cin >> c;
		if (c == 'H')	sum[i] = sum[i - 1] + 1;
		else			sum[i] = sum[i - 1] - 1;
	}

	int st = 0, ed = 1;
	dp[0] = 0;
	stk[++ st] = 0;
	for (int i = 1; i <= n; i ++) {
		while (ed <= st && stk[ed] < i - k)
			ed ++;
		dp[i] = dp[stk[ed]] + (sum[i] - sum[stk[ed]] <= 0);
		while (ed <= st && dp[stk[st]] > dp[i])
			st --;
		while (ed <= st && dp[stk[st]] == dp[i]) {
			if (sum[i] - sum[stk[st]] > 0)	break;
			else							st --;
		}
		stk[++ st] = i;
	}
	cout << dp[n] << endl;
	return 0;
}