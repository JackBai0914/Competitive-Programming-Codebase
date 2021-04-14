/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-02 15:10:36
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
typedef pair <ll, ll> pii;
const int mod = 998244353; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n, m;
struct e {int to, next; bool rev;} edge[5000050];
int point[1000010], te = 0;
void add (int u, int v, bool r) {edge[++ te].to = v, edge[te].next = point[u]; point[u] = te; edge[te].rev = r;}


struct Dis {
	ll turn, dis;
	Dis() 			{turn = 0, dis = 0;}
	Dis(ll x, ll y)	{turn = x, dis = y;}
};
Dis dis[200020][30];
ll mi2[30], s2[30];

bool operator < (const Dis &x, const Dis &y) {
	if (x.turn > 20 || y.turn > 20)	return (x.turn == y.turn ? x.dis > y.dis : x.turn > y.turn);
	return x.dis + s2[x.turn] > y.dis + s2[y.turn];
}



priority_queue <pair<Dis, pii> > q;
bool if_vis[200020][30];

ll realize (Dis x) {
	ll a1 = 1, s1 = 1;
	if (x.turn == 0) {
		return (x.dis + mod) % mod;
	}
	for (int i = 1; i < x.turn; i ++) {
		(a1 *= 2) %= mod;
		(s1 += a1) %= mod;
	}

	return (x.dis + s1 + mod) % mod;
}

int rep (int x) {
	if (x >= 20)
		return 20 + x % 2;
	else
		return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int a, b, i = 1; i <= m; i ++) {
		cin >> a >> b;
		add (a, b, 0);
		add (b, a, 1);
	}
	for (int i = 0; i <= 24; i ++) {
		mi2[i] = (1ll << i);
		s2[i + 1] = s2[i] + mi2[i];
	}

	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < 25; j ++)
			dis[i][j] = Dis(1000000, 1000000);

	dis[1][0] = Dis(0, 0);
	dis[1][1] = Dis(1, 0);
	q.push(MP(dis[1][0], MP(1, 0)));
	q.push(MP(dis[1][1], MP(1, 1)));
	while (!q.empty()) {
		pair <Dis, pii> tp = q.top();
		int x = tp.S.F, ti = tp.S.S;
		Dis d = tp.F;
		q.pop();
		if (if_vis[x][ti])
			continue ;
		// cout << "vis : " << x << " " << ti << " " << d.turn << " " << d.dis << " " << realize(d) << endl;
		if (x == n) {
			cout << realize(d) << endl;
			return 0;
		}
		if_vis[x][ti] = true;


		Dis flip = Dis(d.turn + 1, d.dis);
		if (dis[x][rep(ti + 1)] < flip) {
			dis[x][rep(ti + 1)] = flip;
			q.push(MP(dis[x][rep(ti + 1)], MP(x, rep(ti + 1))));
		}

		Dis nxt;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			nxt = Dis(d.turn, d.dis + 1);
			// cerr << "pre: " << to << " " << edge[e].rev << " " << ti  << endl;
			if (edge[e].rev == ti % 2) {
				// cerr << "find: " << to << endl;
				if (dis[to][ti] < nxt) {
					dis[to][ti] = nxt;
					q.push(MP(dis[to][ti], MP(to, ti)));
				}
			}
		}
	}
	
    return 0;
}