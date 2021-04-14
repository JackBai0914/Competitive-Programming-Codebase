#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;
const int mod = 998244353;

int n, m, type;
int a[2000020];
vector<pair <int, int> > rec;

struct matrix {
	int v[2][2];
	matrix () {memset(v, 0, sizeof v);}
	matrix operator * (const matrix x) {
		matrix ans;
		for (int k = 0; k < 2; k ++)
			for (int i = 0; i < 2; i ++)
				for (int j = 0; j < 2; j ++)
					(ans.v[i][j] += (long long)v[i][k] * x.v[k][j] % mod) %= mod;
		return ans;
	}
	void one() {
		v[0][0] = 1;
		v[1][1] = 1;
	}
}One;


namespace SegTree {
	typedef struct node {
		int st, ed;
		matrix m;
		node *l, *r;
		node (int ss, int ee, int v, node *L, node *R) {
			l = L, r = R, st = ss, ed = ee;
			if (v != 0) {
				m.v[0][0] = v;
				m.v[0][1] = m.v[1][0] = 1;
			}
			else {
				m = One;
			}
		}
	} *pnode;
	void update (pnode r) {
		if (!r || !r->l)
			return ;
		r->m = r->l->m * r->r->m;
	}
	pnode build (int st, int ed) {
		if (st == ed) {
			pnode ne = new node (st, ed, a[st], 0, 0);
			return ne;
		}
		int mid = (st + ed) >> 1;
		pnode ne = new node (st, ed, 0, build(st, mid), build(mid + 1, ed));
		update (ne);
		return ne;
	}
	void modify (pnode r, int pos, int v) {
		if (r->st == r->ed) {
			memset(r->m.v, 0, sizeof r->m.v);
			r->m.v[0][0] = v;
			r->m.v[0][1] = r->m.v[1][0] = 1;
			return ;
		}
		if (pos <= r->l->ed)	modify (r->l, pos, v);
		if (r->r->st <= pos)	modify (r->r, pos, v);
		update (r); 
	}
	matrix find (pnode r, int st, int ed) {
		if (st <= r->st && r->ed <= ed)
			return r->m;
		matrix pans = One;
		if (st <= r->l->ed)	pans = pans * find(r->l, st, ed);
		if (r->r->st <= ed)	pans = pans * find(r->r, st, ed);
		return pans;
	}
}

void force (int l, int r) {
	long long x = a[r], y = 1;
	for (int i = r - 1; i >= l; i --) {
		long long nx = y + x * a[i];
		long long  ny = x;
		x = nx % mod;
		y = ny % mod;
	}
	cerr << "force: " << x << " " << y << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	One.one();
	memset(a, 0, sizeof a);
	cin >> n >> m >> type;
	for (int i = 1; i <= n; i ++)	cin >> a[i];

	SegTree::pnode root = SegTree::build(1, n + m);

	int ansx = 0, ansy = 0;
	for (int op, x, l, r, i = 1; i <= m; i ++) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			if (type)
				x ^= ansx ^ ansy;
			// cerr << "adding: " << x << endl;
			n ++;
			SegTree::modify (root, n, x);
			a[n] = x;
		}
		else {
			cin >> l >> r;
			if (type)
				l ^= ansx ^ ansy, r ^= ansx ^ ansy;
			// cerr << l << " : " << r << endl;
			// for (int j = 1; j <= n; j ++)
				// cerr << j << " : " << a[j] << endl;
			matrix calc = SegTree::find(root, l, r - 1);
			matrix end;
			end.v[0][0] = a[r];
			end.v[1][0] = 1;
			// cout << "P:" << end.v[0][0] << ' ' << end.v[1][0] << '\n';
			end = calc * end;
			// force (l, r);
			// cerr << end.v[0][0] << ' ' << end.v[1][0] << '\n';
			cout << end.v[0][0] << ' ' << end.v[1][0] << '\n';
			ansx = end.v[0][0];
			ansy = end.v[1][0];
		}
	}

	return 0;
}