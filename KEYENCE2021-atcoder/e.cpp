/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-16 13:14:46
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

int n;
int a[500], b[500];

int dp[402][1002];
int hp[402][1002];

int ans[500];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	b[n - i + 1] = a[i];
    }

    memset(dp, -1, sizeof dp);
    memset(hp, -1, sizeof hp);

    dp[0][0] = 0;
   	for (int i = 0; i <= n; i ++) {
   		for (int j = 0; j <= n; j ++) {
   			for (int k = 0; k <= i + j; k ++) {
   				//select jth
   				if (j && k && dp[j - 1][k - 1] != -1)
	   				dp[j][k] = max (dp[j - 1][k - 1] + b[j], dp[j][k]);
	   			//not select jth
	   			if (j && dp[j - 1][k + 1] != -1)
	   				dp[j][k] = max (dp[j - 1][k + 1], dp[j][k]);
	   			if (j && !k && dp[j - 1][k] != -1)
	   				dp[j][k] = max (dp[j - 1][k], dp[j][k]);
	   			// if (j && dp[j - 1][k] != -1)
	   			// 	dp[j][k] = max (dp[j - 1][k], dp[j][k]);

	   			//select ith
	   			if (i && k && hp[j][k - 1] != -1)
	   				dp[j][k] = max (hp[j][k - 1] + a[i], dp[j][k]);
	   			//not select ith
	   			if (i && hp[j][k + 1] != -1)
	   				dp[j][k] = max (hp[j][k + 1], dp[j][k]);
	   			if (i && !k && hp[j][k] != -1)
	   				dp[j][k] = max (hp[j][k], dp[j][k]);
	   			cerr << "dp " << i << " " << j << " " << k << " " << dp[j][k] << endl;
   			}
   		}
   		ans[i] = max (dp[n - i][0], dp[n - i][1]);
   		cout << ans[i] << endl;
   		for (int j = 0; j <= n; j ++)
   			for (int k = 0; k <= i + j; k ++)
   				hp[j][k] = dp[j][k], dp[j][k] = -1;
   }

    return 0;
}