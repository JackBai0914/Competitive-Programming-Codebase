/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-01-05 14:00:43
* @description: 
* /Users/jackbai/Desktop/CR694/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
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

int n, m;
ll k[1000010], c[1000010], bar[1000010];

queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --) {
		while (!q.empty())
			q.pop();
		cin >> n >> m;
		for (int i = 1; i <= m; i ++)
			bar[i] = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> k[i];
			bar[k[i]] ++;
		}
		for (int i = 1; i <= m; i ++)
			cin >> c[i];
		for (int i = m; i >= 1; i --)
			for (int j = 1; j <= bar[i]; j ++)
				q.push(i);

		int pt = 1;
		ll ans = 0;
		while (!q.empty() && pt <= m) {
			// cerr << "select: " << q.top() << endl;
			int id = q.front();
			if (id <= pt)
				break;
			q.pop();
			ans += c[pt ++];
			// cerr << ans << endl;
		}
		while (!q.empty()) {
			// cerr << "remain: " << q.top() << endl;
			ans += c[q.front()];
			// cerr << ans << endl;
			q.pop();
		}
		cout << ans << '\n';
	}

    return 0;
}