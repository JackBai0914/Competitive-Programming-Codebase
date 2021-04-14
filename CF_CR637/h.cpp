#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;

typedef struct node {
	int st, ed;
	node *l, *r;
	int sum, v, lazy;
	node (int stt, int edd, node *L, node *R, int summ, int vv, int lazyy) {
		st = stt, ed = edd, l = L, r = R, sum = summ, v = vv, lazy = lazyy;
	}
} *pnode;

void update (pnode r) {
	if (!r || !r->l)
		return ;
	r->sum = r->l->sum + r->r->sum;
}

void down (pnode r) {
	if (!r || !r->l)
		return ;
	if (r->lazy) {
		r->l->lazy += r->lazy;
		r->r->lazy += r->lazy;
		r->l->sum += r->lazy;
		r->r->sum += r->lazy;
		r->lazy = 0;
	}
}

const int mx = 2e6;
int n;
int a[mx];

pnode build (int st, int ed) {
	if (st == ed) {
		pnode ne = new node (st, ed, 0, 0, a[st], a[st], 0);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, build (st, mid), build (mid + 1, ed), 0, 0, 0);
	update (ne);
	return ne;
}


int main() {
	ios::sync_with_stdio(false);



	return 0;
}