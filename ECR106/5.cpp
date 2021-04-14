/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-18 15:23:09
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

int n, m;
string x, y;
ll dp[1010][1010][2], longest[1010][2];

int main() {
    ios::sync_with_stdio(false);
    cin >> x >> y;
    n = x.size(), m = y.size();
    for (int i = 0; i < n; i ++) {
    	int j = i;
    	while (j + 1 < n && x[j + 1] != x[j])
    		j ++;
    	longest[i][0] = j;
    }
    for (int i = 0; i < m; i ++) {
    	int j = i;
    	while (j + 1 < m && y[j + 1] != y[j])
    		j ++;
    	longest[i][1] = j;
    }
    ll fans = 0;
    for (int i = n - 1; i >= 0; i --)
    	for (int j = m - 1; j >= 0; j --) {
    		//both > 1
	    	if (i + 1 != n && x[i] != x[i + 1])	(dp[i][j][0] += dp[i + 1][j][0]) %= mod;
	    	if (i + 1 != n && x[i] != y[j])		(dp[i][j][0] += dp[i + 1][j][1]) %= mod;
	    	if (j + 1 != m && y[j] != y[j + 1])	(dp[i][j][1] += dp[i][j + 1][1]) %= mod;
	    	if (j + 1 != m && y[j] != x[i])		(dp[i][j][1] += dp[i][j + 1][0]) %= mod;

    		//x[i] single, y > 1
    		if (j + 1 != m)
	    		if (x[i] != y[j])
		    		(dp[i][j][0] += longest[j][1] - j) %= mod;
    		
    		//y[j] single, x > 1 
    		if (i + 1 != n)
	    		if (x[i] != y[j])
		    		(dp[i][j][1] += longest[i][0] - i) %= mod;

    		//x[i] single, y[j] single
    		if (x[i] != y[j])		dp[i][j][0] ++, dp[i][j][1] ++;

    		(fans += dp[i][j][0] + dp[i][j][1]) %= mod;
    	}
    cout << fans << endl;
    return 0;
}