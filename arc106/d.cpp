/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-24 13:42:05
* @description: 
* /Users/jackbai/Desktop/atcoder/d.cpp 
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
const int MOD = 998244353; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, k;
l, a[200020], s[200020][2]. hp[200020][2];
ll ans[330];

ll div2(ll x) {
	return (x % 2 ? (x + MOD) / 2 : x / 2);
}

void calc(int x) {
	ans[x] = 0;
	FOR(i, 1, n + 1)
		(ans += s[i][1]) %= MOD;
	ans[x] = div2(ans[x]);
	FOR(i, 1, n + 1)
		(ans[x] += s[i][0]) %= MOD;
}

int main() {
	cin >> n >> k;
	FOR(i, 1, n + 1)
		cin >> a[i];
	//k == 1
	FOR(i, 1, n + 1) {
		s[i][0] = (n - 1) * a[i] % MOD;
		s[i][1] = 0;
	}
	calc(1);

	FOR(t, 2, k + 1) {
		FOR(i, 1, n + 1) {
			hp[i][0] = s[i][0], s[i][0] = 0;
			hp[i][1] = s[i][1], s[i][1] = 0;
		}
		FOR(i, 1, n + 1) {
			(s[i][0] += hp[i][0] * a[i]) %= MOD;
			(s[i][1] += hp[i][0] * a[i]) %= MOD;
			(s[i][1] += hp[i][0] * a[i]) %= MOD;
			(s[i][1] += hp[])
		}
	}

    return 0;
}