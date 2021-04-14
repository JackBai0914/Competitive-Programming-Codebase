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
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const ll oo = 1e15;
int n, l;
int a[110];
pair <int, int> b[110];
ll s[110], ans[110];

int ver[33][110][110], V = 0;
ll dp[33][110][110];
int par[33][110][110];
ll dfs (int lyer, int rem, int util) {
	// cerr << "dfs: " << lyer << " " << rem << " " << util << endl;
	if (rem == 0)
		return 0;
	if (lyer > l)
		return oo;

	if (ver[lyer][rem][util] != V) {
		ver[lyer][rem][util] = V;
		dp[lyer][rem][util] = oo;
		par[lyer][rem][util] = -1;
	}


	if (util >= rem) {
		par[lyer][rem][util] = rem;
		return s[rem] * lyer;
	}
	if (dp[lyer][rem][util] != oo)
		return dp[lyer][rem][util];
	ll pans1 = 0;
	ll cand = dfs (lyer + 1, rem, util * 2);
	if (cand < dp[lyer][rem][util]) {
		dp[lyer][rem][util] = cand;
		par[lyer][rem][util] = 0;
	}


	for (int i = 1; i < util; i ++) {
		pans1 += b[rem - i + 1].F * lyer;
		ll cand = dfs (lyer + 1, rem - i, (util - i) * 2);
		if (cand + pans1 < dp[lyer][rem][util]) {
			dp[lyer][rem][util] = cand + pans1;
			par[lyer][rem][util] = i;
		}
	}

	return dp[lyer][rem][util];
}


vector <pair<int, int> > rec;
int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	memset(ver, 0, sizeof ver);
	while (cin >> n >> l) {
		V ++;
		if (n == 0 && l == 0)
			return 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			b[i] = MP(a[i], i);
		}
		sort (b + 1, b + n + 1);
		s[0] = 0;
		for (int i = 1; i <= n; i ++)
			s[i] = s[i - 1] + b[i].F;

		if (n == 1) {
			cout << a[1] << endl << 1 << endl;
			continue ;
		}
		// for (int i = 0; i <= l; i ++)
		// 	for (int j = 0; j <= n; j ++)
		// 		for (int k = 0; k <= n; k ++)
		// 			dp[i][j][k] = oo;
		// memset(par, -1, sizeof par);
		ll fans = dfs (0, n, 1);
		// cerr << "end dfs " << endl;
		
		int lyer = 0, rem = n, util = 1;
		rec.resize(0);
		while (rem) {
			rec.push_back(MP(lyer, par[lyer][rem][util]));
			int nlyer = lyer + 1, nrem = rem - par[lyer][rem][util], nutil = (util - par[lyer][rem][util]) * 2;
			lyer = nlyer, rem = nrem, util = nutil;
		}
		for (int pt = n, i = 0; i < rec.size(); i ++)
			for (int j = 1; j <= rec[i].S; j ++, pt --)
				ans[b[pt].S] = rec[i].F;
		cout << fans << endl;
		for (int i = 1; i <= n; i ++)
			cout << ans[i] << ' ';
		cout << endl;
		
	}
	cerr << "TIME: " << TIME << endl;
	return 0;
}