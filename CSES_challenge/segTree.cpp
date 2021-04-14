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

typedef struct node {
	int st, ed;
	node *l, *r;
	int sum;
	node (int stt, int edd, node *ll, node *rr, int summ) {
		st = stt, ed = edd, l = ll, r = rr, sum = summ;
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
}
void add(pnode r, int v, int p) {
	if (r->st == r->ed) {
		r->sum += v;
		return ;
	}
	if (p <= r->l->ed)	add (r->l, v, p);
	if (r->r->st <= p)	add (r->r, v, p);
	update (r);
}
int find_m (pnode r, int rk) {
	if (r->st == r->ed)
		return r->st;
	if (r->l->sum >= rk)
		return find_m(r->l, rk);
	else
		return find_m(r->r, rk - r->l->sum);
}

int n, k;
int a[1000010];

int id[1000010];
int itr[1000010];
map <int, int> tr;


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
			cout << itr[find_m(root, (k + 1) / 2)] << ' ';
		}
	}
	cout << endl;

	return 0;
}
