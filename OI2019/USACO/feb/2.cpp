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
int point[2020], te = 1;
struct edge{int to, next, v;} edge[3030];
void add (int u, int v, int w) {
	te ++;
	edge[te].to = v;
	edge[te].v = w;
	edge[te].next = point[u];
	point[u] = te;
}
vector <int> num, pt[2020];
ll S[2020], N[2020];

namespace Graph {
	int k = 0;
	int flag[2020];
	ll mp[2020][2020];
	void dfs(int x) {
		// cout << "traverse : " << x << endl;
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

ll all = 1, ept = 0, ans, ad = 0;
ll dp[3030], hp[3030], hp2[3030];
int lim;

int main() {
	ios::sync_with_stdio(false);
	freopen("mooriokart.in", "r", stdin);
	freopen("mooriokart.out", "w", stdout);
	cin >> n >> m >> x >> y;
	for (int a, b, c, i = 1; i <= m; i ++) {
		cin >> a >> b >> c;
		add (a, b, c);
		add (b, a, c);
	}
	work();
	lim = y - x * k - 1;
	dp[0] = 1;
	for (int i = 1; i <= k; i ++) {
		memset(hp, 0, sizeof hp);
		memset(hp2, 0, sizeof hp2);
		for (int a = 0; a < num[i]; a ++)
			for (int b = 0; b < num[i]; b ++)
				if (a != b && mp[pt[i][a]][pt[i][b]] <= lim)
					hp[mp[pt[i][a]][pt[i][b]]] ++;
		for (int a = 0; a <= lim; a ++)
			if (hp[a])
				for (int b = lim - a; b >= 0; b --)
					(hp2[b + a] += dp[b] * hp[a] % mod) %= mod;
		for (int a = 0; a <= lim; a ++) {
			dp[a] = hp2[a];
			// cout << a << " : " << dp[a] <<endl;
		}
		// cout << endl;
		ll p = 0;
		for (int a = 0; a < num[i]; a ++)
			for (int b = 0; b < num[i]; b ++) {
				(p += mp[pt[i][a]][pt[i][b]]) %= mod;
				// cout << "contri : " << pt[i][a] << " " << pt[i][b] << " " << mp[pt[i][a]][pt[i][b]] << endl;
			}
		S[i] = p % mod;
		N[i] = num[i] * (num[i] - 1) % mod;
		// cout << i << " : " << S[i] << " " << N[i] << endl;
	}
	all = x * k;
	for (int i = 1; i <= k; i ++)
		(all *= N[i]) %= mod;
	// cout << "A: " << all << endl;
	for (int i = 1; i <= k; i ++) {
		ll pans = S[i];
		for (int j = 1; j <= k; j ++)
			if (i != j)
				(pans *= N[j]) %= mod;
		(all += pans) %= mod;
		// cout << "A: " << all << endl;
	}
	for (int i = 0; i <= lim; i ++)
		(ept += dp[i] * (i + x * k)) %= mod;
	ans = (all - ept + mod) % mod;
	for (int i = 1; i < k; i ++)
		(ans *= i) %= mod;
	// cout << ans << " " << ept << " " << all << endl;
	(ans % 2 ? ans = (ans + mod) / 2 : ans /= 2);
	cout << ans << endl;
	return 0;
}