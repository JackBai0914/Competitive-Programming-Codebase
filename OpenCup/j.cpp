/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 09:24:11
* @description: 
* /Users/jackbai/Desktop/OI/OpenCup/j.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv j.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, q;
pii balls[1000010];
pii ops[1000010];
map <char, pii> dir;

typedef struct node {
	pii pos;
	int ti;
	vector <int> b;
	node() {ti = 0;}
	node(int _ti) {ti = _ti;}
} *pnode;
pnode nd[1000010];
pnode combine(pnode x, pnode y, pii pos, int ti) {
	// cerr << x << " " << y << endl;
	if (x == 0 && y == 0)	return 0;
	if (x == 0)	{y->pos = pos, y->ti = ti; return y;}
	if (y == 0)	{x->pos = pos, x->ti = ti; return x;}
	if (x->b.size() < y->b.size())
		return combine(y, x, pos, ti);
	for (int i = 0; i < y->b.size(); i ++) {
		int c = y->b[i];
		x->b.push_back(c);
	}
	x->pos = pos;
	x->ti = ti;
	return x;
}

map <pii, pnode> mp;
pii ans[1000010];

int main() {
	dir['L'] = MP(-1, 0);
	dir['R'] = MP(+1, 0);
	dir['D'] = MP(0, -1);
	dir['U'] = MP(0, +1);
	string s;
	scanf("%d", &n);
	cin >> s;
	FOR(i, 1, n + 1) {
		ops[i] = dir[s[i - 1]];
		// cerr << "dir: " << ops[i].F << " " << ops[i].S << endl;
	}
	scanf("%d", &q);
	FOR(i, 1, q + 1) {
		scanf("%d %d", &balls[i].F, &balls[i].S);
		balls[i].F *= -1;
		balls[i].S *= -1;
		if (mp.count(balls[i]) == 0) {
			mp[balls[i]] = new node(0);
			mp[balls[i]]->pos = balls[i];
		}
		mp[balls[i]]->b.push_back(i);
	}

	pii cp = MP(0, 0); 
	FOR(i, 1, n + 1) {
		pii nxt = MP(cp.F + ops[i].F, cp.S + ops[i].S);
		pii push = MP(nxt.F + ops[i].F, nxt.S + ops[i].S);
		if (mp.count(nxt)) {
			pnode ne = combine(mp[nxt], mp[push], push, i);
			mp.erase(nxt);
			mp[push] = ne;
		}
		cp = nxt;
	}
	// cerr << "end2 " << endl;
	map<pii, pnode>::iterator iter;
	for (iter = mp.begin(); iter != mp.end(); iter ++) {
		if (iter->S == 0)
			continue ;
		vector <int> b = iter->S->b;
		pii pos = iter->F;
		for (int i = 0; i < b.size(); i ++)
			ans[b[i]] = pos;
	}
	FOR(i, 1, q + 1) {
		printf("%d %d\n", cp.F - ans[i].F, cp.S - ans[i].S);
	}
    return 0;
}