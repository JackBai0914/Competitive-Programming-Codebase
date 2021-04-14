/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 17:09:34
* @description: 
* /Users/jackbai/Desktop/OI/cookoff202010_codechef/c.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv c.cpp
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

int n, eid = 0;
int col[110];

struct Edge {
	int to, nxt;
	Edge() {}
	Edge(int _to, int _nxt) : to(_to), nxt(_nxt) {}
} edges[10000 << 1];
int points[110];
void addE (int st, int ed) {
	eid ++;
	edges[eid].to = ed;
	edges[eid].nxt = points[st];
	points[st] = eid;
}

void dfs (int x, int c) {
	// cerr << "dfs " << x << endl;
	col[x] = c + 1;
	for (int e = points[x]; e; e = edges[e].nxt) {
		int to = edges[e].to;
		// cerr << "from " << x << " try " << to << endl;
		if (col[to])
			continue ;
		dfs (to, c^1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t --) {
		memset(col, 0, sizeof col);
		memset(points, 0, sizeof points);
		eid = 1;
		cin >> n;
		int u, v;
		F0R(i, n - 1) {
			cin >> u >> v;
			addE(u, v);
			addE(v, u);
		}
		dfs (1, 1);
		FOR(i, 1, n + 1) {
			cout << col[i] << ' ';
		}
		cout << endl;
	}

    return 0;
}