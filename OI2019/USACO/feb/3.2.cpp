#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200020;
typedef long long ll;
typedef pair<int, int> pii;
const long long oo = 1e12;
#define F first
#define S second
int n, T, lyer = 0, C;
pii pt[N];
ll area (pii a, pii b) {return (long long)(a.F - b.F) * (a.S - b.S);}
ll area (int a, int b) {return area(pt[a], pt[b]);}

vector <int> rec[N];
int mn[N];
ll ans[N];


int main() {
	ios::sync_with_stdio(false);
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	cin >> n >> T;
	for (int i = 1; i <= n; i ++)
		cin >> pt[i].F >> pt[i].S;
	rec[0].push_back(0);
	mn[0] = 0;
	pt[++ n] = make_pair(T, T);
	pt[++ n] = make_pair(0, 0);
	sort(pt + 1, pt + n + 1);
	for (int i = 1; i <= n; i ++) {
		if (!lyer || pt[i].S > pt[mn[lyer]].S) {
			mn[++ lyer] = i;
			rec[lyer].push_back(i);
			continue ;
		}
		int l = 1, r = lyer - 1, p, mid;
		while (l != r) {
			mid = (l + r + 1) / 2;
			(pt[mn[mid]].S > pt[i].S ? r = mid - 1 : l = mid);
		}
		p = l + 1;
		mn[p] = i;
		rec[p].push_back(i);
	}

	for (int i = 2; i <= n; i ++)
		ans[i] = oo;

	for (C = 2; C <= lyer; C ++) {
			for (int i = 0; i < rec[C].size(); i ++)
				for (int j = 0; j < rec[C - 1].size(); j ++) {
					ll cur = area(rec[C - 1][j], rec[C][i]);
					if (cur > 0)
						ans[rec[C][i]] = min(ans[rec[C][i]], ans[rec[C - 1][j]] + cur);
				}
	}
	cout << ans[n] << endl;
	return 0;
}