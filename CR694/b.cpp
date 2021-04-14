/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-05 14:00:53
* @description: 
* /Users/jackbai/Desktop/CR694/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
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
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

ll n, q, w;
ll a[1000010], rem[1000010];
int bar[1000010];

bool vis[1000010];
ll uni[1000010];
ll p[1000010], pst = 0;

void init() {
	uni[1] = 1;
	for (int i = 2; i <= 1000000; i ++) {
		if (vis[i] == 0) {
			p[++ pst] = i;
			uni[i] = i;
		}
		for (int j = 1; j <= pst && 1000000 / i >= p[j]; j ++) {
			vis[i * p[j]] = true;
			uni[i * p[j]] = uni[i] * p[j];
			if (uni[i] % p[j] == 0)
				uni[i * p[j]] /= p[j] * p[j];
			if (i % p[j] == 0)
				break;
		}
	}
}

int ans0, ans1;

int main() {
	ios::sync_with_stdio(false);
	init();

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ans0 = 0, ans1 = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			bar[uni[a[i]]]++;
			ans0 = max (ans0, bar[uni[a[i]]]);
		}

		for (int i = 1; i <= n; i ++)
			if (bar[uni[a[i]]] % 2 == 0 || uni[a[i]] == 1)
				ans1 ++;

		ans1 = max (ans0, ans1);
		// cerr << ans0 << " " << ans1 << " : " << endl;
		cin >> q;
		for (int i = 1; i <= q; i ++) {
			ll w;
			cin >> w;
			if (w == 0)
				cout << ans0 << '\n';
			else
				cout << ans1 << '\n';
		}

		for (int i = 1; i <= n; i ++)
			bar[uni[a[i]]]--;
	}

    return 0;
}