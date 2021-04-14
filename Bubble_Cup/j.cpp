/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @date: 2020-10-05 21:18:39
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv a.cpp -o a 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define TIME (double)clock()/CLOCKS_PER_SEC


//loops
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

//debug
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

//constants
const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e18;

ll m;
ll dp[70][3];

int fac[4] = {1, 1, 2, 6};

int main() {
	ios::sync_with_stdio(false);
	// freopen("input.in", "r", stdin);
	// freopen("outp2.out", "w", stdout);
	int t;
	scanf("%d", &t);
	cerr << TIME << endl;
	while (t --) {
		scanf("%lld", &m);
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		//0th
		int d0 = m % 2; m /= 2;
		dp[1][0] = 1, dp[1][1] = 0, dp[1][2] = 0;

		//1th
		int d1 = m % 2; m /= 2;
		dp[2][0] = (d1 ? 2 : 1), dp[2][1] = (d1 ? 0 : 1);
		// cout << "1:: " << dp[2][0] << " " << dp[2][1] << " " << dp[2][2] << endl;
		int i = 2;
		for (; m; i ++, m >>= 1) {
			int d = (m & 1);
			if (d == 0) {
				//0, 2, 4
				dp[i + 1][0] = dp[i][0];
				dp[i + 1][1] = dp[i][0] * 3 + dp[i][1] * 3 + dp[i][2];
				dp[i + 1][2] = dp[i][1] + dp[i][2] * 3;
			}
			else {
				//1, 3, 5
				dp[i + 1][0] = dp[i][0] * 3 + dp[i][1];
				dp[i + 1][1] = dp[i][0] * 1 + dp[i][1] * 3 + dp[i][2] * 3;
				dp[i + 1][2] = dp[i][2];
			}
			dp[i + 1][0] %= MOD;
			dp[i + 1][1] %= MOD;
			dp[i + 1][2] %= MOD;
			// cout << i << " : " << d << " " << dp[i + 1][0] << " " << dp[i + 1][1] << " " << dp[i + 1][2] << endl;
		}
		printf("%d\n", (int)dp[i][0] % MOD);
	}
	cerr << TIME << endl;



	return 0;
}