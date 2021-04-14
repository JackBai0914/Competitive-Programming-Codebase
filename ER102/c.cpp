/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-14 14:41:12
* @description: 
* /Users/jackbai/Desktop/ER/c.cpp 
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

ll n, k;


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> k;
		ll str = n - (n - k) * 2 - 1;
		ll fold = n - k + 1;
		ll nat = (fold - 1) * fold;
		ll num = nat - (fold - 1);
		// cout << fold << " " << nat << " " << num << endl;
		for (int i = 1; i <= str; i ++)
			cout << i << " ";
		for (int i = fold; i >= 1; i --)
			cout << str + i << " ";
		cout << '\n';
	}
    return 0;
}