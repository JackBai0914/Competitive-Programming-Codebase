/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 14:20:06
* @description: 
* /Users/jackbai/Desktop/OI/HHKB2020_Atcoder/F.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv F.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
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


ll fac[1000010], ifac[1000010], inv[1000010];
ll kmi (ll x, ll t) {
	ll ans = 1;
	for (x %= MOD; t; x = x * x % MOD, t /= 2)
		if (t & 1)
			ans = ans * x % MOD;
	return ans;
}
void init () {
	fac[0] = ifac[0] = i[0] = 1;
	FOR(i, 1, 1000000)
		fac[i] = fac[i - 1] * i % MOD;
	ifac[999999] = kmi (fac[999999], MOD - 2);
	ROF(i, 999999, 1)
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;	
	FOR(i, 1, 1000000)
		inv[i] = ifac[i] * fac[i - 1] & mod;
	debug(inv[233] * 233 % mod);
}

ll C (int n, int m) {
	if (n < m)
		return 0;
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int n;
pii seg[1010];
vector <int> pt;

int main() {
	cin >> n;
	F0R(i, n) {
		cin >> seg[i].F >> seg[i].S;
		pt.push_back(seg[i].F);
		pt.push_back(seg[i].S);
	}
	sort(pt.begin(), pt.end());

	FOR(i, 1, pt.size()) {
		int st = pt[i - 1], ed = pt[i];
		if (ed - st == 0)
			continue ;
		int cnt = 0;
		F0R(j, n) {

		}
	}


    return 0;
}