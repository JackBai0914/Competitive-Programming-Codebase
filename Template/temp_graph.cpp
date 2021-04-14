/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @date: 2020-09-24 17:08:30
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv a.cpp -o a 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
 #include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

//loops
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

//debug
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

//constants
const ll mod = 1e9 + 7; // 998244353
const ll oo = 1e18;

namespace GRAPH {
	const int MAXN = 1e6 + 10;
	const int MAXM = 1e6 + 10;

	struct Edge {
		int to, nxt, val;
		Edge() {}
		Edge(int _to, int _nxt, int _val = 1) : to(_to), nxt(_nxt), val(_val) {}
	} edges[MAXM << 1];
	struct Graph {
		int n, m, eid;
		int points[MAXN];
		Graph() {}
		Graph(int _n, int _m) : n(_n), m(_m), eid(1) {}
		void addE (int st, int ed, int val = 1) {
			edges[++eid] = Edge(ed, points[st], val);
			points[st] = eid;
		}
	};
}

int main() {
	ios::sync_with_stdio(false);

	return 0;
}