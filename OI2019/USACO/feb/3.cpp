#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200020;
typedef long long ll;
typedef pair<int, int> pii;
const long long oo = 1e12;
#define F first
#define S second
int n, T, lyer = 0, C;
pii pt[N];
ll area (pii a, pii b) {return (long long)(a.F - b.F) * (a.S - b.S);}
ll area (int a, int b) {return area(pt[a], pt[b]);}

vector <int> rec[N];
int mn[N];
ll ans[N];

namespace Structure {
	int key[N];
	typedef struct node {
		node *l, *r;
		int st, ed, shed;
		node (node *ll, node *rr, int stt, int edd, int shedd) {
			l = ll, r = rr, st = stt, ed = edd, shed = shedd;
		}
	} *pnode;
	ll find_value (pnode r, int x) {
		if (r->st == r->ed)
			return area(rec[C - 1][r->shed], rec[C][x]) + ans[rec[C - 1][r->shed]];
		return (x >= r->shed ? find_value(r->l, x) : find_value(r->r, x));
	}
	void find_key(pnode root) {
		int l = 0, r = rec[C].size();
		// cout << "init : " << l << " " << r << endl;
		while (l != r) {
			int mid = (l + r) >> 1;
			if (find_value(root->l, mid) <= find_value(root->r, mid)) {
				// cout << "finding " << find_value(root->l, mid) << " " 
					 // << find_value(root->r, mid) << endl;
				r = mid;
			}
			else
				l = mid + 1;
		}
		root->shed = (l + r) >> 1;
		// cout << "find shed : " 
		// << root->st << " " << root->ed << " " << root->shed << endl;
	}
	
	pnode build (int st, int ed) {
		int mid = (st + ed) >> 1;
		if (st == ed) {
			pnode ne = new node(0, 0, st, ed, mid);
			return ne;
		}
		pnode ne = new node(build(st, mid), build(mid + 1, ed), st, ed, 0);
		find_key(ne);
		return ne;
	}

	ll query (pnode r, int st, int ed, int x) {
		if (st <= r->st && r->ed <= ed)
			return find_value(r, x);
		ll pans = oo;
		if (st <= r->l->ed)	pans = min(pans, query(r->l, st, ed, x));
		if (r->r->st <= ed)	pans = min(pans, query(r->r, st, ed, x));
		return pans;
	}

}using namespace Structure;

int find_bound_F(int x) {
	int l = 0, r = rec[C - 1].size() - 1;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		if (pt[rec[C - 1][mid]].F > x)
			r = mid - 1;
		else
			l = mid;
	}
	return l;
}
int find_bound_S(int y) {
	int l = 0, r = rec[C - 1].size() - 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (pt[rec[C - 1][mid]].S > y)
			l = mid + 1;
		else
			r = mid;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	cin >> n >> T;
	for (int i = 1; i <= n; i ++)
		cin >> pt[i].F >> pt[i].S;
	rec[0].push_back(0);
	mn[0] = 0;
	pt[++ n] = make_pair(T, T);
	pt[++ n] = make_pair(0, 0);
	sort(pt + 1, pt + n + 1);
	for (int i = 1; i <= n; i ++) {
		if (!lyer || pt[i].S > pt[mn[lyer]].S) {
			mn[++ lyer] = i;
			rec[lyer].push_back(i);
			continue ;
		}
		int l = 1, r = lyer - 1, p, mid;
		while (l != r) {
			mid = (l + r + 1) / 2;
			(pt[mn[mid]].S > pt[i].S ? r = mid - 1 : l = mid);
		}
		p = l + 1;
		mn[p] = i;
		rec[p].push_back(i);
	}

	// cout << "lyer : " << lyer << endl;
	// for (int i = 1; i <= lyer; i ++) {
	// 	for (int j = 0; j < rec[i].size(); j ++)
	// 		cout << pt[rec[i][j]].F << " " << pt[rec[i][j]].S << ", ";
	// 	cout << endl;
	// }

	for (int i = 2; i <= n; i ++)
		ans[i] = oo;

	for (C = 2; C <= lyer; C ++) {
		if (rec[C - 1].size() < 1e7 / n) {
			for (int i = 0; i < rec[C].size(); i ++)
				for (int j = 0; j < rec[C - 1].size(); j ++) {
					ll cur = area(rec[C - 1][j], rec[C][i]);
					if (cur > 0)
						ans[rec[C][i]] = min(ans[rec[C][i]], ans[rec[C - 1][j]] + cur);
				}
			continue;
		}
		pnode root = build(0, rec[C - 1].size() - 1);
		for (int i = 0; i < rec[C].size(); i ++) {
			int x = rec[C][i];
			int st = find_bound_S(pt[x].S);
			int ed = find_bound_F(pt[x].F);
			// cout << "B : " << st << " " << ed << endl;
			ans[x] = query(root, st, ed, i);
			// cout << "ans for " << pt[x].F << " " << pt[x].S << " : " << ans[x] << endl;
		}
	}
	// for (int i = 1; i <= n; i ++)
	// 	cout << ans[i] << " ";
	// cout << endl;
	cout << ans[n] << endl;
	// cerr << ans[n] << endl;
	return 0;
}