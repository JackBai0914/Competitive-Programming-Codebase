/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 13:22:12
* @description: 
* /Users/jackbai/Desktop/OI/HHKB2020_Atcoder/d.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv d.cpp
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

ll n, a, b;

int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%lld %lld %lld", &n, &a, &b);
		if (b > a)
			swap (a, b);
		ll sumx = (a - b + 1) * (n - a + 1) % MOD;
		// debug(sumx);
		if (n - a <= b - 1)	sumx += (n - a) * (n - a + 1) % MOD;
		else				sumx += (b * (b - 1) / 2 % MOD + (n - a - (b - 1)) * (b - 1) % MOD) * 2 % MOD;
		sumx %= MOD;
		// debug(sumx);
		ll all = (n - a + 1) * (n - a + 1) % MOD * (n - b + 1) % MOD * (n - b + 1) % MOD;
		// debug(all);
		ll ans = (all - sumx * sumx % MOD + MOD + MOD) % MOD;
		printf("%lld\n", ans);
	}
    return 0;
}