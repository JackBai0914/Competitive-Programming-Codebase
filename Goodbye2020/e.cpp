/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-30 13:55:02
* @description: 
* /Users/jackbai/Desktop/Goodbye2020/e.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv e.cpp
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
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
ll x[1000010];
ll num[66], s1[1000010], s2[1000010];
ll mi2[66];

ll c[220];

int main() {
	for (int i = 0; i <= 60; i ++)
		mi2[i] = (1ll << i);

	c[0] = 1;
	for (int i = 1; i < 200; i ++)
		c[i] = c[i - 1] * 2 % mod;

	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		memset(num, 0, sizeof num);

		for (int i = 1; i <= n; i ++) {
			scanf("%lld", &x[i]);
			for (int j = 0; j < 60; j ++)
				if (x[i] & mi2[j])
					num[j] ++;
			s1[i] = s2[i] = 0;
		}

		ll ans = 0;

		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < 60; j ++) {
				if (x[i] & mi2[j]) {
					(s1[i] += c[j] * num[j]) %= mod;
					(s2[i] += c[j] * n) %= mod;
				}
				else {
					(s2[i] += c[j] * num[j]) %= mod;
				}
			}
			(ans += s1[i] * s2[i]) %= mod;
		}

		((ans %= mod) += mod) %= mod;

		printf("%lld\n", ans);
	}

    return 0;
}