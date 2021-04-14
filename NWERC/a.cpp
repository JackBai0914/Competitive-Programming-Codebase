/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-28 09:43:50
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
const ll oo = 1e14;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, q;
ll a[110];
ll dp[100010];

ll bw, bv;
ld r = oo;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
    	cin >> a[i];
    	dp[i] = a[i];
    	if ((ld)a[i] / i < r) {
    		r = (ld)a[i] / i;
    		bw = a[i];
    		bv = i;
    	}
    }
    for (int i = n + 1; i <= 100000; i ++) {
    	dp[i] = oo;
    	for (int j = i - 1; j >= i - n; j --)
    		dp[i] = min (dp[i], dp[j] + a[i - j]);
    }
    // for (int i = 1; i <= 100; i ++)
    // 	cout << i << " : " << dp[i] << endl;
    for (ll x, i = 1; i <= q; i ++) {
    	cin >> x;
    	if (x >= 100000) {
    		ll gp = (x - 100000) / bv + 1;
    		ll preans = gp * bw;
    		cout << dp[x - gp * bv] + preans << '\n';
    	}
    	else {
    		cout << dp[x] << '\n';
    	}
    }
    return 0;
}