#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#define MP make_pair
#define F first
#define S second
using namespace std;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

typedef pair <int, int> pii;
pii operator + (const pii a, const pii b) {
	return MP (a.F + b.F, a.S + b.S);
}
int n, m, q;
int v[1000010], s[1000010];
vector <int> I[1000010], O[1000010];

struct Query {
	int l, r, id;
	bool operator < (const Query u) const {
		return r < u.r;
	}
} query[1000010];
int ans[1000010];

int bel[1000010];
namespace SegTree {
	typedef struct node {
		int st, ed;
		node *l, *r;
		int sum;
		node (int stt, int edd, node *L, node *R, int summ) {
			st = stt, ed = edd, l = L, r = R, sum = summ;
		}
	} *pnode;
	pnode build (int st, int ed) {
		if (st == ed) {
			pnode ne = new node (st, ed, 0, 0, 0);
			return ne;
		}
		int mid = (st + ed) >> 1;
		pnode ne = new node (st, ed, build(st, mid), build(mid + 1, ed), 0);
		return ne;
	}
	void update (pnode r) {
		if (!r || !r->l)
			return ;
		r->sum = r->l->sum + r->r->sum;
	}
	void add (pnode r, int p, int v_s) {
		// cerr << "adding " << r << " " << r->st << " " << r->ed << " " << p << " " << v_s << " " << v_n << endl;
		if (!r || !p) {
			// cerr << "pre ret " << endl;
			return ;
		}
		if (r->st == r->ed) {
			r->sum += v_s;
			return ;
		}
		if (p <= r->l->ed)	add (r->l, p, v_s);
		else				add (r->r, p, v_s);
		update (r);
		return ;
	}
	int query (pnode r, int st, int ed) {
		if (st <= r->st && r->ed <= ed)
			return r->sum;
		int pans = 0;
		if (st <= r->l->ed)	pans = pans + query(r->l, st, ed);
		if (r->r->st <= ed)	pans = pans + query(r->r, st, ed);
		return pans;
	}
}

int main() {
	// ios::sync_with_stdio(false);
	read(n);
	read(m);
	read(q);
	// cin >> n >> m >> q;
	for (int i = 1; i <= n; i ++) {
		// cin >> v[i];
		read(v[i]);
		s[i] = s[i - 1] + v[i];
	}
	for (int a, b, i = 1; i <= m; i ++) {
		// cin >> a >> b;
		read(a);
		read(b);
		I[b].push_back(a);
		O[a].push_back(b);
	}
	for (int i = 1; i <= q; i ++) {
		// cin >> query[i].l >> query[i].r;
		read(query[i].l);
		read(query[i].r);
		query[i].id = i;
	}
	
	return 0;
}