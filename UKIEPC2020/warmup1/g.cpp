/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-10 16:19:00
* @description: 
* /Users/jackbai/Desktop/UKIEPC2016/g.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv g.cpp
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

long double a, b, c, d, e, ans = 0;

int main() {
	cout << fixed << setprecision(10);
	cin >> a >> b;
	for (int i = 0; i < b; i ++) {
		cin >> c >> d;
		ans += a * c * d;
	}
	cout << ans << endl;
    return 0;
}