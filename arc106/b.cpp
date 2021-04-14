/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-24 13:05:31
* @description: 
* /Users/jackbai/Desktop/atcoder/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
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

int n, m;
ll a[200020], b[200020], c[200020], d[200020];
ll rt[200020], sum[200020];

int get_r(int x) {return (x == rt[x] ? x : rt[x] = get_r(rt[x]));}

int main() {
	cin >> n >> m;
	FOR(i, 1, n + 1)	rt[i] = i;
	FOR(i, 1, n + 1)	cin >> a[i];
	FOR(i, 1, n + 1)	cin >> b[i];
	F0R(i, m) {
		int st, ed;
		cin >> st >> ed;
		if (get_r(st) != get_r(ed))
			rt[get_r(st)] = ed;
	}

	bool ok = true;
	FOR(i, 1, n + 1)
		sum[get_r(i)] += a[i] - b[i];
	FOR(i, 1, n + 1)
		ok &= (sum[i] == 0);
	cout << (ok ? "Yes" : "No") << endl;
    return 0;
}