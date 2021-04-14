/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* https://www.luogu.com.cn/problem/P3373
* @author: Xingjian Bai 
* @date: 2020-11-19 17:12:16
* @description: 
* /Users/jackbai/Desktop/Template/SegTree/SegTree_basic.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv SegTree_basic.cpp
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

const int MAXN = 200005;
#define mid ((st + ed) >> 1)
#define lch (r << 1)
#define rch (r << 1 | 1)

int n, m, p;
ll a[MAXN];

ll lazp[MAXN << 2], lazm[MAXN << 2], sum[MAXN << 2];

void set_point (int r, ll s, ll lp, ll lm) {
	sum[r] = s;
	lazp[r] = lp;
	lazm[r] = lm;
}

void update (int r) {
	sum[r] = (sum[lch] + sum[rch]) % p;
}

void build_tree (int r, int st, int ed) {
	if (st == ed) {
		set_point(r, a[st], 0, 1);
		return ;
	}
	build_tree(lch, st, mid);
	build_tree(rch, mid + 1, ed);
	set_point(r, 0, 0, 1);
	update(r);
}

void pushdown (int r, int st, int ed) {
	if (lazp[r] == 0 && lazm[r] == 1)
		return ;
	set_point (lch, (sum[lch] * lazm[r] + lazp[r] * (mid - st + 1)) % p, (lazp[lch] * lazm[r] + lazp[r]) % p, lazm[lch] * lazm[r] % p); 
	set_point (rch, (sum[rch] * lazm[r] + lazp[r] * (ed - mid)) % p, (lazp[rch] * lazm[r] + lazp[r]) % p, lazm[rch] * lazm[r] % p); 
	lazp[r] = 0;
	lazm[r] = 1;
}

void modify (int r, int st, int ed, int tst, int ted, ll mul, ll pl) {
	if (tst <= st && ed <= ted)
		return set_point (r, (sum[r] * mul + pl * (ed - st + 1)) % p, (lazp[r] * mul + pl) % p, lazm[r] * mul % p);
	pushdown(r, st, ed);
	if (tst <= mid)	modify (lch, st, mid, tst, ted, mul, pl);
	if (mid < ted)	modify (rch, mid + 1, ed, tst, ted, mul, pl);
	update(r);
}

ll query (int r, int st, int ed, int tst, int ted) {
	if (tst <= st && ed <= ted) {		
		return sum[r];
	}
	pushdown(r, st, ed);
	ll ans = 0;
	if (tst <= mid)	ans += query (lch, st, mid, tst, ted);
	if (mid < ted)	ans += query (rch, mid + 1, ed, tst, ted);
	return ans % p;
}

int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	build_tree(1, 1, n);
	while (m --) {
		int tp, x, y, k;
		cin >> tp >> x >> y;
		if (tp == 1) {
			cin >> k;
			modify (1, 1, n, x, y, k, 0);
		}
		else if (tp == 2) {
			cin >> k;
			modify (1, 1, n, x, y, 1, k);
		}
		else
			cout << query(1, 1, n, x, y) << '\n';
	}
    return 0;
}