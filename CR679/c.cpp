/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-25 11:44:14
* @description: 
* /Users/jackbai/Desktop/CR679/c.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv c.cpp
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

ll a, b, c, d;
ll rd, gain;

ll calc(ll st, ll ed, ll num) {
	return (st + ed) * num / 2;
}

int main() {
	int t;
	scanf ("%d", &t);
	while (t --) {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a > b * c) {
			printf("-1\n");
			continue ;
		}
		rd = a / b / d;	//rd * d * b <= a
		gain = a + a * rd - calc(b * d, rd * b * d, rd);
		printf("%lld\n", gain);
	}	

    return 0;
}