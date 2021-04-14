/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 16:19:53
* @description: 
* /Users/jackbai/Desktop/OI/CGR_Codeforces/c.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv c.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int r, n;
int t[1000010], x[1000010], y[1000010];
int dp[1000010];

int main() {
	memset(dp, -1, sizeof dp);
	int ans = 0;
	scanf("%d %d", &r, &n);
	t[0] = 0, x[0] = 1, y[0] = 1, dp[0] = 0;

	int mx = -1;
	FOR(i, 1, n + 1) {
		if (i >= r + r) {
			mx = max(mx, dp[i - r - r]);
			dp[i] = mx + 1;
		}
		scanf("%d %d %d", &t[i], &x[i], &y[i]);

		FOR(j, max(0, i - (r + r + 1)), i) 
			if (dp[j] != -1) {
				if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
					dp[i] = max (dp[i], dp[j] + 1);
		}
		ans = max (ans, dp[i]);
	}
	printf("%d\n", ans);
    return 0;
}