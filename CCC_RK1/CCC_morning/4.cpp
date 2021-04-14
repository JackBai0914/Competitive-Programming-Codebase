/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-30 08:57:38
* @description: 
* /Users/jackbai/Desktop/CCC/1.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 1.cpp
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

int n, m, p;
const int K = 32;
pii rk[1000010];

int rt[1000010];
int sum[1000010];

int main() {
	cin >> n >> m >> p;
	for (int i = 0; i < m; i ++) {
		rk[i].F = 1000;
		rk[i].S = -i;
	}


	for (int i = 1; i <= n; i ++) {
		int a, b;
		int s1 = 0, s2 = 0, r1 = 0, r2 = 0;
		vector <pii> v1, v2;
		for (int j = 1; j <= p; j ++) {
			cin >> a >> b;
			s1 += b;
			r1 += rk[a].F;
			v1.push_back(MP(a, b));
		}

		for (int j = 1; j <= p; j ++) {
			cin >> a >> b;
			s2 += b;
			r2 += rk[a].F;
			v2.push_back(MP(a, b));
		}

		for (int j = 0; j < p; j ++) {
			int pid = v1[j];
			int ra = rk[pid].F, rc = r2 - r1 + ra;
			ld Ea = 1 / (1 + pow(10, (rc - ra) / 400.0));
			rk[pid].F = ra + K * ((s1 > s2) - Ea);
		}

		for (int j = 0; j < p; j ++) {
			int pid = v2[j];
			int ra = rk[pid].F, rc = r1 - r2 + ra;
			ld Ea = 1 / (1 + pow(10, (rc - ra) / 400.0));
			rk[pid].F = ra + K * ((s2 > s1) - Ea);
		}
	}

	sort (rk, rk + m);
	for (int i = m - 1; i >= 0; i --)
		cout << -rk[i].S << " " << rk[i].F << endl;
    return 0;
}