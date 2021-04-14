#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define int long long
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int mx = 8e5 + 20;
int n, m;
ll ans1 = 0, ans2 = 0, ans0 = 0;
pii ex[mx];
int lca[mx], af[mx], as[mx];
namespace Tree {
	int point[mx], te = 0;
	struct e {int to, next;} edge[mx << 1];
	void add (int u, int v) {te ++, edge[te].to = v, edge[te].next = point[u], point[u] = te;}
	int par[mx], dep[mx], num[mx], desc[mx], top[mx];
	int st[mx], ed[mx], dfn[mx], ti = 0;
	int ve[mx];
	void set (int x) {
		st[x] = ++ ti;
		dfn[ti] = x;
		num[x] = 1;
		int mx = 0;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (to == par[x])
				continue ;
			par[to] = x;
			dep[to] = dep[x] + 1;
			set(to);
			num[x] += num[to];
			if (mx < num[to])
				mx = num[to], desc[x] = to;
		}
		ed[x] = ti;
	}
	void build (int x, int rt) {
		top[x] = rt;
		if (desc[x])
			build(desc[x], rt);
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (to == par[x] || to == desc[x])
				continue ;
			build(to, to);
		}
	}

	void Tree_init () {
		set(1);
		build(1, 1);
	}
	void Cumu (int x) {
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (to == par[x])
				continue ;
			ve[to] += ve[x];
			Cumu(to);
		}
	}
}using namespace Tree;

vector <int> hang[mx];
map <pii, int> over;
void deal_LCA(int x, int y, int id) {
	bool rev = 0;
	int z, ax = x, ay = y;
	int ix = min(x, y), iy = max(x, y);
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])	swap(x, y), swap(ax, ay), rev ^= 1;
		ax = top[x];
		x = par[top[x]];
	}
	if (dep[x] < dep[y]) {
		ay = desc[x];
		z = x;
	}
	else if (dep[x] > dep[y]) {
		ax = desc[y];
		z = y;
	}
	else
		z = (x + y) >> 1;

	// cout << ix << " " << iy << " res : " << z << " " << ax << " " << ay << endl;
	lca[id] = z;
	hang[z].push_back(id);
	over[MP(min(ax, ay), max(ax, ay))] ++;
	ve[ax] ++;
	ve[ay] ++;
	if (rev)	swap(ax, ay);
	af[id] = ax, as[id] = ay;
}

pii dex[mx];
bool sm (const pii a, const pii b) {return a.F < b.F;}
bool lg (const pii a, const pii b) {return a.S > b.S;}

int rt[mx];
bool inv (const int a, const int b) {return ed[a] > ed[b];}

namespace SegTree {
	typedef struct node {
		int st, ed;
		node *l, *r;
		int s;
		node (int stt, int edd, node *L, node *R, int ss) {
			st = stt, ed = edd, l = L, r = R, s = ss;
		}
	} *pnode;
	pnode Build (int st, int ed) {
		if (st == ed) {
			pnode ne = new node (st, ed, 0, 0, 0);
			return ne;
		}
		int mid = (st + ed) >> 1;
		pnode ne = new node (st, ed, Build(st, mid), Build(mid + 1, ed), 0);
		return ne;
	}
	void add (pnode r, int p) {
		if (!r)
			return ;
		r->s ++;
		if (r->st == r->ed)
			return ;
		if (p <= r->l->ed)	add (r->l, p);
		if (r->r->st <= p)	add (r->r, p);
		return ;
	}
	int query (pnode r, int st, int ed) {
		if (!r)
			return 0;
		if (st <= r->st && r->ed <= ed)
			return r->s;
		int ans = 0;
		if (st <= r->l->ed)	ans += query(r->l, st, ed);
		if (r->r->st <= ed)	ans += query(r->r, st, ed);
		return ans;
	}
} using namespace SegTree;

signed main() {
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	cin >> n >> m;
	m -= n - 1;
	for (int a, b, i = 1; i < n; i ++)	cin >> a >> b, add(a, b), add (b, a);
	for (int i = 1; i <= n; i ++)	add (i, n + i), add (n + i, i);
	for (int a, b, i = 1; i <= m; i ++) {
		cin >> ex[i].F >> ex[i].S;
		ex[i].F += n;
		ex[i].S += n;
	}
	n <<= 1;

	Tree_init();
// for (int i = 1; i <= n; i ++) 	cout << i << " : " << par[i] << " " << dep[i] << " " << num[i] << " " << top[i] << " " << st[i] << endl;
	for (int i = 1; i <= m; i ++)
		deal_LCA(ex[i].F, ex[i].S, i);
	Cumu(1);
	// for (int i = 1; i <= n; i ++)
	// 	cout << i << " : " << ve[i] << endl;
	for (int i = 1; i <= m; i ++) {
		int a = ex[i].F;
		int b = ex[i].S;
		int l = lca[i];
		// cout << ": " << a << " " << b << " " << l << endl;

		ans1 += ve[a] - ve[l] - 1;
		ans1 += ve[b] - ve[l] - 1;
	}

	for (map<pii, int>::iterator it = over.begin(); it != over.end(); it ++) {
		int numb =it->second;
		ans0 += (ll)numb * (numb - 1);
	}

	// for (int i = 1; i <= n; i ++)	cout << i << " : " << st[i] << " " << ed[i] << endl;

	pnode root = Build(1, n);
	for (int i = 1; i <= m; i ++) {
		dex[i] = MP(st[ex[i].F], st[ex[i].S]);
		if (dex[i].F > dex[i].S)
			swap(dex[i].F, dex[i].S);
		// cout << "dex " << i << " = " << dex[i].F << " , " << dex[i].S << endl;
	}
	sort(dex + 1, dex + m + 1, sm);
	int dst = 1;
	for (int i = 1; i <= n; i ++) {
		int x = dfn[i];
		for (int j = 0; j < hang[x].size(); j ++) {
			int id = hang[x][j];
			int st1 = st[af[id]], ed1 = ed[af[id]];
			int st2 = st[as[id]], ed2 = ed[as[id]];
			ans2 += query(root, st1, ed1);
			ans2 += query(root, st2, ed2);
			// cout << " - " << id << " " << ans2 << endl;
		}
		while (dst <= m && dex[dst].F == st[x])
			add (root, dex[dst].S), dst ++;
	}

	root = Build(1, n);
	sort(dex + 1, dex + m + 1, lg);
	dst = 1;
	for (int i = 1; i <= n; i ++)	rt[i] = i;
	sort(rt + 1, rt + n + 1, inv);
	for (int i = 1; i <= n; i ++) {
		int x = rt[i];
		// cout << "start : " << x << " " << st[x] << " " << ed[x] << endl;
		while (dst <= m && dex[dst].S > ed[x]) {
			// cout << "add " << dex[dst].F << " " << dex[dst].S << endl;
			add (root, dex[dst].F), dst ++;
		}
		for (int j = 0; j < hang[x].size(); j ++) {
			int id = hang[x][j];
			int st1 = st[af[id]], ed1 = ed[af[id]];
			int st2 = st[as[id]], ed2 = ed[as[id]];
			// cout << "search " << st1 << " " << ed1 << " " << st2 << " " << ed2 << endl;
			ans2 += query(root, st1, ed1);
			ans2 += query(root, st2, ed2);
			// cout << "result " << id << " " << ans2 << endl;
		}
	}
	// cout << ans1 << " " << ans2 << " " << ans0 << endl;
	cout << (ans1 + ans2 - ans0) / 2 << endl;

	return 0;
}