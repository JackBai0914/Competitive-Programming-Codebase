/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-28 15:30:52
* @description: 
* /Users/jackbai/Desktop/ECR101/e.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv e.cpp
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

typedef unsigned long long ull;
typedef pair <ll, ll> H;

int t = 0;

const ll mod1 = 998244353;
const ll mod2 = 1e9 + 21;
H kmi (H x, ll t) {
	H ans = MP(1ull, 1ull);
	for(x.F %= mod1, x.S %= mod2; t; t >>= 1, x.F = x.F * x.F % mod1, x.S = x.S * x.S % mod2)
		if (t & 1)
			(ans.F *= x.F) %= mod1, (ans.S *= x.S) %= mod2;
	return ans;
}
map <H, int> bar;

int get (char c) {return (c - '0') ^ 1;}

H rec[1000010];
void deal(string s, int k) {
	H cur = MP(0, 0);
	H fac = kmi (MP(23, 23), k);
	// cerr << ":" << fac.F << " " << fac.S << endl;
	for (int i = 0; i < s.size(); i ++) {
		rec[i] = MP((cur.F * 23 + get(s[i])) % mod1, (cur.S * 23 + get(s[i])) % mod2);
		cur = rec[i];
		// cerr << get(s[i]) << " " << "---" << cur.F << " " << cur.S << endl;
		if (i == k - 1) {
			((cur.F %= mod1) += mod1) %= mod1;
			((cur.S %= mod2) += mod2) %= mod2;
			// cout << cur.F << " " << cur.S << endl;
			bar[cur] = t;
		}
		else if (i >= k) {
			H c = MP(cur.F - rec[i - k].F * fac.F % mod1, cur.S - rec[i - k].S * fac.S % mod2);
			((c.F %= mod1) += mod1) %= mod1;
			((c.S %= mod2) += mod2) %= mod2;
			bar[c] = t;
			// cout << c.F << " " << c.S << endl;
		}
		else {
			// cerr << "pre: " << cur.F << " " << cur.S << endl;
		}

	}
}

H calc (string s) {
	H cur = MP(0, 0);
	for (int i = 0; i < s.size(); i ++)
		cur = MP((cur.F * 23 + get(s[i])) % mod1, (cur.S * 23 + get(s[i])) % mod2);
	return cur;
}

string cur;
H rc;
H f[30];
bool move () {
	int pt = cur.size() - 1;

	while (pt >= 0 && cur[pt] == '0') {
		cur[pt] = '1'; 
		rc = MP((rc.F - f[cur.size() - pt - 1].F) % mod1, (rc.S - f[cur.size() - pt - 1].S) % mod2);
		pt --;
	}
	if (pt == -1)
		return false;
	cur[pt] = '0';
	rc = MP((rc.F + f[cur.size() - pt - 1].F) % mod1, (rc.S + f[cur.size() - pt - 1].S) % mod2);
	((rc.F %= mod1) += mod1) %= mod1;
	((rc.S %= mod2) += mod2) %= mod2;
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	for (int i = 0; i <= 20; i ++) {
		f[i] = kmi (MP(23, 23), i);
		// cerr << i << " : " << f[i].F << " " << f[i].S << endl;
	}
	int T = 1;
	cin >> T;
	for (t = 1; t <= T; t++) {
		string s = "";	int n = 1000000, k = 200;
		cin >> n >> k;
		cin >> s;
		deal(s, k);
		cur = "";
		if (k <= 20) {
			for (int i = 0; i < k; i ++)
				cur += '1';
			rc = calc(cur);
			// cerr << "init: " << rc.F << " " << rc.S << endl;
			bool fin = false;
			while (bar[rc] == t) {
				if (!move()) {
					fin = true;
					break;
				}
			} 
			if (bar[rc] != t) {
				cout << "YES" << '\n';
				// cerr << " : " << rc.F << " " << rc.S << " " << calc(cur).F << " " << calc(cur).S << endl;
				for (int i = 0; i < cur.size(); i ++)
					cout << (cur[i] == '0' ? '1' : '0');
				cout << '\n';
				continue ;
			}
			else {
				cout << "NO" << '\n';
				continue ;
			}
		}
		else {
			for (int i = 0; i < 20; i ++)
				cur += '1';
			rc = calc(cur);
			bool fin = false;
			while (bar[rc] == t) {
				if (!move()) {
					fin = true;
					break;
				}
			}
			// cerr << "st output " << TIME << " " << cur.size() << endl;
			cout << "YES" << '\n';
			for (int i = 0; i < k - 20; i ++)
				cout << '0';
			for (int i = 0; i < cur.size(); i ++)
					cout << (cur[i] == '0' ? '1' : '0');
			cout << '\n';
			cerr << "ed output " << TIME << endl;

		}
	}

    return 0;
}