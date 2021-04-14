/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 10:31:31
* @description: 
* /Users/jackbai/Desktop/OI/OpenCup/e.cpp 
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
const int INF = 1e9;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl
const int maxn = 1e6;
int n, m;
ll fans = 0;
vector <int> adj[maxn];

ll dg[maxn], dg2[maxn], sdg[maxn];
int  a3[maxn], a3i[maxn];
priority_queue <pii> a3q;

namespace SegTree{
	typedef struct node {
		int st, ed;
		node *l, *r;
		ll mx, num_mx, lz;
		ll mx2, num_mx2;
		node () {}
		node (int stt, int edd, node *L, node *R, ll mxx) {
			st = stt, ed = edd, l = L, r = R, mx = mxx, num_mx = 1, mx2 = -INF, num_mx2 = 0, lz = 0;
		}
	} *pnode;
	void update (pnode r) {
		if (!r || !r->l)
			return ;
		r->mx = max (r->l->mx, r->r->mx);
		r->mx2 = -INF;
		if (r->l->mx != r->mx)	r->mx2 = max (r->mx2, r->l->mx);
		if (r->r->mx != r->mx)	r->mx2 = max (r->mx2, r->r->mx);
		if (r->l->mx2 != r->mx)	r->mx2 = max (r->mx2, r->l->mx2);
		if (r->r->mx2 != r->mx)	r->mx2 = max (r->mx2, r->r->mx2);
		r->num_mx = 0;
		r->num_mx2 = 0;
		if (r->l->mx == r->mx)		r->num_mx += r->l->num_mx;
		if (r->r->mx == r->mx)		r->num_mx += r->r->num_mx;
		if (r->l->mx2 == r->mx)		r->num_mx += r->l->num_mx2;
		if (r->r->mx2 == r->mx)		r->num_mx += r->r->num_mx2;
		if (r->l->mx == r->mx2)		r->num_mx2 += r->l->num_mx;
		if (r->r->mx == r->mx2)		r->num_mx2 += r->r->num_mx;
		if (r->l->mx2 == r->mx2)	r->num_mx2 += r->l->num_mx2;
		if (r->r->mx2 == r->mx2)	r->num_mx2 += r->r->num_mx2;
	}
	pnode build (int st, int ed) {
		if (st == ed) {
			pnode ne = new node (st, ed, 0, 0, sdg[st]);
			return ne;
		}
		int mid = (st + ed) >> 1;
		pnode ne = new node (st, ed, build (st, mid), build (mid + 1, ed), 0);
		update (ne);
		return ne;
	}
	void down (pnode r) {
		if (!r || !r->l)
			return ;
		if (r->lz) {
			r->l->mx += r->lz;
			r->r->mx += r->lz;
			r->l->mx2 += r->lz;
			r->r->mx2 += r->lz;
			r->l->lz += r->lz;
			r->r->lz += r->lz;
			r->lz = 0;
		}
	}
	void modify (pnode r, int st, int ed, ll v) {
		if (st <= r->st && r->ed <= ed) {
			r->mx += v;
			r->mx2 += v;
			r->lz += v;
			return ;
		}
		down (r);
		if (st <= r->l->ed)	modify (r->l, st, ed, v);
		if (r->r->st <= ed)	modify (r->r, st, ed, v);
		update (r);
	}
	ll count_zero(pnode r, int st, int ed, ll v) {
		// cout << r->st << " " << r->ed << " " << st << " " << ed << " " << v << endl;
		// cout << "info: " << r->mx << " " << r->num_mx << " " << r->mx2 << " " << r->num_mx2 << endl;
		if (st <= r->st && r->ed <= ed) {
			if (r->mx == v)		return r->num_mx;
			if (r->mx2 == v)	return r->num_mx2;
			return 0;
		}
		down (r);
		ll ans = 0;
		if (st <= r->l->ed)	ans += count_zero (r->l, st, ed, v);
		if (r->r->st <= ed)	ans += count_zero (r->r, st, ed, v);
		return ans;
	}
	void order (pnode r) {
		// cout << r->st << " " << r->ed << " : " << r->mx << " " << r->mx2 << " " << r->num_mx << " " << r->num_mx2 << endl;
		if (r->st == r->ed) {
			cout << r->st << " : " << r->mx << endl;
			return ;
		}
		down(r);
		order(r->l);
		order(r->r);
	}
} using namespace SegTree;
pnode root;


void dg_minus(int x, ll dt) {
	dg2[x] -= dt;
	modify (root, x, n, -dt);
}

ll find_sdg (int st, int ed, ll val) {
	return count_zero(root, st, ed, val);
}

int main() {
	scanf("%d %d", &n, &m);
	F0R(i, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		dg[x] ++, dg[y] ++;
		dg2[max(x, y)] ++;
	}
	FOR(i, 1, n + 1) {
		sort(adj[i].begin(), adj[i].end());
		if (adj[i].size() >= 3) {
			a3[i] = adj[i][2], a3i[i] = 2;
			a3q.push(MP(-max(i, a3[i]), i));
		}	
		else {
 			a3[i] = n + 1, a3i[i] = adj[i].size();
 			a3q.push(MP(-(n + 1), i));
 		}
		sdg[i] = sdg[i - 1] + dg2[i];
	}
	FOR(i, 1, n + 1)
		sdg[i] -= i;

	root = build(1, n);

	FOR(i, 1, n + 1) {
		order(root);
		// cout << "begin" << endl;
		//find the largest r such that for all i from l to r, dg[i] <= 2
		int bound, bid;
		bool cont = true;
		do {
			pii tp = a3q.top();
			bound = -tp.F, bid = tp.S;
			if (bound == n + 1)							break;
			if (bid >= i && bound == max(bid, a3[bid]))	break;
			a3q.pop();
		} while (true);
		bound = min (bound, n + 1);
		// cout << "bound: " << bound << endl;
		//find the number of i from l to bound-1 such that sdg[i]-2*i==-2*l;
		ll pans = find_sdg(i, bound - 1, -i);
		cout << "find " << -i << " in " << i << " " << bound - 1 << endl;
		fans += pans;
		cout << "ans " << i << " : " << pans << endl;

		//delete i's neithbors' a3
		F0R(j, adj[i].size()) {
			int to = adj[i][j];
			if (to < i)
				continue ;
			if (a3i[to] == adj[to].size())
				continue ;
			a3i[to] ++;
			if (a3i[to] == adj[to].size()) {
				a3[to] = n + 1;
				a3q.push(MP(-(n + 1), i));
			}
			else {
				a3[to] = adj[to][a3i[to]];
				a3q.push(MP(-max(to, a3[to]), to));
			}
			
		}
		//delete i's neighbors's dg
		F0R(j, adj[i].size()) {
			int to = adj[i][j];
			if (to > i)
				dg_minus(to, 1);
		}
	}
	printf("%lld\n", fans);
	// cerr << TIME << endl;
    return 0;
}