#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;

int n, m;
ll wei[500050], lab[500050], pnum[500050], psum[500050], sum[500050], ans[500050];

ll par[500050], tnum[500050];
vector <int> son[500050];

void calc_pnum (int x) {
	tnum[x] = 1;
	int mx_son = 1;
	for (int i = 0; i < son[x].size(); i ++) {
		int s = son[x][i];
		calc_pnum (s);
		tnum[x] += tnum[s];
		pnum[x] -= tnum[s] * (tnum[s] - 1) / 2;
		if (tnum[s] > mx_son) {
			mx_son = tnum[s];
			descend[x] = s;
		}
	}
	pnum[x] += (tnum[x] - 1) * tnum[x] / 2;
}

void calc_psum (int x) {
	psum[x] = pnum[x];
	for (int i = 0; i < son[x].size(); i ++) {
		int s = son[x][i];
		calc_psum (s);
		psum[x] += psum[s] * (lab[s] == 0);
	}
	ans[x] = psum[x] * wei[x];
	sum[x] = ans[x] * lab[x];
	for (int i = 0; i < son[x].size(); i ++)
		sum[x] += sum[son[x][i]];
}

void change_sum (int x, ll dt) {
	do {
		sum[x] += dt;
		x = par[x];
	} while (x);

}

//x is changing from black to white, so some of its ancestors' psum need to change.
void change_psum_to_0 (int x) {
	//force.
	ll add = psum[x];
	x = par[x];
	while (x) {
		psum[x] += add;
		if (lab[x])
			change_sum (x, psum[x] * wei[x] - ans[x]);
		ans[x] = psum[x] * wei[x];
		if (lab[x])
			break;
		x = par[x];
	}
}

//x is changing from white to black, so some of its ancestors' psum need to change.
void change_psum_to_1 (int x) {
	//force.
	ll sub = psum[x];
	x = par[x];
	while (x) {
		psum[x] -= sub;
		if (lab[x])
			change_sum (x, psum[x] * wei[x] - ans[x]);
		ans[x] = psum[x] * wei[x];
		if (lab[x])
			break;
		x = par[x];
	}
}

int find_black_father (int x) {
	//force.
	do {
		if (lab[x])
			return x;
		x = par[x];
	} while (x);
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 2; i <= n; i ++) {
		cin >> par[i];
		son[par[i]].push_back (i);
	}
	for (int i = 1; i <= n; i ++)
		cin >> wei[i];

	calc_pnum (1);
	calc_psum (1);

	for (int tt = 1; tt <= m; tt ++) {
		char c;	int u, w;	cin >> c;
		if (c == 'Q') {
			cin >> u;
			//using Partition + Segtree to calc subtree
			int bf = find_black_father(u);
			if (bf == -1 || lab[u])
				cout << sum[u] << endl;
			else
				cout << sum[u] + wei[bf] * psum[u] << endl;
		}
		if (c == 'M') {
			//since we only maintain DanDian(and calc subtree when querying)
			//we only need to change the ans of this point
			cin >> u >> w;
			wei[u] = w;
			if (lab[u])
				change_sum (u, psum[u] * wei[u] - ans[u]);
			ans[u] = psum[u] * wei[u];
		}
		if (c == 'F') {
			cin >> u;
			if (lab[u]) {
				//change 1 to 0
				change_psum_to_0(u);
				change_sum(u, - ans[u]);
			}
			else {
				//change 0 to 1
				change_psum_to_1(u);
				change_sum(u, ans[u]);
			}
			lab[u] ^= 1;
		}
		// for (int i = 1; i <= n; i ++)	cerr << pnum[i] << ' ';cerr << "pnum " << endl;
		// for (int i = 1; i <= n; i ++)	cerr << psum[i] << ' ';cerr << "psum " << endl;
		// for (int i = 1; i <= n; i ++)	cerr << ans[i] << ' ';cerr <<  "ans " << endl;
	}
	
	return 0;
}