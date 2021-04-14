/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-19 16:08:11
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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
const int mod = 998244353; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
int d[110];

ll st[110], ed[110];
ll pst = 0;

ll kmi  (ll x, ll t) {
	ll ans = 1;
	for (x %= mod; t; t >>= 1, x = x * x % mod)
		if (t & 1)
			ans = ans * x % mod;
	return ans;
}

ll fans = 1;
ll fnum = 0;

void dfs (int p, ll l, ll r, ll num) {
	if (st[p] > r + 1 || ed[p] < l - 1)
		return ;
	ll nl = min (st[p], l);
	ll nr = max (ed[p], r);

	ll ol = min (ed[p], r) - max (st[p], l) + 1;

	ll fac = kmi (2, ol);

	if (nl == l && nr == r)
		fac --;
	ll nnum = fac * num;
	cerr << p << " : " << nl << " " << nr << " " << nnum << endl;

	if (nr - nl + 1 > fans) {
		fans = nr - nl + 1;
		fnum = nnum;
	}
	else if (nr - nl + 1 == fans) {
		fnum += nnum;
	}

	for (int i = p + 1; i <= pst; i ++)
		dfs (i, nl, nr, nnum);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> d[0];
    ll c = 0;
    for (int i = 0; i < n; i ++) {
    	cin >> d[i];
    	if (d[i] > 0) {
    		ll x = c + d[i];
    		if (i != 0 && d[i - 1] > 0)
    			ed[pst] = x;
    		else {
    			pst ++;
    			st[pst] = c;
    			ed[pst] = x;
    		}
    		c = x;
    	}
    	else {
    		ll x = c + d[i];
    		c = x;
    	}
    }
    if (pst == 0) {
    	cout << 1 << " " << c + 1 << endl;
    	return 0;
    }
    dfs (1, 0, -1, 1);
    // for (int i = 1; i <= pst; i ++)
    // 	cout << i << " : " << st[i] << " " << ed[i] << endl;
    cout << fans << " " << fnum % mod << endl;
    return 0;
}