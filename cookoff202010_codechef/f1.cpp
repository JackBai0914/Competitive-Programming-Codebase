/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 18:15:50
* @description: 
* /Users/jackbai/Desktop/OI/cookoff202010_codechef/f.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv f.cpp
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

int dp[300030];

pii de(int x) {
	for (int i = sqrt(x)+eps; i >= 1; i --)
		if (x % i == 0)
			return MP(i, x / i);
	return MP(1, x);
}

int main() {
	ld mx = 0;
	dp[1] = 2;
	for (int i = 2; i <= 300000; i ++) {
		pii ini = de(i);
		dp[i] = ini.F + ini.S;
		for (int j = 1; j < i; j ++)
			dp[i] = min (dp[i], dp[j] + dp[i - j]);
		cout << i << " : " << dp[i] << endl;
		mx = max (mx, (ld)dp[i] - sqrt(i)*2);
	}
	// cout << mx << endl;


    return 0;
}