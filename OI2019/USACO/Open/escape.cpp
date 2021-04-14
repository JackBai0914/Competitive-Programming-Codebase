#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#define TIME (double)clock()/CLOCKS_PER_SEC 
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
int n, k;
int vert[30030][7], hori[7][30030];

namespace Status {
	int stat[300], stnum = 0;
	int istat[10000];
	struct Hex {int a[6]; Hex(){memset(a, 0, sizeof a);}};
	void output (Hex x) {
		for (int i = 0; i < k; i ++)
			cout << x.a[i] << " ";
		cout << endl;
	}
	void order (Hex &x) {
		int mp[10];
		memset(mp, -1, sizeof mp);
		int st = 0;
		for (int i = 0; i < k; i ++) {
			if (mp[x.a[i]] == -1)
				mp[x.a[i]] = st ++;
			x.a[i] = mp[x.a[i]];
		}
	}
	int code (Hex x) {
		int ans = 0; 
		for (int i = 0; i < k; i ++) 
			ans = ans * k + x.a[i];
		return ans;
	}
	Hex decode (int x) {
		Hex ans;
		for (int i = k - 1; i >= 0; i --, x /= k)
			ans.a[i] = x % k;
		return ans;
	}
	Hex cur;
	void dfs (int x, int tpnum) {
		if (x == k) {
			int msk = code (cur);
			stat[++ stnum] = msk;
			istat[msk] = stnum;
			// for (int i = 0; i < k; i ++)
				// cout << cur.a[i] << " ";
			// cout << msk << endl;
			return ;
		}
		for (int i = 0; i <= tpnum + 1; i ++) {
			cur.a[x] = i;
			dfs (x + 1, max(tpnum, i));
		}
	}
} using namespace Status;

namespace Trans {
	struct e {
		int to;
		bool e1, e2;
		e () {}
		e (int too, bool e11, bool e22) 
		{to = too; e1 = e11, e2 = e22;}
	};
	vector <e> tr[6][300];
	namespace CombineSet {
		int rt[6];
		int num[6];
		int get_r(int x){return (x == rt[x] ? x : rt[x] = get_r(rt[x]));}
		void ini ()	{for (int i = 0; i < k; i ++) rt[i] = i, num[i] = 1;}
		void trans (Hex x){
			ini ();
			for (int i = 1; i < k; i ++)
				for (int j = i - 1; j >= 0; j --)
					if (x.a[i] == x.a[j]) {
						get_r(i);
						get_r(j);
						if (rt[i] == rt[j])
							continue ;
						num[rt[j]] += num[rt[i]];
						num[rt[i]] = 0;
						rt[rt[i]] = rt[j];
						break;
					}
		}
	} using namespace CombineSet;
	int ist = 0, mk[20];
	void search (int Msk, int p) {
		Hex info = decode(Msk);
		trans(info);
		if (p == 0) {
			tr[p][istat[Msk]].push_back(e(istat[Msk], 1, 0));
			if (num[get_r(0)] > 1) {
				Hex ne = info;
				ne.a[0] = 6;
				order(ne);
				tr[p][istat[Msk]].push_back(e(istat[code(ne)], 0, 0));
			}
			return ;
		}
		if (num[get_r(p)] > 1) {
			Hex ne = info;
			ne.a[p] = 6;
			order(ne);
			tr[p][istat[Msk]].push_back(e(istat[code(ne)], 0, 0));
			ne.a[p] = ne.a[p - 1];
			order(ne);
			tr[p][istat[Msk]].push_back(e(istat[code(ne)], 0, 1));
		}
		tr[p][istat[Msk]].push_back(e(istat[Msk], 1, 0));
		if (get_r(p - 1) != get_r(p)) {
			Hex ne = info;
			for (int i = 0; i < k; i ++)
				if (get_r(i) == rt[p])
					ne.a[i] = ne.a[p - 1];
			order(ne);
			tr[p][istat[Msk]].push_back(e(istat[code(ne)], 1, 1));
		}
	}
	void contr() {
		for (int i = 1; i <= stnum; i ++)
			for (int p = 0; p < k; p ++)
				search(stat[i], p);
		// for (int i = 0; i < k; i ++)
			// cout << "enum : " << tr[i].size() << endl;
		// for (int i = 0; i < tr[1].size(); i ++) {
			// cout << "#" << i << " : " << endl;
			// output(decode(tr[1][i].fr));
			// output(decode(tr[1][i].to));
			// cout << "msk : " << tr[1][i].e1 << " " << tr[1][i].e2 << endl;
		// }
	}
} using namespace Trans;

ll dp[7][220];
ll dp2[7][220];

Hex st_cur;
void start (int x, int col, ll cost) {
	if (x == k) {
		dp[0][istat[code(st_cur)]] = cost;
		dp2[0][istat[code(st_cur)]] = 1;
		// output(st_cur);
		// cout << cost << endl;
		return ;
	}
	st_cur.a[x] = col + 1;
	start(x + 1, col + 1, cost);
	st_cur.a[x] = col;
	start(x + 1, col, cost + vert[1][x]);
}

int REAL = 0, FAKE = 0, CNT = 0;

int main() {
	ios::sync_with_stdio(false);
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < k; j ++)
			cin >> vert[i][j];
	for (int i = 1; i <= k; i ++)
		for (int j = 1; j < n; j ++)
			cin >> hori[i][j];
	dfs (0, -1);
	contr();
	// cout << "?? " << stnum << endl;
	memset(dp, -1, sizeof dp);
	start (1, 0, 0);
	for (int i = 1; i < n; i ++) {
		for (int p = 0; p < k; p ++) {
			ll v1 = hori[p + 1][i];
			ll v2 = vert[i + 1][p];
			for (int j = 1; j <= stnum; j ++) {
				if (dp[p][j] == -1)
					continue ;
				e cur_tr;
				ll cost, bef;
				for (int l = 0; l < tr[p][j].size(); l ++) {
					cur_tr = tr[p][j][l];
					cost = v1 * cur_tr.e1 + v2 * cur_tr.e2 + dp[p][j];
					bef = dp[p + 1][cur_tr.to];
					if (bef == -1 || bef > cost) {
						dp[p + 1][cur_tr.to] = cost;
						dp2[p + 1][cur_tr.to] = dp2[p][j];
					}
					else if (bef == cost)
						(dp2[p + 1][cur_tr.to] += dp2[p][j]) %= mod;
				}
			}
			// cout << ": " << i << " " << p + 1 << " - ";
			// for (int j = 1; j <= stnum; j ++)
				// cout << dp[p + 1][j] << " ";
			// cout << endl;
			// cout << "$ " << i << " " << p + 1 << " - ";
			// for (int j = 1; j <= stnum; j ++)
			// 	cout << dp2[p + 1][j] << " ";
			// cout << endl;
		}
		for (int j = 1; j <= stnum; j ++) {
			dp[0][j] = dp[k][j];
			dp2[0][j] = dp2[k][j];
		}
		for (int j = 1; j <= stnum; j ++)
			for (int l = 1; l <= k; l ++)
				dp[l][j] = -1, dp2[l][j] = 0;
	}
	cout << dp2[0][1] << endl;
	// cerr << TIME << endl;
	// cerr << REAL << " " << FAKE << " " << CNT << endl;
	return 0;
}