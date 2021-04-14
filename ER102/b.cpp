/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-14 14:41:17
* @description: 
* /Users/jackbai/Desktop/ER/b.cpp 
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

string a, b;

string repeat (string x, int t) {
	string ans = "";
	while (t --)
		ans = ans + x;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> a >> b;
		int len = 1000000;
		string t;
		for (int i = 1; i <= b.size(); i ++) {
			string c = repeat(a, i);
			if (c.size() % b.size() != 0)
				continue ;
			string bc = repeat(b, c.size() / b.size());
			if (c != bc)
				continue ;
			if (c.size() < len) {
				len = c.size();
				t = c;
			}
		}
		if (len == 1000000)
			cout << -1 << '\n';
		else
			cout << t << '\n';
	}

    return 0;
}