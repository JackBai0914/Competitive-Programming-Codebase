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

	ll fix (ll &x) {
		if (!x)
			return x;
		while (x % 2 == 0)
			x /= 2;
		return x;
	}

	ll combine (ll a, ll b) {
		ll aa = a, bb = b;
		if (a == b)
			return a;
		if (a < b)
			swap (a, b);
		ll ans = b;
		fix (a);
		fix (b);
		for (int i = 0; i <= 64; i ++) {
			a ^= b;
			fix (a);
			ans = min (ans, a);
		}
		ll fans = min (ans, combine (ans, b));
		cerr << ": " << aa << " " << bb << " : " << fans << endl;
		return fans;
	}
}using namespace LinearBase;

typedef struct node {
	int st, ed;
	node *l, *r;
	ll v;
	node (int stt, int edd, node *L, node *R) {
		st = stt, ed = edd, l = L, r = R;
	}
} *pnode;

pnode build (int st, int ed) {
	// cerr << "build " << st << " " << ed << endl;
	if (st == ed) {
		pnode ne = new node (st, ed, 0, 0);
		ne->v = fix(a[st]);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, build (st, mid), build (mid + 1, ed));
	ne->v = combine (ne->l->v, ne->r->v);
	return ne;
}

void modify (pnode r, ll v, int p) {
	if (!r)
		return ;
	if (r->st == r->ed) {
		r->v = fix (v);
		return ;
	}
	if (p <= r->l->ed)	modify (r->l, v, p);
	if (r->r->st <= p)	modify (r->r, v, p);
	r->v = combine (r->l->v, r->r->v);
}

ll fans = -1;
void query (pnode r, int st, int ed) {
	if (st <= r->st && r->ed <= ed) {
		if (fans == -1)
			fans = r->v;
		else
			fans = combine (fans, r->v);
		return ;
	}
	if (st <= r->l->ed) {
		query (r->l, st, ed);
	}
	if (r->r->st <= ed) {
		query (r->r, st, ed);
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	pnode root = build (1, n);	
	cin >> q;
	ll a, b, c;
	for (int i = 1; i <= q; i ++) {
		cin >> a >> b >> c;
		if (a == 1)
			modify (root, c, b);
		else {
			fans = -1;
			query (root, b, c);
			cout << fans << '\n';
		}
	}
	// cerr << "TIME: " << TIME << endl;
	return 0;
}