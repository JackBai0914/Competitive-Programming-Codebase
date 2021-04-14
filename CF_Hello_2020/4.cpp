#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

namespace SegTree {
	typedef struct node {
		node *l, *r;
		ll sum;
		int st, ed;
		int lz;
		node (node *L,node *R, ll summ, int stt, int edd, int lzz) {
			l = L, r = R, sum = summ, st = stt, ed = edd, lz = lzz;
		}
	} *pnode;
	pnode build (int st, int ed) {
		if (st == ed) {
			pnode ne = new node (0, 0, 0, st, ed, 0);
			return ne;
		}
		int mid = (st + ed) >> 1;
		pnode ne = new node (build (st, mid), build (mid + 1, ed), 0, st, ed, 0);
		return ne;
	}
	void update (pnode r) {
		if (!r || !r->l)
			return ;
		r->sum = r->l->sum + r->r->sum;
	}
	void down (pnode r) {
		if (!r || !r->l)
			return ;
		if (r->lz) {
			r->l->lz += r->lz;
			r->r->lz += r->lz;
			r->l->sum += r->lz * (r->l->ed - r->l->st + 1);
			r->r->sum += r->lz * (r->r->ed - r->r->st + 1);
			r->lz = 0;
		}
	}
	void add (int st, int ed, pnode r, int d) {
		// cerr << "add : " << st << " " << ed << " " << r->st << " " << r->ed << endl;
		if (st <= r->st && r->ed <= ed) {
			r->sum += d * (r->ed - r->st + 1);
			r->lz += d;
			return ;
		}
		down (r);
		if (st <= r->l->ed)	add (st, ed, r->l, d);
		if (r->r->st <= ed)	add (st, ed, r->r, d);
		update (r);
	}
	bool if_empty (int st, int ed, pnode r) {
		if (st <= r->st && r->ed <= ed)
			return (r->sum == 0);
		down (r);
		bool if_e = true;
		if (st <= r->l->ed)	if_e &= if_empty(st, ed, r->l);
		if (r->r->st <= ed)	if_e &= if_empty(st, ed, r->r);
		return if_e;
	}
} using namespace SegTree;

int n;
int a[1000010], b[1000010], c[1000010], d[1000010];
vector <pii> ad[500010], de[500010];

int ord[1000010], ost = 0;
map <int, int> m1, m2;

bool ans = true;

priority_queue <int> beg;
priority_queue <int, vector <int>, greater<int> > fin;
int del_b[1000010], del_e[1000010];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++)	cin >> a[i] >> b[i] >> c[i] >> d[i];

	ost = 0;
	for (int i = 1; i <= n; i ++)
		ord[++ ost] = a[i], ord[++ ost] = b[i];
	sort (ord + 1, ord + ost + 1);
	for (int i = 1, j = 0; i <= ost; i ++) {
		if (ord[i] != ord[i - 1])
			j ++;
		m1[ord[i]] = j;
	}
	for (int i = 1; i <= n; i ++)
		a[i] = m1[a[i]], b[i] = m1[b[i]];

	ost = 0;
	for (int i = 1; i <= n; i ++)
		ord[++ ost] = c[i], ord[++ ost] = d[i];
	sort (ord + 1, ord + ost + 1);
	for (int i = 1, j = 0; i <= ost; i ++) {
		if (ord[i] != ord[i - 1])
			j ++;
		m2[ord[i]] = j;
	}
	for (int i = 1; i <= n; i ++)
		c[i] = m2[c[i]], d[i] = m2[d[i]];


	for (int i = 1; i <= n; i ++) {
		ad[a[i]].push_back(MP(c[i], d[i]));
		de[b[i] + 1].push_back(MP(c[i], d[i]));
	}
	for (int i = 1; i <= 2*n + 1; i ++) {
		for (int j = 0; j < de[i].size(); j ++) {
			int st = de[i][j].F, ed = de[i][j].S;
			del_b[st] ++, del_e[ed] ++;
		}
		for (int j = 0; j < ad[i].size(); j ++) {
			int st = ad[i][j].F, ed = ad[i][j].S;
			beg.push(st);
			fin.push(ed);
			while (del_b[beg.top()]) {
				del_b[beg.top()] --;
				beg.pop();
			}
			while (del_e[fin.top()]) {
				del_e[fin.top()] --;
				fin.pop();
			}
			if (!beg.empty())
				if (beg.top() > fin.top()) {
					cout << "NO" << endl;
					return 0;
				}
		}
	}

	while (!beg.empty())	beg.pop();
	while (!fin.empty())	fin.pop();
	memset(del_b, 0, sizeof del_b);
	memset(del_e, 0, sizeof del_e);


	for (int i = 0; i <= 2*n; i ++)
		ad[i].resize(0), de[i].resize(0);
	for (int i = 1; i <= n; i ++) {
		// cerr << i << " :: " << c[i] << " " << d[i] << endl;
		ad[c[i]].push_back(MP(a[i], b[i]));
		de[d[i] + 1].push_back(MP(a[i], b[i]));
	}
	for (int i = 1; i <= 2*n + 1; i ++) {
		for (int j = 0; j < de[i].size(); j ++) {
			int st = de[i][j].F, ed = de[i][j].S;
			del_b[st] ++, del_e[ed] ++;
		}
		for (int j = 0; j < ad[i].size(); j ++) {
			int st = ad[i][j].F, ed = ad[i][j].S;
			beg.push(st);
			fin.push(ed);
			while (del_b[beg.top()]) {
				del_b[beg.top()] --;
				beg.pop();
			}
			while (del_e[fin.top()]) {
				del_e[fin.top()] --;
				fin.pop();
			}
			if (!beg.empty())
				if (beg.top() > fin.top()) {
					cout << "NO" << endl;
					return 0;
				}
		}
	}

	cout << "YES" << endl;
	return 0;
}