#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
using namespace std;

int n, k, L, R;
int v[500050], s[500050];

namespace SegTree {
	typedef struct node {
		int st, ed;
		node *l, *r;
		int num;
		node() {}
		node (int stt, int edd, node *L, node *R, int numm) {
			st = stt, ed = edd, l = L, r = R, num = numm;
		}
	} *pnode;
	pnode duplicate (pnode r) {
		pnode ne = new node();
		*ne = *r;
		return ne;
	}
	pnode add (pnode ol, int pos) {
		r = duplicate(ol);
		if (r->st == r->ed) {
			r->num ++;
			return r;
		}
		int mid = (r->st + r->ed) >> 1;
		if (!r->l)	r->l = new node (r->st, mid, 0, 0, 0);
		if (!r->r)	r->r = new node (mid + 1, r->ed, 0, 0, 0);
		r->num ++;
		if (pos <= r->l->ed)	add (r->l, pos);
		if (r->r->st <= pos)	add (r->r, pos);
		return r;
	}

	int find_k (pnode r, int k) {
		if (!r)
			return -1;
		// cerr << r->st << " " << r->ed << ": " << r->num << " " << k << endl;
		if (r->st == r->ed)
			return r->st;
		if (k <= r->l->num)	return find_k(r->l, k);
		if (k > r->l->num)	return find_k(r->r, k - r->l->num);
	}
}using namespace SegTree;




int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> L >> R;
	for (int i = 1; i <= n; i ++)
		cin >> v[i], s[i] = s[i - 1] + v[i];

	

	return 0;
}