/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-16 12:13:04
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
const int mod = 998244353; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int h, w, k;
int mp[5050][5050];
ll dp[5050][5050];

ll kmi (ll x, ll t) {
	ll ans = 1;
	for (x %= mod; t; t >>= 1, x = x * x % mod)
		if (t & 1)
			ans = ans * x % mod;
	return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> h >> w >> k;
    for (int a, b, i = 1; i <= k; i ++) {
    	char c;
    	cin >> a >> b >> c;
    	if (c == 'X')	mp[a][b] = 1;
    	if (c == 'D')	mp[a][b] = 2;
    	if (c == 'R')	mp[a][b] = 3;
    }
    dp[1][1] = 1;
    ll inv3 = kmi (3, mod - 2);

    for (int i = 1; i <= h; i ++)
    	for (int j = 1; j <= w; j ++) {
    		// cerr << ": " << i << " " << j << " " << dp[i][j] << " " << mp[i][j] << endl;
    		if (!mp[i][j]) {
    			(dp[i][j + 1] += 2 * dp[i][j] % mod * inv3) %= mod;
    			(dp[i + 1][j] += 2 * dp[i][j] % mod * inv3) %= mod;
    		}
    		else {
    			if (mp[i][j] == 1)	(dp[i][j + 1] += dp[i][j]) %= mod, (dp[i + 1][j] += dp[i][j]) %= mod;
    			if (mp[i][j] == 2)	(dp[i + 1][j] += dp[i][j]) %= mod;
    			if (mp[i][j] == 3)	(dp[i][j + 1] += dp[i][j]) %= mod;
    		}
    	}

    ll ans = dp[h][w] % mod;

    int rem = h * w - k;
    ans = ans * kmi (3, rem) % mod;

    cout << ans << endl;
    return 0;
}