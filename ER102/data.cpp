/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-14 16:46:00
* @description: 
* /Users/jackbai/Desktop/ER/data.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv data.cpp
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

map <pii, bool> mp;

int main() {
	int n = 1e5;
	int m = 2e5;
	cout << n << " " << m << endl;
	while (m --) {
		int st, ed;
		do {
			st = rand() % n + 1;
			ed = rand() % n + 1;
		} while (mp[MP(st, ed)]);
		mp[MP(st, ed)] = mp[MP(ed, st)] = true;
		cout << st << " " << ed << " " << rand() % 1e9 << '\n';
	}

    return 0;
}