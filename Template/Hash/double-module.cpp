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

//START HERE
typedef pair <ll, ll> H;
const H ID = MP(1, 1);
const H ZERO = MP(0, 0);
const H mod = MP(998244353, 1e9 + 21);
const H coef = MP(23, 23);
H operator * (const H &x, const H &y) {return MP(x.F * y.F, x.S * y.S);}
H operator % (const H &x, const H &y) {return MP(x.F % y.F, x.S % y.S);}
H operator + (const H &x, const H &y) {return MP(x.F + y.F, x.S + y.S);}
H operator - (const H &x, const H &y) {return MP(x.F - y.F, x.S - y.S);}
H operator * (const H &x, const ll &y) {return MP(x.F * y, x.S * y);}

// fast power
H kmi (H x, ll t) {
	H ans = ID;
	for(x = x % mod; t; t >>= 1, x = x * x % mod)
		if (t & 1)
			ans = ans * x % mod;
	return ans;
}

// barrel
map <H, int> bar;

// non-general operations
H get (char c) {return MP((c - '0') ^ 1, (c - '0') ^ 1);}

// calculating hash of substrings with specific length k
H rec[1000010];
void deal(string s, int k) {
	H cur = ZERO;
	H fac = kmi (coef, k);
	for (int i = 0; i < s.size(); i ++) {
		rec[i] = (cur * coef + get(s[i])) % mod;
		cur = rec[i];
		if (i == k - 1) {
			cur = (cur % mod + mod) % mod;
			bar[cur] = true;
		}
		else if (i >= k) {
			H c = (cur - rec[i - k]) * fac % mod;
			c = (c % mod + mod) % mod;
			bar[c] = true;
		}
	}
}

// calculating hash of the entire string
H calc (string s) {
	H cur = MP(0, 0);
	for (int i = 0; i < s.size(); i ++)
		cur = (cur * coef + get(s[i])) % mod;
	return cur;
}


int main() {
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s) {
		cout << calc(s).F << " " << calc(s).S << endl;
		deal(s, 10);
	}
    return 0;
}