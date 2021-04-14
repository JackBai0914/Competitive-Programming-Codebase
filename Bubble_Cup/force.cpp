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
int dp[70][8];

int main() {
	ios::sync_with_stdio(false);
	int t;
	freopen("input.in", "r", stdin);
	freopen("outp.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%lld", &m);
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		int i = 0;
		for (; m; i ++, m /= 2) {
			int d = m % 2;
			FOR (ne, 0, 8)
				FOR(ol, 0, 8)
					if ((ne + ol) % 2 == d)
						(dp[i + 1][(ne + ol) / 2] += dp[i][ol]) %= MOD;
		}
		printf("%d\n", dp[i][0]);
	}	


	return 0;
}