/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-28 11:35:57
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, r, m;

ld p[55];
int d[55], t[55];

ld dp[55][55][5500], cnt[55][55][5500];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> r >> m;
    t[0] = 0, p[0] = 1.0, d[0] = 0;
    for (int i = 1; i <= m; i ++)
    	cin >> t[i] >> p[i] >> d[i];
    m ++; t[m] = n, p[m] = 1.0, d[m] = 0;

    for (int i = 0; i <= r; i ++)
    	dp[0][0][i] = 0;
    for (int rd = 1; rd <= m; rd ++) {
	    for (int i = 0; i <= r; i ++)
	    	dp[rd][rd][i] = 0.0, cnt[rd][rd][i] = 1.0;
	    for (int i = rd - 1; i >= 0; i --) {
	    	int v = t[i], vn = t[i + 1], gp = vn - v;
    		for (int j = v; j <= r - (t[rd] - v); j ++) {
		    	ld d1, c1, d2, c2;
		    	// cout << " : " << j << " " << (n - i) << " " << d[i] << " " << r << endl;
		    	if (j + t[rd] - v + d[i] <= r) {
			    	d1 = p[i] * (cnt[rd][i+1][j+gp] * gp + dp[rd][i+1][j+gp])
			    	   + (1-p[i]) * (cnt[rd][i+1][j+gp+d[i]] * (gp+d[i]) + dp[rd][i+1][j+gp+d[i]]);
			    	   // cout << ":: " << j+gp+d[i] << " " << (cnt[rd][i+1][j+gp+d[i]]) << " " << (gp+d[i]) << " " << dp[rd][i+1][j+gp+d[i]] << endl;;
			    	c1 = p[i] * cnt[rd][i+1][j+gp] + (1-p[i]) * cnt[rd][i+1][j+gp+d[i]];
			    }
			    else
			    	d1 = oo, c1 = 1;
			    // cout << "c2? " << i << " : " << cnt[rd][i + 1][j + gp] << " " << p[i] << endl;
			    c2 = cnt[rd][i + 1][j + gp] / p[i];
			    d2 = cnt[rd][i + 1][j + gp] * gp + dp[rd][i + 1][j + gp];

			    if (c1 * dp[i][0][r - j] + d1 < c2 * dp[i][0][r - j] + d2)
			    	dp[rd][i][j] = d1, cnt[rd][i][j] = c1;
			    else
			    	dp[rd][i][j] = d2, cnt[rd][i][j] = c2;
			    // cout << "cmp: " << dp[i][0][r - j] << " " << c1 * dp[i][0][r - j] + d1 << " " << c2 * dp[i][0][r - j] + d2 << endl;
		    	// cout << rd << " " << i << " " << j << " : " << dp[rd][i][j] << " " << cnt[rd][i][j] << " (" << d1 << " " << c1 << " " << d2 << " " << c2 << endl;
	    	}
	    }

	    for (int j = r - t[rd] - 1; j >= 0; j --)
	    	dp[rd][0][j] = min (dp[rd][0][j + 1], dp[rd][0][j]);
	}
    cout << dp[m][0][0] << endl;
    return 0;
}