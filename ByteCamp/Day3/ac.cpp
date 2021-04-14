#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef unsigned long long ll;
typedef pair <ll, ll> pll;

int n, q;
ll a[100010];

namespace LinearBase {
	const int m = 63;
	const ll MX = (1ll << 62);
	struct LB {
		pll b[64], c[64];
		void init() {
			for (int i = 0; i <= m; i ++)
				b[i].F = b[i].S = c[i].F = c[i].S = 0;
		}
		LB() {init();}
		void insert (ll x, ll y) {
			bool flag = 0;
			for (int i = m - 1; i >= 0 && x; i --)
				if (x >> i & 1) {
					if (c[i].F == 0 && c[i].S == 0) {
						c[i].F = x;
						c[i].S = y;
						for (int j = i - 1; j >= 0; j --)	if (c[i].F >> j & 1)	c[i].F ^= c[j].F, c[i].S ^= c[j].S;
						for (int j = m - 1; j >= 0; j --)	if (c[i].S >> j & 1)	c[i].F ^= b[j].F, c[i].S ^= b[j].S;
						for (int j = m - 1; j > i; j --)	if (c[j].F >> i & 1)	c[j].F ^= c[i].F, c[j].S ^= c[i].S;
						return ;
					}
					else {
						x ^= c[i].F, y ^= c[i].S;
					}
				}
			for (int i = m - 1; i >= 0 && y; i --) {
				if (y >> i & 1) {
					if (b[i].F == 0 && b[i].S == 0) {
						b[i].F = x;
						b[i].S = y;
						for (int j = i - 1; j >= 0; j --)	if (b[i].S >> j & 1)	b[i].F ^= b[j].F, b[i].S ^= b[j].S;
						for (int j = m - 1; j > i; j --)	if (b[j].S >> i & 1)	b[j].F ^= b[i].F, b[j].S ^= b[i].S;
						return ;
					}
					else
						x ^= b[i].F, y ^= b[i].S;
				}
			}
		}
		void Insert (ll v) {
			ll x, y, z, pv = (1ll<<(m-1));
			z = v; x = v, y = 0;
			while (z < MX) 	{insert (0, z);z <<= 1;if (z >= MX / 2) break; }
			for (int i = 0; i <= m; i ++) {
				insert (y, x);
				y /= 2;
				y+=x%2*pv; 
				x /= 2; 
			}
		}
		void init (ll v)	{Insert(v);}
		LB (ll v) 			{Insert(v);}
		LB combine (LB lb) {
			LB ans = *this;
			for (int i = 0; i < m; i ++)	if (lb.b[i].F != 0 || lb.b[i].S != 0)	ans.insert (lb.b[i].F, lb.b[i].S);
			for (int i = 0; i < m; i ++)	if (lb.c[i].F != 0 || lb.c[i].S != 0)	ans.insert (lb.c[i].F, lb.c[i].S);
			return ans;
		// can opt
		}

		ll outp2 () {
			cout << "pre out " << endl;
			for (int i = 0; i < m; i ++)
				cout << i << " : " << b[i].F << " " << b[i].S << endl;
			for (int i = 0; i < m; i ++)
				cout << i << " :: " << c[i].F << " " << c[i].S << endl;
			return -1;
		}


		ll outp () {
			// cerr << "pre out " << endl;
			// for (int i = 0; i < m; i ++)
				// cerr << i << " : " << b[i].F << " " << b[i].S << endl;
			for (int i = 0; i < m; i ++)
				if (b[i].S != 0)
					return b[i].S;
			// cerr << "outp ABSELUTELY WRONG" << endl;
			// assert (0);
			return -1;
		}
	};
//ATTENTION: those two "for" must not be switched
}using namespace LinearBase;

typedef struct node {
	int st, ed;
	node *l, *r;
	LB lb;
	node (int stt, int edd, node *L, node *R) {
		st = stt, ed = edd, l = L, r = R;
	}
} *pnode;

pnode build (int st, int ed) {
	// cerr << "build " << st << " " << ed << endl;
	if (st == ed) {
		pnode ne = new node (st, ed, 0, 0);
		ne->lb.init (a[st]);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, build (st, mid), build (mid + 1, ed));
	ne->lb = ne->l->lb.combine (ne->r->lb);
	return ne;
}

void modify (pnode r, ll v, int p) {
	if (!r)
		return ;
	if (r->st == r->ed) {
		r->lb = LB (v);
		return ;
	}
	if (p <= r->l->ed)	modify (r->l, v, p);
	if (r->r->st <= p)	modify (r->r, v, p);
	r->lb = r->l->lb.combine (r->r->lb);
}

LB fans;
void query (pnode r, int st, int ed) {
	// if (fans.b[0].S == 1)
		// return ;
	// cout << "q :  " << st << " " << ed << " " << r->st << " " << r->ed << endl;
	if (st <= r->st && r->ed <= ed) {
		fans = fans.combine (r->lb);
		return ;
	}
	if (st <= r->l->ed)
		query (r->l, st, ed);
	if (r->r->st <= ed)
		query (r->r, st, ed);
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	// cerr << "? " << endl;
	pnode root = build (1, n);	
	// cerr << ". " << endl;

	cin >> q;

	ll a, b, c;
	LB pans;
	for (int i = 1; i <= q; i ++) {
		// cerr << "process " << i << endl;
		cin >> a >> b >> c;
		if (a == 1) {
			modify (root, c, b);
		}
		else {
			fans.init();
			query (root, b, c);
			cout << fans.outp() << '\n';
		}
	}
	cerr << "TIME: " << TIME << endl;
	return 0;
}