/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-17 15:33:12
* @description: 
* /Users/jackbai/Desktop/cf/f.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv f.cpp
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

void input() {
	ll ans = 0;
	cerr << fixed << setprecision(10) << log2(32-16) << endl;
	int l;
	int c;
	string inp;
	cin >> l >> inp;
	for (int i = 0; i < inp.size(); i ++)
		for (int j = i; j < inp.size(); j ++) {
			int prev = 0, mx = 0;
			for (int k = i; k <= j; k ++) {
				c = inp[k] - '0';
				if (c == 0)
					prev = 0;
				if (c == 1) {
					prev ++;
					mx = max (mx, prev);
				}
			}
			ans += mx;
		}
	cout << ans << endl;
}

int main() {
	input();
    return 0;
}