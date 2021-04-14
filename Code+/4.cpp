#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
int n, m;
ll a[2020];

int point[2020], te = 0;
int mp[2020][2020];
struct e {int to, next;}edge[1000010];
void add (int u, int v) {edge[++ te].to = v, edge[te].next = point[u]; point[u] = te;mp[u][v]=1;}


void build() {
	te = 1;
	memset(point, 0, sizeof point);
	for (int i = 0; i <= n + 1; i ++)
		for (int j = 0; j <= n + 1; j ++)
			mp[i][j] = (i==j);
	for (int i = 1; i <= n; i ++) {
		int id = 0;
		for (int j = 0; j < i; j ++)
			if (a[j] >= a[i])
				id = j;
		add(i, id);
		add(id, i);
		// cerr << "add " << i << " " << id << endl;
		for (int j = i + 1; j <= n + 1; j ++) {
			// cerr << "cmp " << a[i] << " " << a[j] << endl;
			if (a[j] > a[i]) {
				id = j;
				break;
			}
		}
		add (i, id);
		add (id, i);
		// cerr << "add " << i << " " << id << endl;

	}
}

ll ans = 0;
vector <int> cand;
int vis[2020];
map <vector<int>, int> fans;
void dfs (int x, int core, int dis, vector<int> rec) {
	// cerr << "dfs " << x << " (" << core << ") " << dis << endl;
	vis[x] = 1;
	rec.push_back(x);
	if (dis == 5) {
		if (mp[x][core] == 1) {
			sort(rec.begin(), rec.end());
			// cerr << "found " << rec[0] << " " << rec[1] << " " << rec[2] << " " << rec[3] << " " << rec[4] << " " << rec[5] << endl;
			if (!fans[rec]) {
				fans[rec] = 1;
				ans ++;
			}
		}
		vis[x] = 0;
		return ;
	}
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (vis[to])
			continue ;
		dfs (to, core, dis + 1, rec);
	}
	vis[x] = 0;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	a[0] = 1e9;
	a[n + 1] = 1e9;
	cin >> m;
	for (ll x, y, i = 1; i <= m; i ++) {
		ans = 0;
		fans.clear();
		cin >> x >> y;
		a[x] += y;
		build();
		for (int j = 0; j <= n + 1; j ++) {
			vector <int> emp;
			dfs (j, j, 0, emp);
		}
		cout << ans << endl;
	}

	
	return 0;
}