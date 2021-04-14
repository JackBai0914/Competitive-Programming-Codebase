#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;

int n, q, a[500050];

typedef struct node
{
	int st, ed, sum;
	node *l, *r;
	node(int stt, int edd, node *ll, node *rr, int summ)
	{st = stt;   ed = edd;  l = ll;	r = rr;	sum = summ;}
}* pnode;

pnode build(int st, int ed)
{
	if(st == ed){
		pnode ne = new node(st, ed, 0, 0, 0);
		return ne;
	}
	int mid = (st + ed) >> 1;
	pnode ne = new node(st, ed, build(st, mid), build(mid + 1, ed), 0);
	return ne;
}
void update (pnode r) {
	if (!r || !r->l)
		return ;
	r->sum = r->l->sum + r->r->sum;
}

void change(int pos, pnode r)
{
	if (!r)
		return ;
	if(pos <= r->st && r->ed <= pos){
		r->sum ++;
		return;
	}
	if(pos <= r->l->ed)	change(pos, r->l);
	if(r->r->st <= pos)	change(pos, r->r);
	update(r);
}

int ans = -1;
void find (int sum, pnode r) {
	if (r->st == r->ed) {
		if (sum >= r->sum)
			ans = r->st;
		return ;
	}
	if (r->l->sum > sum)
		find (sum, r->l);
	else {
		ans = r->l->ed;
		find (sum - r->l->sum, r->r);
	}	 
}

int calc (int st, int ed, pnode r) {
	if (st <= r->st && r->ed <= ed)
		return r->sum;
	int ans = 0;
	if (st <= r->l->ed)	ans += calc (st, ed, r->l);
	if (r->r->st <= ed)	ans += calc (st, ed, r->r);
	return ans;
}

int app[500050];
vector <int> add[500050];

struct Q {
	int x, y, id, ans;
} qu[500050];
bool ord (Q a, Q b) {
	return (a.x > b.x);
}
bool ord2 (Q a, Q b) {
	return (a.id < b.id);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> q;
	pnode root = build (0, n);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		int dist = i - a[i];
		if (dist < 0 || dist > root->sum) {
			app[i] = -1;
			continue ;
		}
		// cerr << "considering " << i << " : " << dist << endl;
		ans = -1;
		find (root->sum - dist, root);
		ans ++;
		ans = min (ans, i - 1);
		// cerr << "find " << root->sum - dist << " " << ans << endl;
		app[i] = ans;
		change (ans, root);
		add[app[i]].push_back(i);
		// cerr << "change " << ans << endl;
		// cerr << "ending " << i << " : " << dist << " with sum = " << root->sum << endl;
	}
	// for (int i = 1; i <= n; i ++)
		// cout << app[i] << " ";
	// cout << endl;
	for (int i = 1; i <= q; i ++)
		cin >> qu[i].x >> qu[i].y, qu[i].id = i;
	sort (qu + 1, qu + q + 1, ord);
	pnode root2 = build (1, n);
	for (int pt = 1, i = n; i >= 0 && pt <= q; i --) {
		for (int j = 0; j < add[i].size(); j ++)
			change (add[i][j], root2);
		while (pt <= q && qu[pt].x == i) {
			int x = qu[pt].x;
			int y = qu[pt].y;
			qu[pt].ans = calc (x + 1, n - y, root2);
			pt ++;
		}
	}
	sort (qu + 1, qu + q + 1, ord2);
	for (int i = 1; i <= q; i ++)
		cout << qu[i].ans << '\n';
	return 0;
}
