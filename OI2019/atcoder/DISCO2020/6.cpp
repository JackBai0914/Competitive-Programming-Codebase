#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll h, w, t;

ll hl, wl;
ll hn, wn;

ll gcd (ll a, ll b) {if (b == 0) return a; return gcd (b, a % b);}
ll kmi (ll x, ll t) {
	ll ans = 1;
	// cerr << "kmi : " << x << " " << t << endl;
	for (x %= mod; t; t = t / 2, x = x * x % mod)
		if (t % 2 == 1)
			ans = ans * x % mod;
	// cerr << "res : " << ans << endl;
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin >> h >> w >> t;
	hn = gcd (h, t), hl = h / hn;
	wn = gcd (w, t), wl = w / hn;

	// cerr << hn << " " << hl << " " << wn << " " << wl << endl;
	ll pans = kmi (2, hl) + kmi (2, wl) + 1;
	// cerr << pans << endl;
	ll fans = kmi(pans, hn * wn % mod); 
	
	cout << fans << endl;
	return 0;
}