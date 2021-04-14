#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll oo = 1e18;

int n, a, b;

typedef struct node {
	int st, ed;
	node *l, *r;
	ll mn;
	node (int stt, int edd, node *ll, node *rr, long long  mnn) {
		st = stt, ed = edd, l = ll, r = rr, mn = mnn;
	}
} *pnode;
pnode build (int st, int ed) {
	if (st == ed) {
		pnode ne = new node (st, ed, 0, 0, oo);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, build (st, mid), build (mid + 1, ed), oo);
	return ne;
}
void update (pnode r) {
	if (!r || !r->l)
		return ;
	r->mn = min(r->l->mn, r->r->mn);
}
void add(pnode r, ll v, int p) {
	if (r->st == r->ed) {
		r->mn = v;
		return ;
	}
	if (p <= r->l->ed)	add (r->l, v, p);
	if (r->r->st <= p)	add (r->r, v, p);
	update (r);
}
ll find_mn (pnode r, int st, int ed) {
	// cerr << "find: " << st << " " << ed << endl;
	if (st <= r->st && r->ed <= ed)
		return r->mn;
	ll ans = oo;
	if (st <= r->l->ed)
		ans = min (ans, find_mn(r->l, st, ed));
	if (r->r->st <= ed)
		ans = min (ans, find_mn(r->r, st, ed));
	return ans;
}



int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> a >> b;
	ll s = 0, v;
	pnode root = build (0, n);
	add (root, 0, 0);
	ll fans = -oo;
	for (int i = 1; i <= n; i ++) {
		cin >> v;
		s += v;
		add (root, s, i);
		// cerr << i << " : " << i - a << " " << i - b << endl;
		if (i - a >= 0)
			fans = max(fans, s - find_mn(root, max(0, i - b), i - a));
	}
	cout << fans << endl;
	return 0;
}
