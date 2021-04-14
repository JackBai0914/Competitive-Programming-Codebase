/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-06 15:53:58
* @description: 
* /Users/jackbai/Desktop/CGR12/d.cpp 
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
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;
int a[300030];
int lmn[300030], rmn[300030];
stack <pii> l, r;

struct inc {
	int t, v, dt;
	inc() {}
	inc(int tt , int vv, int dtt) {t = tt, v = vv, dt = dtt;}
	bool operator < (const inc y) const {
		return t < y.t;
	}
	bool operator > (const inc y) const {
		return t > y.t;
	}
};
priority_queue <inc> q;

int ans[300030];

int s[300030], sum = 0;


int main() {
	int t;
	scanf("%d", &t);
	while (t --) {
		while (!l.empty())
			l.pop();
		while (!r.empty())
			r.pop();

		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			ans[i] = s[i] = 0, sum = 0;
			scanf("%d", &a[i]);
			while (!l.empty() && a[i] < l.top().F)
				l.pop();
			lmn[i] = (l.empty() ? 0 : l.top().S);
			l.push(MP(a[i], i));
		}

		for (int i = n; i >= 1; i --) {
			while (!r.empty() && a[i] <= r.top().F)
				r.pop();
			rmn[i] = (r.empty() ? n + 1 : r.top().S);
			r.push(MP(a[i], i));
		}
		for (int i = 1; i <= n; i ++) {
					// cout << i << " : " << lmn[i] << " " << rmn[i] << endl;
			int lg = i - lmn[i];
			int rg = rmn[i] - i;
			if (lg == 1) {
				q.push(inc(rg + lg - 1, a[i], 1));
			}
			else if (rg == 1) {
				q.push(inc(rg + lg - 1, a[i], 1));
			}
			else {
				q.push(inc(rg + lg - 2, a[i], -1));
				q.push(inc(rg + lg - 1, a[i], 1));
				if (rg + lg - 1 != 1) {
					q.push(inc(1, a[i], 1));
				}
			}
		}
		int cur = n + 1;

		while (!q.empty()) {
			inc c = q.top();
			q.pop();
			// cerr << "deal: " << c.t << " " << c.v << " " << c.dt << endl;
			if (c.t < cur - 1) {
				while (cur - 1 != c.t) {
					cur --;
					sum += (s[(n - cur + 1)] == 1);	
					// cerr << "upd: " << cur << " " << sum << endl;
					ans[cur] = (sum == n - cur + 1);
				}
			}
			if (c.v <= n - cur + 1)
				sum -= (s[c.v] == 1);
			s[c.v] += c.dt;
			if (c.v <= n - cur + 1)
				sum += (s[c.v] == 1);
		}
		while (cur != 1) {
			cur --;
			sum += (s[(n - cur + 1)] == 1);	
			// cerr << "upd: " << cur << " " << sum << endl;
			ans[cur] = (sum == n - cur + 1);
		}
		for (int i = 1; i <= n; i ++)
			cout << (ans[i] ? 1 : 0);
		cout << endl;
	

	}

    return 0;
}