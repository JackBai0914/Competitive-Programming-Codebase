#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
int n, m, x, y;
int point[200020], te = 1;
struct edge{int to, next, v;} edge[200020];
void add (int u, int v, int w) {
	te ++;
	edge[te].to = v;
	edge[te].v = w;
	edge[te].next = point[u];
	point[u] = te;
}
vector <int> num, pt[200020];
ll S[200020], N[200020];

namespace Graph {
	int k = 0;
	int flag[200020];
	ll mp[2020][2020];
	void dfs(int x) {
		flag[x] = k;
		pt[k].push_back(x);
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (!flag[to])
				dfs(to);
		}
	}
	void dfs_dis(int x, int dis, int rt) {
		mp[rt][x] = dis;
		for (int e = point[x]; e; e = edge[e].next) {
			int to = edge[e].to;
			if (mp[rt][to] == -1)
				dfs_dis(to, dis + edge[e].v, rt);
		}
	}
	void work() {
		num.resize(n);
		memset(mp, -1, sizeof mp);
		for (int i = 1; i <= n; i ++) {
			if (!flag[i]) {
				// cout << "find : " << i << endl;
				k ++;
				dfs(i);
				num[k] = pt[k].size();
			}
			dfs_dis(i, 0, i);
		}
	}
} using namespace Graph;

ll fans = 0;

void dfs(int id, int pans) {
	if (id == k + 1) {
		pans += k * x;
		if (pans >= y)
			fans += pans;
		return ;
	}
	for (int i = 0; i < num[id]; i ++)
		for (int j = 0; j < num[id]; j ++) {
			int x = pt[id][i];
			int y = pt[id][j];
			if (x == y)
				continue ;
			pans += mp[x][y];
			dfs(id + 1, pans);
			pans -= mp[x][y];
		}
}

int main() {
	ios::sync_with_stdio(false);
	freopen("mooriokart.in", "r", stdin);
	freopen("force.out", "w", stdout);
	cin >> n >> m >> x >> y;
	for (int a, b, c, i = 1; i <= m; i ++) {
		cin >> a >> b >> c;
		add (a, b, c);
		add (b, a, c);
	}
	work();
	dfs(1, 0);
	fans /= 2;
	for (int i = 1; i < k; i ++)
		(fans *= i) %= mod;
	cout << fans % mod << endl;
	return 0;
}