/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-24 13:00:20
* @description: 
* /Users/jackbai/Desktop/atcoder/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
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

ll n, p3[110], p5[110];

int main() {
	scanf ("%lld", &n);
	
	ll v3 = 1;
	F0R(i, 100) {
		p3[i] = v3;
		if (1e18 / v3 / 3 < 1)
			continue ;
		v3 *= 3;
	}
	ll v5 = 1;
	F0R(i, 100) {
		p5[i] = v5;
		if (1e18 / v5 / 5 < 1)
			continue ;
		v5 *= 5;
	}

	FOR(i, 1, 100)
		FOR(j, 1, 100)
			if (n - p3[i] == p5[j]) {
				printf("%d %d\n", i, j);
				return 0;
			}
	printf("-1\n");
    return 0;
}