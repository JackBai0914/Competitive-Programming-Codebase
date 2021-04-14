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

ll dp[33][110][220];
int par[33][110][220];


vector <pair<int, int> > rec;
int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin >> n >> l) {
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
		
		for (int i = 0; i <= l; i ++)
			for (int j = 0; j <= n; j ++)
				for (int k = 0; k <= n; k ++)
					dp[i][j][k] = oo;
		for (int i = 0; i <= n; i ++)
			for (int j = i; j <= n; j ++)
				if (i <= j) {
					dp[l][i][j] = s[i] * l;
					// par[l][i][j] = i;
				}

		ll cur;
		for (int i = l - 1; i >= 0; i --)
			for (int j = 0; j <= n; j ++)
				for (int k = 1; k < j && k <= (1ll << i); k ++) {
					// cerr << ": " << i << " " << j << " " << k << endl;
					if (j == 0) {
						dp[i][j][k] = 0;
						continue ;
					}
					for (int m = 0; m < k; m ++) {
						cur = i * (s[j] - s[j - m]);
						if ((k - m) * 2 >= j - m) {
							if (cur + (i + 1) * (s[j - m]) < dp[i][j][k]) {
								dp[i][j][k] = cur + (i + 1) * (s[j - m]);
								// cerr << "upd with " << m << endl;
								par[i][j][k] = m;
							}
						}
						else {
							if (cur + dp[i + 1][j - m][(k-m)*2] < dp[i][j][k]) {
								dp[i][j][k] = cur + dp[i + 1][j - m][(k-m)*2];
								// cerr << "upd with " << m << endl;

								par[i][j][k] = m;
							}
						}
					}
				}

		int lyer = 0, rem = n, util = 1;
		rec.resize(0);
		// cerr << "done " << endl;
		while (rem) {
			if (util >= rem) {
				rec.push_back (MP(lyer, rem));
				break;
			}
			// cerr << "rem " << rem << endl;
			rec.push_back(MP(lyer, par[lyer][rem][util]));
			int nlyer = lyer + 1, nrem = rem - par[lyer][rem][util], nutil = (util - par[lyer][rem][util]) * 2;
			lyer = nlyer, rem = nrem, util = nutil;
		}
		for (int pt = n, i = 0; i < rec.size(); i ++)
			for (int j = 1; j <= rec[i].S; j ++, pt --)
				ans[b[pt].S] = rec[i].F;
		cout << dp[0][n][1] << endl;
		for (int i = 1; i <= n; i ++)
			cout << ans[i] << ' ';
		cout << endl;
		
	}
	cerr << "TIME: " << TIME << endl;
	return 0;
}