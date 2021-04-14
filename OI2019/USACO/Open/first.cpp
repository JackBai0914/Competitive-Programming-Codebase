#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "grader.h"
#define F first
#define S second
#define MP make_pair
using namespace std;

int n, q;
int point[100010], te = 0;
vector <int> sons[100010];
struct e {int to, next;} edge[200020];

void add  (int a, int b) {
	te ++;
	edge[te].to = b;
	edge[te].next = point[a];
	point[a] = te;
}

void addRoad(int a, int b){
	a ++, b ++;
	add (a, b);
	add (b, a);
}

int par[100010], dep[100010], num[100010], desc[100010], top[100010];

void build (int x) {
	num[x] = 1;
	int mx = 0;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x])
			continue ;
		sons[x].push_back(to);
		dep[to] = dep[x] + 1;
		par[to] = x;
		build (to);
		num[x] += num[to];
		if (num[to] > mx) {
			mx = num[to];
			desc[x] = to;
		}
	}
}
void link (int x, int tp) {
	top[x] = tp;
	if (desc[x])
		link (desc[x], tp);
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (to == par[x] || to == desc[x])
			continue ;
		link (to, to);
	}
}

void find_lca(int a, int b, int &ra, int &rb, int &lca) {
	while (top[a] != top[b]) {
		if (dep[top[a]] > dep[top[b]]) {
			ra = top[a];
			a = par[top[a]];
		}
		else {
			rb = top[b];
			b = par[top[b]];
		}
	}
	if (dep[a] > dep[b]) {
		lca = b;
		ra = -1;
	}
	else {
		lca = a;
		rb = -1;
	}
}

int sq[100010];
int v[100010], fs[100010], bs[100010];
typedef pair<int, int> pii;
pii pos[100010], drift[100010];

void dfs1 (int x) {
	sq[x] = 1;
	for (int i = 0; i < sons[x].size(); i ++) {
		int to = sons[x][i];
		dfs1 (to);
		sq[x] += sq[to];
	}
	for (int i = 0; i < sons[x].size(); i ++)
		v[i] = sq[sons[x][i]];
	fs[0] = v[0];
	bs[sons[x].size()] = 0;
	for (int i = 1; i < sons[x].size(); i ++)
		fs[i] = fs[i - 1] + v[i];
	for (int i = sons[x].size() - 1; i >= 0; i --)
		bs[i] = bs[i + 1] + v[i];
	for (int i = 0; i < sons[x].size(); i ++) {
		int to = sons[x][i];
		drift[to] = MP((i ? fs[i - 1] : 0) + 1, bs[i + 1] + 1);
	}
}

pii cur;
void dfs2 (int x) {
	cur.F += drift[x].F;
	cur.S += drift[x].S;
	pos[x] = cur;
	for (int i = 0; i < sons[x].size(); i ++) {
		int to = sons[x][i];
		dfs2 (to);
	}
	cur.F -= drift[x].F;
	cur.S -= drift[x].S;
}

void notify (int a, int b) {
	// cout << "addBox : " << pos[a].F << " " <<  pos[a].S << " "
						// << pos[b].F << " " <<  pos[b].S << endl;
	addBox (pos[a].F, pos[a].S, pos[b].F, pos[b].S);
}

void buildFarms(){
	n = getN();
	q = getQ();
	// cin >> n >> q;
	// for (int a, b, i = 1; i < n; i ++) {
		// cin >> a >> b;
		// addRoad (a, b);
	// }
	build (1);
	link (1, 1);
	dfs1(1);
	cur = MP(1, 1);
	dfs2(1);
	for (int i = 1; i <= n; i ++) {
		// cout << "setFarmLocation " << i - 1 << " "
			 // << pos[i].F << " " << pos[i].S << endl;
		setFarmLocation (i - 1, pos[i].F, pos[i].S);
	}
	/*
	for (int a, b, i = 1; i <= q; i ++) {
		cin >> a >> b;
		a ++, b ++;
		int ra = 0, rb = 0, lca = 0;
		find_lca(a, b, ra, rb, lca);
		if (lca == a)		notify (a, b);
		else if (lca == b)	notify (b, a);
		else if (~ra)		notify (ra, a), notify (lca, b);
		else				notify (rb, b), notify (lca, a);
	}
	*/
	// for (int i = 1; i <= n; i ++)
		// cout << " : " << i << " " << top[i] << " " << par[i] << endl;
}
void notifyFJ(int a, int b){
	a ++, b ++;
	int ra = 0, rb = 0, lca = 0;
	find_lca(a, b, ra, rb, lca);
	if (lca == a)		notify (a, b);
	else if (lca == b)	notify (b, a);
	else if (~ra)		notify (ra, a), notify (lca, b);
	else				notify (rb, b), notify (lca, a);
}