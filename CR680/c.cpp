/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-01 11:56:02
* @description: 
* /Users/jackbai/Desktop/cf/c.cpp 
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
typedef pair <ll, ll> pll;
const int MOD = 1000000007; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

ll n, m, k;

int num[500050], bel[500050], ban[500050], bst = 0, col[500050];
vector <int> gp[500050];

int point[500050], te = 1;
struct e {int to, next;} edge[2000020];
void add (int u, int v) {edge[++ te].to = v, edge[te].next = point[u]; point[u] = te;}

map <pll, bool> rel;
map <pll, bool> ruined;
vector <pll> deal;

bool ord (pll a, pll b) {
	if (bel[a.F] == bel[b.F])
		return bel[a.F] < bel[b.F];
	return bel[a.S] < bel[b.S];
}

void dfs (int x, int c) {
	col[x] = c;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (col[to]) {
			if (col[to] == col[x]) {
				bst += (ban[bel[x]] == false);
				ban[bel[x]] = true;
			}
			continue ;
		}
		dfs (to, c ^ 1);
	}
}

int rt[2000020];
int get_r(int x) {return (rt[x] == x ? x : rt[x] = get_r(rt[x]));}
map <ll, int> last;

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		cin >> bel[i], num[bel[i]] ++, gp[bel[i]].push_back(i);
	for (int a, b, i = 1; i <= m; i ++) {
		cin >> a >> b;
		if (bel[a] == bel[b]) 	add (a, b), add (b, a);
		else {
			if (bel[a] < bel[b])	deal.push_back(MP(a, b));
			else					deal.push_back(MP(b, a));
		}
	}
	for (int i = 1; i <= n; i ++)
		if (!col[i])
			dfs (i, 2 * i);
	ll fans = bst * k - bst * (bst + 1) / 2, add = 0;
	sort(deal.begin(), deal.end(), ord);

	ll id;
	for (int i = 0; i < deal.size(); i ++) {
		int st = deal[i].F, ed = deal[i].S;
		int rst = bel[st], red = bel[ed];
		int cst = col[st], ced = col[ed];
		pll rep = MP(rst, red);
		id = (rst * (k + 1) + red) * 6 * n;
		if (i == 0 || bel[deal[i].F] != bel[deal[i - 1].F] || bel[deal[i].S] != bel[deal[i - 1].S]) {
			if (num[rst] <= num[red])
				for (int j = 0; j < gp[rst].size(); j ++) {
					rt[col[gp[rst][j]]] = col[gp[rst][j]];
					rt[col[gp[rst][j]] ^ 1] = col[gp[rst][j]] ^ 1;
				}
			if (num[rst] > num[red])
				for (int j = 0; j < gp[red].size(); j ++) {
					rt[col[gp[red][j]]] = col[gp[red][j]];
					rt[col[gp[red][j]] ^ 1] = col[gp[red][j]] ^ 1;
				}
		}
		
		if (ban[rst] || ban[red])
			continue ;
		if (ruined[rep])
			continue ;

		if (num[rst] <= num[red]) {
			if (last.find(id + col[ed]) != last.end()) {
				int lc = last[id + col[ed]];
				cerr << "assign " << col[st] << " to root " << lc << endl;
				rt[get_r(col[st])] = lc;
				rt[get_r(col[st]) ^ 1] = lc ^ 1;
				if (get_r(col[st]) == get_r(col[st] ^ 1)) {
					ruined[rep] = true;
					add ++;
					continue ;
				}
			}
			cerr << "assign last" << col[st] << " " << col[ed] << endl;
			last[id + col[ed]] = col[st];
			last[id + col[ed] ^ 1] = col[st] ^ 1;
		}

		if (num[rst] > num[red]) {
			if (last.find(id + col[st]) != last.end()) {
				int lc = last[id + col[st]];
				rt[get_r(col[ed])] = lc;
				rt[get_r(col[ed]) ^ 1] = lc ^ 1;
				if (get_r(col[ed]) == get_r(col[ed] ^ 1)) {
					ruined[rep] = true;
					add ++;
					continue ;
				}
			}
			last[id + col[st]] = col[ed];
			last[id + col[st] ^ 1] = col[ed] ^ 1;
		}

	}
	cerr << fans << " " << add << endl;
	cout << k * (k - 1) / 2 - fans - add << endl;
    return 0;
}