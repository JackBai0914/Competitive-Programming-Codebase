#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m, q;
struct e {int st, ed, next, val;};
struct e2 {int a, b, c; e2(){}e2(int aa, int bb, int cc){a = aa, b = bb, c = cc;}}edge2[1000010];
bool ord (e2 x, e2 y) {
	return x.c < y.c;
}


int ban, targ;
int par[501];
int len[501][501][501];
namespace MST{
	int rt[1010];
	vector <int> es;
	int get_rt(int r) {return (r == rt[r] ? r : rt[r] = get_rt(rt[r]));}
	void set_rt(int r, int s) {rt[get_rt(s)] = r;}
	void init() {
		for (int i = 1; i <= n; i ++)
			rt[i] = i;
		es.resize(0);
	}
	void work() {
		init();
		for (int i = 1; i <= m; i ++) {
			int st = edge2[i].a;
			int ed = edge2[i].b;
			if (st == ban || ed == ban)
				continue ;
			if (get_rt(st) == get_rt(ed))
				continue ;
			set_rt(st, ed);
			es.push_back(i);
			cerr << "ban " << ban << " adde " << st << " " << ed << endl;
		}
	}
}

vector <int> mst[1010]; 



void sp_add (int a, int b, int v) {
	sp_te[ban] ++;
	sp_edge[ban][sp_te[ban]].next = sp_point[ban][a];
	sp_edge[ban][sp_te[ban]].val = v;
	sp_edge[ban][sp_te[ban]].st = a;
	sp_edge[ban][sp_te[ban]].ed = b;
	sp_point[ban][a] = sp_te[ban];
}

void dfs (int x) {
	for (int e = sp_point[ban][x]; e; e = sp_edge[ban][e].next) {
		int to = sp_edge[ban][e].ed;
		if (to == par[ban][x])
			continue ;
		par[ban][to] = x;
		pv[ban][to] = sp_edge[ban][e].val;
		dep[ban][to] = dep[ban][x] + 1;
		dfs (to);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int a, b, c, i = 1; i <= m; i ++) {
		cin >> a >> b >> c;
		edge2[i] = e2(a, b, c);
	}
	sort(edge2 + 1, edge2 + m + 1, ord);
	for (int i = 1; i <= n; i ++) {
		ban = i;
		for (int tg = 1; tg = n; tg ++)  {
			targ = tg;
			MST::work();
		}
	}
	for (int i = 1; i <= q; i ++) {
		int u, v, s, ans = 0;
		cin >> u >> v >> s;
		ban = s;
		targ = v;
		
	}


	
	return 0;
}