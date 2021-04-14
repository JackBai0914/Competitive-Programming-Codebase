/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-17 15:07:06
* @description: 
* /Users/jackbai/Desktop/cf/e.cpp 
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

int n, k;
ll a[1000010], ct[1000010];

ll sqr (ll x) {return x*x;}
ll val (ll v, ll k) {
	ll l = v / k, r = v - l * k;
	return sqr(l+1)*r + sqr(l)*(k-r);
}

priority_queue <pair<ll, int> > q;


int main() {
	cin >> n >> k;
	ll ans = 0;
	F0R(i, n) {
		cin >> a[i];
		ct[i] = 1;
		if (a[i] != ct[i])
			q.push(MP(val(a[i], ct[i]) - val(a[i], ct[i] + 1), i));
		ans += val(a[i], ct[i]);
	}

	F0R(i, k - n) {
		pair <ll, int> c = q.top();
		int x = c.S;
		q.pop();
		ans -= c.F;
		ct[x] ++;
		if (a[x] != ct[x])
			q.push(MP(val(a[x], ct[x]) - val(a[x], ct[x] + 1), x));
	}
	cout << ans << endl;
    return 0;
}