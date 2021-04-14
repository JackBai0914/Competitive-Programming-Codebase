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

ll id[1000010];
ll itr[1000010];
map <ll, ll> tr;

typedef struct node {
	int st, ed;
	node *l, *r;
	ll sum;
	ll val;
	node (int stt, int edd, node *ll, node *rr, long long summ) {
		st = stt, ed = edd, l = ll, r = rr, sum = summ; val = 0;
	}
} *pnode;
pnode build (int st, int ed) {
	if (st == ed) {
		pnode ne = new node (st, ed, 0, 0, 0);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, build (st, mid), build (mid + 1, ed), 0);
	return ne;
}
void update (pnode r) {
	if (!r || !r->l)
		return ;
	r->sum = r->l->sum + r->r->sum;
	r->val = r->l->val + r->r->val;
}
void add(pnode r, ll v, int p) {
	if (r->st == r->ed) {
		r->sum += v;
		r->val += v * itr[p];
		// cerr << "add: " << v << " * " << itr[p] << endl;
		return ;
	}
	if (p <= r->l->ed)	add (r->l, v, p);
	if (r->r->st <= p)	add (r->r, v, p);
	update (r);
}
ll find_m (pnode r, int rk) {
	if (r->st == r->ed)
		return r->st;
	if (r->l->sum >= rk)
		return find_m(r->l, rk);
	else
		return find_m(r->r, rk - r->l->sum);
}
ll collect (pnode r, ll m) {
	if (r->st == r->ed)
		return 0;
	if (m <= r->l->ed)
		return collect (r->l, m) + r->r->val - r->r->sum * itr[m];
	else
		return collect (r->r, m) + r->l->sum * itr[m] - r->l->val;
}

int n, k;
ll a[1000010];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		id[i] = a[i];
	}
	sort (id + 1, id + n + 1);
	for (int i = 1, j = 0; i <= n; i ++) {
		if (id[i] != id[i - 1])
			j ++;
		tr[id[i]] = j;
		itr[j] = id[i];
	}
	for (int i = 1; i <= n; i ++)
		a[i] = tr[a[i]];

	pnode root = build (1, n);
	for (int i = 1; i <= n; i ++) {
		add (root, 1, a[i]);
		if (i > k) {
			add (root, -1, a[i - k]);
		}
		if (i >= k) {
			int m = find_m(root, (k + 1) / 2);
			// cout << "M: " << m << endl;
			cout << collect (root, m) << ' ';
		}
	}
	cout << endl;

	return 0;
}
