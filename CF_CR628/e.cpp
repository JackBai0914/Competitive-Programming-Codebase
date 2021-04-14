#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

struct e {
	int to, next;
} edge[20000020];

int point[2000020], te = 1, col[2000020];
map <pair <int, int>, bool> rec;
void add (int u, int v) {
	// cerr << "add " << u << " " << v << endl;
	if (rec[make_pair(u, v)]) {
		cout << 2 << endl;
		exit(0);
	}
	rec[make_pair(u, v)] = true;
	te ++;
	edge[te].to = v;
	edge[te].next = point[u];
	point[u] = te;
}

void decompose (int x) {
	// cerr << x << " : " << endl;
	vector <int> pr;
	for (int i = 2; i * i <= x; i ++)
		if (x % i == 0) {
			int num = 0;
			while (x % i == 0) {
				x /= i;
				num ^= 1;
			}
			if (num != 0)
				pr.push_back (i);
		}
	if (x != 1) {
		pr.push_back(x);
		x = 1;
	}
	if (pr.size() == 0) {
		cout << 1 << endl;
		exit(0);
	}
	if (pr.size() == 1) {
		col[pr[0]] = 1;
	}
	else {
		add (pr[0], pr[1]);
		add (pr[1], pr[0]);
	}
}

int n, fans = 1e9;
int a[2000020];

int mp[1010][1010], con[1010][1010];
int pts[1010], pst = 0;
int id[2000020];
void deal() {
	if (pst < 2)
		return ;
	// for (int i = 1; i <= pst; i ++)
	// 	cerr << pts[i] << " ";
	// cerr << endl;
	for (int i = 1; i <= pst; i ++) {
		for (int j = 1; j <= pst; j ++)
			mp[i][j] = con[i][j] = 1e9;
		mp[i][i] = 0;
	}
	for (int i = 1; i <= pst; i ++)
		for (int e = point[pts[i]]; e; e = edge[e].next) {
			int to = edge[e].to;
			mp[i][id[to]] = mp[id[to]][i] = 1;
			con[i][id[to]] = con[id[to]][i] = 1;
			// cerr << "con " << i << " " << id[to] << endl;
		}
	for (int i = 1; i <= pst; i ++) {
		for (int j = 1; j < i; j ++)
			for (int k = j + 1; k < i; k ++)
				fans = min (fans, mp[j][k] + con[i][j] + con[i][k]);
		for (int j = 1; j <= pst; j ++)
			for (int k = 1; k <= pst; k ++)
				mp[j][k] = min (mp[j][i] + mp[i][k], mp[j][k]);
	}
}

int vis[2000020], dfn[2000020], ti = 0, par[2000020];
void dfs (int x) {
	dfn[x] = ++ ti;
	vis[x] = 1;
	pts[++ pst] = x;
	id[x] = pst;
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if ((e^1) == par[x])
			continue ;
		// cerr << x << " to " << to << " " << vis[to] << endl;
		if (vis[to]) {
			// cerr << ": " << dfn[x] - dfn[to] << endl;
			// fans = min(fans, abs(dfn[x] - dfn[to]) + 1);
			continue ;
		}
		par[to] = e;
		dfs (to);
	}
}

int ink[2000020], dis[2000020];
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		decompose(a[i]);
	}

	for (int i = 1; i <= 1e6 + 10; i ++)
		if (!vis[i]) {
			pst = 0;
			par[i] = -1;
			dfs (i);
			deal();
		}

	memset(ink, 0, sizeof ink);
	memset(dis, 0, sizeof dis);
	for (int i = 1; i <= 1e6 + 10; i ++)
		if (col[i]) {
			ink[i] = i;
			dis[i] = 0;
			q.push(i);
		}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		// cerr << "in: " << x << endl;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			// cerr << "to: " << to << endl;
			if (ink[x] == ink[to])	continue ;
			if (ink[to] != 0) {
				fans = min (fans, dis[x] + dis[to] + 1 + 2);
				// cerr << "UPD: " << dis[x] << " " << dis[to] << endl;
			}		
			else {
				ink[to] = ink[x];
				dis[to] = dis[x] + 1;
				q.push(to);
			}
		}
	}

	cout << (fans == 1e9 ? -1 : fans) << endl;
	return 0;
}
