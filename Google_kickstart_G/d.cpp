/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 13:58:38
* @description: 
* /Users/jackbai/Desktop/OI/Google_kickstart_G/d.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv d.cpp
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

int n;
ld a[5050];
ld dp[5050][5050];

int main() {
	cout << fixed << setprecision(20);
	cerr << fixed << setprecision(20);
	int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt ++) {
        ld ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++)
        	cin >> a[i];
        dp[2][1] = 1;
        dp[2][2] = 1;

        for (int i = 3; i <= n; i ++) {
        	int all_choice = i - 1;
        	for (int j = 1; j <= i; j ++) {
        		dp[i][j] = 0;
        		int cnt = 0;
        		if (j != 1)	dp[i][j] += (1 + dp[i - 1][j - 1]) / all_choice;
        		if (j != i)	dp[i][j] += (1 + dp[i - 1][j]) / all_choice;
        		if (j > 2)	dp[i][j] += dp[i - 1][j - 1] * (j - 2) / all_choice;
	        	if (j < i - 1)	dp[i][j] += dp[i - 1][j] * (i - 1 - j) / all_choice;
	        	// cerr << "dp " << " " << i << " " << j << " " << dp[i][j] << endl;
        	}
        }
        for (int i = 1; i <= n; i ++)
        	ans += dp[n][i] * a[i];

        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}