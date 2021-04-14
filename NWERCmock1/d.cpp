/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-26 21:59:57
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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
const int mod = 1000000007; 
const ll oo = 1e16;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

ll a, b;
int n, m;

int point[100010], ipoint[100010], te = 1, ite = 1;
struct e {int to, next; ll v; bool qua;} edge[100010], iedge[100010];
void add (int u, int v, int w) {
	te ++;
	edge[te].to = v;
	edge[te].v = w;
	edge[te].next = point[u];
	point[u] = te;
}
void iadd (int u, int v, int w) {
	ite ++;
	iedge[ite].to = v;
	iedge[ite].v = w;
	iedge[ite].next = ipoint[u];
	ipoint[u] = ite;
}
ll dis[2][100010];
namespace Dijkstra {
	bool vis[100010];
	priority_queue <pair <ll, int> > q;
	void main() {
		for (int i = 1; i <= n; i ++)
			dis[0][i] = dis[1][i] = oo;

		memset(vis, 0, sizeof(vis));
		dis[0][1] = 0;
		q.push(MP(0, 1));
		while (!q.empty()) {
			int x = q.top().S;
			q.pop();
			if (vis[x])
				continue ;
			vis[x] = true;
			for (int e = point[x]; e; e = edge[e].next) {
				int to = edge[e].to;
				if (dis[0][to] > dis[0][x] + edge[e].v) {
					dis[0][to] = dis[0][x] + edge[e].v;
					q.push(MP(-dis[0][to], to));
				}
			}
		}

		memset(vis, 0, sizeof(vis));
		dis[1][n] = 0;
		q.push(MP(0, n));
		while (!q.empty()) {
			int x = q.top().S;
			q.pop();
			if (vis[x])
				continue ;
			vis[x] = true;
			for (int e = ipoint[x]; e; e = iedge[e].next) {
				int to = iedge[e].to;
				if (dis[1][to] > dis[1][x] + iedge[e].v) {
					dis[1][to] = dis[1][x] + iedge[e].v;
					q.push(MP(-dis[1][to], to));
				}
			}
		}
	}
}

queue <int> q;
bool qua[100010];
ll longest;
ll deep[100010];
bool vis[100010];
bool in_s[100010];
void dfs (int x) {
	if (longest == oo)
		return ;
	in_s[x] = true;
	vis[x] = true;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (!edge[e].qua)
			continue ;
		if (!qua[to])
			continue ;
		if (in_s[to]) {
			longest = oo;
			in_s[x] = false;
			return ;
		}
		if (!vis[to])
			dfs (to);
		deep[x] = max (deep[x], deep[to] + edge[e].v);
	}
	in_s[x] = false;
}
bool check (ll mx) {
	longest = 0;
	// cerr << "checking " << mx << endl;
	memset(qua, false, sizeof (qua));
	for (int i = 0; i <= te; i ++)
		edge[i].qua = false;
	for (int i = 1; i <= n; i ++)
		if (dis[0][i] + dis[1][i] <= a + mx)
			q.push(i);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (qua[x] == true)
			continue ;
		qua[x] = true;
		// cerr << "qua: " << x << endl;

		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (edge[e].v + dis[1][to] <= mx) {
				edge[e].qua = true;
				// cerr << "qua: " << x << " " << to << endl;
				q.push(to);
			}
		}
	}
	if (!qua[1])
		return false;
	memset(deep, 0, sizeof deep);
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i ++)
		if (dis[0][i] + dis[1][i] <= a + mx && !vis[i])
			dfs (i);
	for (int i = 1; i <= n; i ++)
		if (dis[0][i] + dis[1][i] <= a + mx) {
			// cerr << i << " : " << (a + mx - (dis[0][i] + dis[1][i])) << " " << dis[0][i] << " " << deep[i] << endl;
			longest = max (longest, (a + mx - (dis[0][i] + dis[1][i])) + dis[0][i] + deep[i]);
		}
	// cerr << "longest: " << longest << " " << b << " " << (b <= longest) << endl;
	return (b <= longest);
}


int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    cin >> n >> m;
    for (int u, v, w, i = 1; i <= m; i ++) {
    	cin >> u >> v >> w;
    	add (u, v, w);
    	iadd (v, u, w);
    }
	Dijkstra::main();
	// for (int i = 1; i <= n; i ++)
		// cerr << i << " : " << dis[0][i] << " " << dis[1][i] << endl; 

    ll l = 0, r = oo;
    while (l < r) {
    	ll mid = (l + r) >> 1;
    	if (check(mid))	r = mid;
    	else	   		l = mid + 1;
    }
    cout << min(dis[0][n], l) << endl;
    return 0;
}