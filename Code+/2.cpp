#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
#define F first
#define S second
#define MP make_pair
const int oo = 1e7;
typedef pair <int, int> pii;
int n, m;
bool mp[100010];
vector<bool> ind[100010];
set <int> ins;

int pt[100010];
vector <pii> fr[100010], ba[100010];

typedef struct node {
	int st, ed, sum;
	node *l, *r;
	node (int stt, int edd, int summ, node *L, node *R) {
		st = stt, ed = edd, sum = summ, l = L, r = R;
	}
} *pnode;
pnode build (int st, int ed) {
	if (st == ed) {
		pnode ne = new node (st, ed, 0, 0, 0);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node (st, ed, 0, build (st, mid), build (mid + 1, ed));
	return ne;
}

void update (pnode r) {
	if (!r || !r->l)
		return ;
	r->sum = r->l->sum + r->r->sum;
}

int query (pnode r, int st, int ed) {
	if (st <= r->st && r->ed <= ed)
		return r->sum;
	int pans = 0;
	if (st <= r->l->ed)	pans += query (r->l, st, ed);
	if (r->r->st <= ed)	pans += query (r->r, st, ed);
	return pans;
}
void modify (pnode r, int p, int v) {
	if (r->st == r->ed) {
		r->sum = v;
		return ;
	}
	if (p <= r->l->ed)	modify(r->l, p, v);
	if (r->r->st <= p)	modify(r->r, p, v);
	update(r);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	pnode root = build (1, n);
	for (int i = 1; i <= n; i ++) {
		ind[i].resize(n/i + 2);
		pt[i] = 0;
		for (int j = 1; j <= n; j += i) {
			int len = min(n, j + i - 1) - j;
			fr[j].push_back(MP(len, i));
			ba[min(n, j + i - 1)].push_back(MP(len, i));
			// cerr << i << " added " << min(n, j + i - 1) << endl;;
		}
	}
	for (int i = 1; i <= n; i ++) {
		sort(fr[i].begin(), fr[i].end());
		sort(ba[i].begin(), ba[i].end());
	}

	ins.insert(0);
	ins.insert(n+1);
	for (int a, b, c, i = 1; i <= m; i ++) {
		cin >> a >> b;
		if (a == 1) {
			if (mp[b])
				continue ;
			mp[b] = 1;
			int ed = *ins.upper_bound(b);
			int st = *(--ins.upper_bound(b));
			ins.insert(b);
			// cerr << st << " " << ed << endl;
			if (b - st < ed - b) {
				for (int j = st + 1; j <= b; j ++)
					for (int k = 0; k < fr[j].size(); k ++) {
						int stp = j, len = fr[j][k].S;
						if (stp + len - 1 < b)
							continue ;
						if (min(n, stp + len - 1) >= ed)
							break;
						// cerr << "eval1 " << (stp - 1) / len + 1 << " " << len << endl;

						ind[len][(stp - 1) / len + 1] = true;
						bool changed = false;
						while (pt[len] != (n - 1) / len + 1 && ind[len][pt[len] + 1] == true) {
							pt[len] ++, changed = true;
							// cerr << "changed " << endl;
						}
						if (changed) {
							modify(root, len, pt[len]);
							// cerr << "mod : " << len << " " << pt[len] << endl;
						}
					}
			}
			else {
				for (int j = ed - 1; j >= b; j --)
					for (int k = 0; k < ba[j].size(); k ++) {
						int edp = j, len = ba[j][k].S;
						int stp = (edp - 1) / len * len + 1;
						// cerr << "occur: " << j << " " << k << " " << ba[j][k] << " " << len << " " << stp << " " << edp << endl;
						if (stp > b)
							continue ;
						if (stp <= st)
							break;
						// cerr << "eval2 " << (edp - 1) / len + 1 << " " << len << endl;

						ind[len][(edp - 1) / len + 1] = true;
						bool changed = false;
						while (pt[len] != (n - 1) / len + 1 && ind[len][pt[len] + 1] == true)
							pt[len] ++, changed = true;
						if (changed) {
							modify(root, len, pt[len]);
							// cerr << "mod : " << len << " " << pt[len] << endl;
						}
						// cerr << "result " << len << "len: " << pt[len] << endl;
					}
			}
		}
		else {
			cin >> c;
			cout << query(root, b, c) + c - b + 1 << endl;
		}
	}

	
	return 0;
}