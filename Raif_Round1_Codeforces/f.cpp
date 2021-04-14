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

#define int ll

ll n = 0;
pii a[500050];
ll s[500050];

ll mx[500050][22];
ll mi2[22];

ll ans = 0;

ll prep[500050];
void input() {
	FOR(i, 1, 500010)
		prep[i] = (ll)i * (i + 1) / 2;
	FOR(i, 1, 500010)
		prep[i] += prep[i - 1];

	int l;
	string inp;
	cin >> l >> inp;
	int prev = -1;
	int num = 0;
	F0R(i, l) {
		if (prev == -1)
			prev = inp[i] - '0';
		if (prev == inp[i] - '0')
			num ++;
		else {
			a[n ++] = MP(num, prev);
			prev = inp[i] - '0';
			num = 1;
		}
	}
	if (num)
		a[n ++] = MP(num, prev);
	F0R (i, n + 1)
		s[i] = (i ? s[i - 1] + a[i].F : a[i].F);

	for (int i = 0; i <= 20; i ++)
		mi2[i] = (1<<i);
	for(int i = 0; i < n; i ++)
		mx[i][0] = i;
	for(int i = 1; i <= 20; i ++) {
		int p = (1<<i);
		int id1, id2;
		for (int j = 0; j + p <= n; j ++) {
			id1 = mx[j][i - 1];
			id2 = mx[j + p/2][i - 1];
			if (a[id1].F * a[id1].S > a[id2].F * a[id2].S)
				mx[j][i] = id1;
			else
				mx[j][i] = id2;
		}
	}

	// for (int i = 0; i < n; i ++) {
		// for (int j = 0; j <= 3; j ++) {
			// cerr << "mx " << i << " " << j << " " << mx[i][j] << endl;
		// }
	// }
}

ll calc_mx_id (int st, int ed) { //[st, ed)
	int p = log2 (ed - st) + eps;
	int id1 = mx[st][p];
	int id2 = mx[ed - mi2[p]][p];
	if (a[id1].F * a[id1].S > a[id2].F * a[id2].S)
		return id1;
	else
		return id2;
}

ll calc_num (int st, int ed) {
	if (ed < st)
		return 0;
	if (st == 0)
		return s[ed];
	return s[ed] - s[st - 1];
}

ll calc_ari (ll st, ll ed) {
	return (st <= ed ? (st + ed) * (ed - st + 1) / 2 : 0);
}

ll calc_sum (ll mx, ll lmx) {
	return lmx * lmx + calc_ari(lmx + 1, mx);
}


void deal (int st, int ed) {
	if (ed - st == 0)
		return ;
	if (ed - st == 1) {
		ans += (a[st].S == 1) * prep[a[st].F];
		return ;
	}

	int id = calc_mx_id (st, ed);
	ll mx = a[id].F * a[id].S;
	//st in l, ed in r
	ans += calc_num(st, id - 1) * calc_num(id + 1, ed - 1) * mx;
	// debug (calc_num(st, id - 1) * calc_num(id + 1, ed - 1) * mx);

	//st in m, ed in m
	deal (id, id + 1);

	//st in l, ed in m
	ll l_mx = 0, prev = 0, c;
	for (int i = id - 1; i >= st; i --) {
		for (int j = 0; j < a[i].F; j ++) {
			c = a[i].S;
			if (c == 0)
				prev = 0;
			if (c == 1) {
				prev ++;
				l_mx = max (l_mx, prev);
			}
			ans += calc_sum(mx, l_mx);
			// debug(calc_sum(mx, l_mx));
		}
	}

	//st in m, ed in r
	ll r_mx = 0; prev = 0;
	for (int i = id + 1; i < ed; i ++) {
		for (int j = 0; j < a[i].F; j ++) {
			c = a[i].S;
			if (c == 0)
				prev = 0;
			if (c == 1) {
				prev ++;
				r_mx = max (r_mx, prev);
			}
			ans += calc_sum(mx, r_mx);
			// debug(calc_sum(mx, r_mx));
		}
	}

	//st in l, ed in l
	deal(st, id);

	//st in r, ed in r
	deal(id + 1, ed);
}

signed main() {
	input();
	deal(0, n);
	cout << ans << endl;
    return 0;
}