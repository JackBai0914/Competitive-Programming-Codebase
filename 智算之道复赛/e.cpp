#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

int n, m;
ll wei[200020], lab[200020], pnum[200020], psum[200020], ans[200020];

ll par[200020], tnum[200020], descend[200020];
vector <int> son[200020];

namespace Partition_Segtree {
	int cap[200020], top[200020], dep[200020], col[200020];
	int link[200020], ed[200020], name[200020], now = 0;

	void partition(int x)
	{
		now ++;
		name[now] = x;
		link[x] = now;
		if (descend[x]) {
			top[descend[x]] = top[x];
			partition(descend[x]);
		}
		for (int i = 0; i < son[x].size(); i ++) {
			int s = son[x][i];
			if (s != descend[x]) {
				top[s] = s;
				partition(s);
			}
		}
		ed[x] = now;
	}

	typedef struct node
	{
		bool lab;
		int lsum;
		ll ans, lazy;
		int st, ed;
		node *l, *r;
		node (bool labb, int anss, int stt, int edd, node *L, node *R, int lsumm) {
			lab = labb, ans = anss, st = stt, ed = edd, l = L, r = R, lsum = lsumm; lazy = 0;
		}
	}*pnode;

	void update (pnode r) {
		if (!r || !r->l)
			return ;
		r->ans = r->l->ans * r->l->lab + r->r->ans * r->r->lab;
		r->lsum = r->l->lsum + r->r->lsum;
	}

	pnode build(int st, int ed)
	{
		if (st == ed) {
			// cerr << "building" << ed << " " << name[ed] << endl;
			pnode ne = new node(lab[name[ed]], ans[name[ed]], st, ed, 0, 0, lab[name[ed]]);
			// cerr << "bulidinginging: " << st <<
			return ne;
		}
		int mid = (st + ed) >> 1;
		pnode ne = new node(1, 0, st, ed, build(st, mid), build(mid + 1, ed), 0);
		update(ne);
		return ne;
	}

	void update_lab (pnode r, int p, bool lab) {
		if (r->st == r->ed) {
			r->lab = r->lsum = lab;
			return ;
		}
		if (p <= r->l->ed)	update_lab (r->l, p, lab);
		if (r->r->st <= p)	update_lab (r->r, p, lab);
		update (r);
	}

	void update_ans (pnode r, int p, ll ans) {
		if (r->st == r->ed) {
			r->ans = ans;
			return ;
		}
		if (p <= r->l->ed)	update_ans (r->l, p, ans);
		if (r->r->st <= p)	update_ans (r->r, p, ans);
		update (r);
	}

	bool query_lab (pnode r, int st, int ed) {
		if (st <= r->st && r->ed <= ed)
			return (r->lsum != 0);
		bool ans = false;
		if (st <= r->l->ed)	ans |= query_lab(r->l, st, ed);
		if (r->r->st <= ed)	ans |= query_lab(r->r, st, ed);
		return ans;
	}
	ll query_sum (pnode r, int st, int ed) {
		if (st <= r->st && r->ed <= ed)
			return r->ans * r->lab;
		ll ans = 0;
		if (st <= r->l->ed)	ans += query_sum(r->l, st, ed);
		if (r->r->st <= ed)	ans += query_sum(r->r, st, ed);
		return ans;
	}
}using namespace Partition_Segtree;
pnode root = 0;

void calc_pnum (int x) {
	tnum[x] = 1;
	int mx_son = 1;
	for (int i = 0; i < son[x].size(); i ++) {
		int s = son[x][i];
		calc_pnum (s);
		tnum[x] += tnum[s];
		pnum[x] -= tnum[s] * (tnum[s] - 1) / 2;
		if (tnum[s] > mx_son) {
			mx_son = tnum[s];
			descend[x] = s;
		}
	}
	pnum[x] += (tnum[x] - 1) * tnum[x] / 2;
}

void calc_psum (int x) {
	psum[x] = pnum[x];
	for (int i = 0; i < son[x].size(); i ++) {
		int s = son[x][i];
		calc_psum (s);
		psum[x] += psum[s] * (lab[s] == 0);
	}
	ans[x] = psum[x] * wei[x];
}

//x is changing from black to white, so some of its ancestors' psum need to change.
void change_psum_to_0 (int x) {
	// x = par[x];
	// while (query_lab(root, link[top[x]], link[x]) == false) {

	// }
	//force.
	ll add = psum[x];
	x = par[x];
	while (x) {
		psum[x] += add;
		ans[x] = psum[x] * wei[x];
		update_ans (root, link[x], ans[x]);
		if (lab[x])
			break;
		x = par[x];
	}
}

//x is changing from white to black, so some of its ancestors' psum need to change.
void change_psum_to_1 (int x) {
	//force.
	ll sub = psum[x];
	x = par[x];
	while (x) {
		psum[x] -= sub;
		ans[x] = psum[x] * wei[x];
		// cerr << "new: " << x << " : " << psum[x] << " " << wei[x] << " " << ans[x] << endl;
		update_ans (root, link[x], ans[x]);
		if (lab[x])
			break;
		x = par[x];
	}
}

//calculate the subtree Sigma {lab * ans} of x
ll calc_ans (int x) {
	// cerr << "qing: " << link[x] << " " << ed[x] << endl;
	return query_sum(root, link[x], ed[x]);
}

int find_black_father (int x) {
	//force.
	do {
		if (lab[x])
			return x;
		x = par[x];
	} while (x);
	return -1;
}



int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 2; i <= n; i ++) {
		cin >> par[i];
		son[par[i]].push_back (i);
	}
	for (int i = 1; i <= n; i ++)
		cin >> wei[i];

	calc_pnum (1);
	calc_psum (1);


	top[1] = 1;
	partition(1);
	root = build(1, now);

	// cerr << query_sum(root, 1, 1) << endl;
	// cerr << query_sum(root, 2, 2) << endl;
	// cerr << query_sum(root, 3, 3) << endl;
	// cerr << query_sum(root, 4, 4) << endl;	

	for (int tt = 1; tt <= m; tt ++) {
		char c;	int u, w;	cin >> c;
		if (c == 'Q') {
			cin >> u;
			//using Partition + Segtree to calc subtree
			int bf = find_black_father(u);
			// cerr << ": " << calc_ans (u) << endl;
			if (bf == -1 || lab[u])
				cout << calc_ans (u) << '\n';
			else
				cout << calc_ans (u) + wei[bf] * psum[u] << endl;
		}
		if (c == 'M') {
			//since we only maintain DanDian(and calc subtree when querying)
			//we only need to change the ans of this point
			cin >> u >> w;
			wei[u] = w;
			ans[u] = psum[u] * wei[u];
			update_ans (root, link[u], ans[u]);
		}
		if (c == 'F') {
			cin >> u;
			if (lab[u]) {
				//change 1 to 0
				change_psum_to_0(u);
			}
			else {
				//change 0 to 1
				change_psum_to_1(u);
			}
			lab[u] ^= 1;
			update_lab (root, link[u], lab[u]);
		}
		// cerr << query_sum(root, 1, 1) << endl;
		// cerr << query_sum(root, 2, 2) << endl;
		// cerr << query_sum(root, 3, 3) << endl;
		// cerr << query_sum(root, 4, 4) << endl;
		// for (int i = 1; i <= n; i ++)	cerr << pnum[i] << ' ';cerr << "pnum " << endl;
		// for (int i = 1; i <= n; i ++)	cerr << psum[i] << ' ';cerr << "psum " << endl;
		// for (int i = 1; i <= n; i ++)	cerr << ans[i] << ' ';cerr <<  "ans " << endl;
	}
	
	return 0;
}