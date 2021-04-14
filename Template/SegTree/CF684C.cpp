/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-19 19:08:04
* @description: 
* /Users/jackbai/Desktop/OI/CF684/3.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 3.cpp
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

int n, q;
int a[MAXN];

ll s[MAXN << 2], mx[MAXN << 2], mn[MAXN << 2], lz[MAXN << 2];

void update(int r) {
	s[r] = s[lch] + s[rch];
	mx[r] = mx[lch];
	mn[r] = mn[rch];
}

void build_tree(int r, int st, int ed) {
	if (st == ed) {
		s[r] = mx[r] = mn[r] = a[st];
		lz[r] = 0;
		return ;
	}
	build_tree(lch, st, mid);
	build_tree(rch, mid + 1, ed);
	update(r);
}

void push_down(int r, int st, int ed) {
	if (!lz[r] || st == ed)
		return ;
	s[lch] = lz[r] * (mid - st + 1);
	s[rch] = lz[r] * (ed - mid);
	lz[lch] = lz[rch] = mx[lch] = mx[rch] = mn[lch] = mn[rch] = lz[r];
	lz[r] = 0;
}

void modify (int r, int st, int ed, int ted, ll val) {
	push_down(r, st, ed);
	if (ted < ed) {
		if (ted <= mid)
			modify(lch, st, mid, ted, val);
		else {
			modify(lch, st, mid, ted, val);
			modify(rch, mid + 1, ed, ted, val);
		}
		update(r);
		return ;
	}
	if (mx[r] <= val) {
		mx[r] = mn[r] = lz[r] = val;
		s[r] = val * (ed - st + 1);
		return ;
	}
	if (mn[r] >= val)
		return ;
	modify(lch, st, mid, ted, val);
	modify(rch, mid + 1, ed, ted, val);
	update(r);
}

pii query (int r, int st, int ed, int ted, ll val) {
	push_down(r, st, ed);
	if (val < mn[r])
		return MP(0, 0);
	if (st < ted) {
		if (mid < ted)
			return query (rch, mid + 1, ed, ted, val);
		pii pans1 = query(lch, st, mid, ted, val);
		pii pans2 = query(rch, mid + 1, ed, ted, val - pans1.F);
		return MP(pans1.F + pans2.F, pans1.S + pans2.S);
	}
	if (val >= s[r])	return MP(s[r], ed - st + 1);

	pii pans1 = query(lch, st, mid, ted, val);
	pii pans2 = query(rch, mid + 1, ed, ted, val - pans1.F);

	return MP(pans1.F + pans2.F, pans1.S + pans2.S);
}


int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	build_tree(1, 1, n);
	int t, x, y;	pii ans;
	while (q --) {
		cin >> t >> x >> y;
		if (t == 1)
			modify(1, 1, n, x, y);
		else {
			ans = query(1, 1, n, x, y);
			cout << ans.S << '\n';
		}
	}

    return 0;
}