/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-14 15:16:42
* @description: 
* /Users/jackbai/Desktop/ER/e.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv e.cpp
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
const ll oo = 1e16;
struct edge {
	int to, next;
	ll val;
} edges[1000010];

int n, m;
int point[500050], te = 1;
ll dis[500050][2][2]; //weither used the coupon
bool vis[500050][2][2];
void add (int a, int b, ll c) {
	edges[++ te].to = b;
	edges[te].val = c;
	edges[te].next = point[a];
	point[a] = te;
}

typedef pair <int, pair <bool, bool> > Ind;

priority_queue <pair<ll, Ind> > q;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		ll x, y, z;
		cin >> x >> y >> z;
		add (x, y, z);
		add (y, x, z);
	}

	for (int i = 1; i <= n; i ++)
		dis[i][0][0] = dis[i][0][1] = dis[i][1][0] = dis[i][1][1] = oo;
	dis[1][0][0] = 0;
	q.push(MP(0, MP(1, MP(0, 0))));

	while (!q.empty()) {
		pair <ll, Ind> tp = q.top();
		int x = tp.S.F;
		bool i1 = tp.S.S.F, i2 = tp.S.S.S;
		ll d = dis[x][i1][i2];
		q.pop();
		if (vis[x][i1][i2])
			continue ;
		// cerr << " : " << x << " " << i1 << " " << i2 << " " << d << endl;
		vis[x][i1][i2] = true;
		for (int e = point[x]; e; e = edges[e].next) {
			int to = edges[e].to;
			if (d + edges[e].val < dis[to][i1][i2]) {
				dis[to][i1][i2] = d + edges[e].val;
				q.push(MP(-dis[to][i1][i2], MP(to, MP(i1, i2))));
			}
			if (i1 == 0)
				if (d + edges[e].val * 2 < dis[to][1][i2]) {
					dis[to][1][i2] = d + edges[e].val * 2;
					q.push(MP(-dis[to][1][i2], MP(to, MP(1, i2))));
				}
			if (i2 == 0)
				if (d < dis[to][i1][1]) {
					dis[to][i1][1] = d;
					q.push(MP(-dis[to][i1][1], MP(to, MP(i1, 1))));
				}
		}
	}

	for (int i = 2; i <= n; i ++)
		cout << min(dis[i][1][1], dis[i][0][0]) << ' ';
	cout << endl;



    return 0;
}