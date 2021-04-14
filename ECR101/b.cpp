/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-28 14:31:34
* @description: 
* /Users/jackbai/Desktop/ECR101/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
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

int n, m;
int a[110], b[110];
int sa[110], sb[110];

int dp[110][110];

int main() {
	int t;
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			sa[i] = sa[i - 1] + a[i];
		}
		cin >> m;
		for (int i = 1; i <= m; i ++) {
			cin >> b[i];
			sb[i] = sb[i - 1] + b[i];
		}
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= m; j ++)
				dp[i][j] = -1e9;
		dp[0][0] = 0;
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= m; j ++) {
				if (i != n) dp[i + 1][j] = max(dp[i + 1][j], max (dp[i][j], sa[i + 1] + sb[j]));
				if (j != m) dp[i][j + 1] = max(dp[i][j + 1], max (dp[i][j], sa[i] + sb[j + 1]));
			}
		cout << dp[n][m] << endl;
	}

    return 0;
}