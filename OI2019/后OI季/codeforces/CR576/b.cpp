#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;

int n, q;
int ins[200020];
typedef struct node {
	int st, ed;
	node *l, *r;
	int lz, v;
	node (int stt, int edd, int lzz, int vv, node *L, node *R) {
		st = stt, ed = edd, lz = -1, v = vv, l = L, r = R;
	}
} *pnode;
pnode build (int st, int ed) {
	if (st == ed) {
		pnode ne = new node (st, ed, 0, ins[st], 0, 0);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, 0, 0, build (st, mid), build (mid + 1, ed));
	return ne;
}
void down (pnode r) {
	if (!r || !r->l)
		return ;
	if (r->lz != -1) {
		r->l->lz = max (r->l->lz, r->lz);
		r->r->lz = max (r->r->lz, r->lz);
		r->l->v = max (r->l->v, r->lz);
		r->r->v = max (r->r->v, r->lz);
		r->lz = -1;
	}
}

void cover (pnode r, int st, int ed, int v) {
	if (st <= r->st && r->ed <= ed) {
		r->lz = max (r->lz, v);
		r->v = max (r->v, v);
		return ;
	}
	down (r);
	if (st <= r->l->ed)	cover (r->l, st, ed, v);
	if (r->r->st <= ed)	cover (r->r, st, ed, v);
	return ;
}

void modify (pnode r, int p, int v) {
	if (r->st == r->ed) {
		r->v = v;
		return ;
	}
	down (r);
	if (p <= r->l->ed)	modify(r->l, p, v);
	if (r->r->st <= p)	modify(r->r, p, v);
	return ;
}
void order (pnode r) {
	if (r->st == r->ed) {
		cout << r->v << " ";
		return ;
	}
	down (r);
	order(r->l);
	order(r->r);
}


int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> ins[i];
	pnode root = build (1, n);
	cin >> q;
	for (int i = 1; i <= q; i ++) {
		int tp, a, b;
		cin >> tp;
		if (tp == 1) {
			cin >> a >> b;
			modify(root, a, b);
		}
		if (tp == 2) {
			cin >> a;
			cover (root, 1, n, a);
		}
	}
	order(root);
	cout << endl;

	return 0;
}