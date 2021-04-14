/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-30 13:55:08
* @description: 
* /Users/jackbai/Desktop/Goodbye2020/c.cpp 
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

string s;
int v[1000010];

int main() {
	int t;
	cin >> t;
	while (t --) {
		int ans = 0;
		cin >> s;
		for (int i = 0; i < s.size(); i ++)
			v[i] = s[i];
		for (int i = 1; i < s.size(); i ++) {
			if (v[i] == v[i - 1] || (i >= 2 && v[i] == v[i - 2])) {
				ans ++;
				v[i] = 200 + ans;
			}
		}
		cout << ans << endl;
	}
    return 0;
}