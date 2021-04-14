/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 13:40:11
* @description: 
* /Users/jackbai/Desktop/OI/HHKB2020_Atcoder/E.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv E.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
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

int n, m, all = 0;
char mp[2020][2020];
int x[2020][2020][2], y[2020][2020][2];
ll kmi[5000000];

int main() {
	scanf("%d %d\n", &n, &m);
	kmi[0] = 1;
	FOR(i, 1, n * m + 1)
		kmi[i] = kmi[i - 1] * 2 % MOD;
	F0R(i, n)
		F0R(j, m) {
			cin >> mp[i][j];
			all += (mp[i][j] == '.');
		}
	F0R(i, n) {
		int pre = -1, suf = m;
		F0R(j, m) {
			if (mp[i][j] == '#')	pre = j;
			else					x[i][j][0] = pre;
		}
		R0F(j, m) {
			if (mp[i][j] == '#')	suf = j;
			else					x[i][j][1] = suf;
		}
	}
	F0R(j, m) {
		int pre = -1, suf = n;
		F0R(i, n) {
			if (mp[i][j] == '#')	pre = i;
			else					y[i][j][0] = pre;
		}
		R0F(i, n) {
			if (mp[i][j] == '#')	suf = i;
			else					y[i][j][1] = suf;
		}
	}

	ll ans = 0;
	F0R(i, n)
		F0R(j, m)
			if (mp[i][j] == '.') {
				int use = (x[i][j][1] - x[i][j][0] - 1) + (y[i][j][1] - y[i][j][0] - 1) - 1;
				(ans += kmi[all - use] * (kmi[use] - 1)) %= MOD;
				// debug(x[i][j][0]);
				// debug(x[i][j][1]);
				// debug(y[i][j][0]);
				// debug(y[i][j][1]);
				// debug(use);
				// debug(ans);
			}
	printf("%lld\n", ans);
    return 0;
}