/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-14 15:04:08
* @description: 
* /Users/jackbai/Desktop/ER/d.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv d.cpp
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

int n, m;
int op[1000010];
int s[1000010], mn[1000010], mx[1000010];
int s2[1000010], mn2[1000010], mx2[1000010];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> m;
		mn[0] = mx[0] = s[0] = 0;
		for (int i = 1; i <= n; i ++) {
			char c;
			cin >> c;
			op[i] = (c == '+' ? 1 : -1);
			s[i] = s[i - 1] + op[i];
			mn[i] = min (mn[i - 1], s[i]);
			mx[i] = max (mx[i - 1], s[i]);
		}
		s2[n + 1] = mn2[n + 1] = mx2[n + 1] = 0;
		for (int i = n; i >= 0; i --) {
			s2[i] = s2[i + 1] - op[i];
			mn2[i] = min (mn2[i + 1], s2[i]);
			mx2[i] = max (mx2[i + 1], s2[i]);
		}
		for (int st, ed, i = 1; i <= m; i ++) {
			cin >> st >> ed;
			int lb = 0, ub = 0;
			int gap = s[n] + -(s[ed] - s[st - 1]);
			lb = min (lb, mn[st - 1]);
			ub = max (ub, mx[st - 1]);
			lb = min (lb, mn2[ed + 1] + gap);
			ub = max (ub, mx2[ed + 1] + gap);
			// cerr << " : " << mx2[ed + 1] << " " << gap << " " << ub << endl;
			cout << (ub - lb + 1) << '\n';
		}
	}

    return 0;
}