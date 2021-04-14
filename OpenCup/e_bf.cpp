/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 10:31:31
* @description: 
* /Users/jackbai/Desktop/OI/OpenCup/e.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv e_bf.cpp
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
const int maxn = 1e6;
int n, m;
ll fans = 0;
vector <int> adj[maxn];

int dg[maxn], dg2[maxn], sdg[maxn];
int a3[maxn], a3i[maxn];
priority_queue <pii> a3q;


void dg_minus(int x, int dt) {
	dg2[x] -= dt;
	FOR(i, x, n + 1)
		sdg[i] -= dt;
}

int find_sdg (int st, int ed, int val) {
	int pans = 0;
	FOR(i, st, ed + 1)
		pans += (sdg[i] == val);
	return pans;
}
int hp[1000010];

int main() {
	scanf("%d %d", &n, &m);
	F0R(i, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		dg[x] ++, dg[y] ++;
		dg2[max(x, y)] ++;
	}
	FOR(i, 1, n + 1) {
		sort(adj[i].begin(), adj[i].end());
		if (adj[i].size() >= 3)	a3[i] = adj[i][2], a3i[i] = 2;
		else	 	 			a3[i] = n + 1, a3i[i] = adj[i].size();
		a3q.push(MP(-max(i, a3[i]), i));
		sdg[i] = sdg[i - 1] + dg2[i];
	}
	FOR(i, 1, n + 1)
		sdg[i] -= i;


	FOR(i, 1, n + 1) {
		FOR(j, i, n + 1)
			hp[j] = 0;
		int bound = i;
		FOR(j, i + 1, n + 2) {
			bool check = true;
			FOR(k, i, j) {
				int cnt = 0;
				F0R(l, adj[k].size())
					cnt += (adj[k][l] >= i && adj[k][l] < j);
				check &= (cnt <= 2);
			}
			if (!check)
				break;
			bound = j;
		}
		// cout << "find " << -i << " in (" << i << " " << bound << " )" << endl;
		// cout << "bound: " << bound << endl;
		//find the number of i from l to bound-1 such that sdg[i]-2*i==-2*l;
		fans += find_sdg(i, bound - 1, -i);
		// cout << "ans " << i << " : " << find_sdg(i, bound - 1, -i) << endl;

		//delete i's neithbors' a3
		F0R(j, adj[i].size()) {
			int to = adj[i][j];
			if (a3i[to] == adj[to].size())
				continue ;
			a3i[to] ++;
			if (a3i[to] == adj[to].size())
				a3[to] = n + 1;
			else
				a3[to] = adj[to][a3i[to]];
			a3q.push(MP(-max(to, a3[to]), to));
		}
		//delete i's neighbors's dg
		F0R(j, adj[i].size()) {
			int to = adj[i][j];
			if (to > i)
				dg_minus(to, 1);
		}
	}
	cout << fans << endl;
    return 0;
}