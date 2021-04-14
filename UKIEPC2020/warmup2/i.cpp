/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-11 10:44:17
* @description: 
* /Users/jackbai/Desktop/OI/UKIEPC2020/warmup2/i.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv i.cpp
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
typedef pair <ld, ld> pll;

int c;
pii p[100010];

pll h[100010], s[100010];
int hst = 0, sst = 0;

ld cross (const pll &a, const pll &b) {
	return a.F * b.S - a.S * b.F;
}
pll operator - (const pll &a, const pll &b) {
	return MP(a.F - b.F, a.S - b.S);
}

ld len (const pll &x) {
	return hypot(x.F, x.S);
}

ld dist (pll a, pll b) {
	return len(a-b);
}

int main() {
	cout << fixed << setprecision(10);
	cin >> c;
	for (int i = 1; i <= c; i ++)
		cin >> p[i].F >> p[i].S;
	sort(p + 1, p + c + 1);

	for (int i = 1; i <= c; i ++) {
		while (sst > 1 && cross(p[i] - s[sst - 1], s[sst] - s[sst - 1]) < eps)
			sst --;
		s[++ sst] = p[i];
	}
	for (int i = 1; i <= sst; i ++)
		h[++ hst] = s[i];

	sst = 0;
	for (int i = c; i >= 1; i --) {
		while (sst > 1 && cross(p[i] - s[sst - 1], s[sst] - s[sst - 1]) < eps)
			sst --;
		s[++ sst] = p[i];
	}
	
	for (int i = 2; i < sst; i ++)
		h[++ hst] = s[i];

	for (int i = 1; i <= hst; i ++)
		h[hst + i] = h[i];
	hst <<= 1;

	ld fans = 0;

	int pt = 1;
	for (int i = 1; i <= hst / 2; i ++) {
		while (dist(h[pt + 1], h[i]) > dist(h[pt], h[i]))
			pt ++;
		fans = max (fans, dist(h[pt], h[i]));
	}
	cout << fans << endl;
    return 0;
}