/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-12 09:58:40
* @description: 
* /Users/jackbai/Desktop/Template/graph.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv graph.cpp
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

const int MAXN = 1e6 + 10;
const int MAXM = 2e6 + 10;
struct e {
	int to, next;
	e () {}
	e (int _to, int _next) {
		to = _to;
		next = _next;
	}
} edges[MAXM << 1];
int n, m, point[MAXN], te = 1;
void add (int u, int v) {edges[++ te] = e(v, point[u]); point[u] = te;}

void dfs (int x) {
	for (int e = point[x]; e; e = edges[e].next) {
		int to = edges[e].to;
	}
}


int main() {


    return 0;
}