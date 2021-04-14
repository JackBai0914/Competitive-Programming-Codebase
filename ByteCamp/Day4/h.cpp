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
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int n, l;
int a[110];
ld b[110];

priority_queue <pair <ld, int> > q;
ll ans[110];
ll dep[110], par[220];
ll fans[220];
pair <ld, ll> proceed () { 
	int pt = n;
	ld ans = 0;
	ll depth = 0;
	memset(par, 0, sizeof par);
	while (!q.empty())
		q.pop();
	for (int i = 1; i <= n; i ++) {
		q.push (MP(-b[i], i));
		dep[i] = 0;
	}
	
	while (!q.empty()) {
		pair <ld, int> fir = q.top();
		q.pop();
		if (q.empty())
			return MP (ans, depth);
		pair <ld, int> sec = q.top();
		q.pop();
		dep[++ pt] = max(dep[fir.S], dep[sec.S]) + 1;
		par[fir.S] = par[sec.S] = pt;
		ans += -(fir.F + sec.F);
		depth = max (depth, dep[pt]);
		q.push (MP(fir.F+sec.F, pt));
	}
	return MP (ans, depth);
}

ll rec;
ll rans[220];
ll rans2[220];

void calc () {
	// cerr << "calc " << endl;
	for (int i = 1; i <= n; i ++) {
		fans[i] = 0;
		int p = par[i];
		while (p) {
			fans[i] ++;
			// cerr << "par: " << p << " " << par[p] << endl;
			p = par[p];
		}
		rans2[i] = fans[i];
	}
}

bool process (ld C) {
	for (int i = 1; i <= n; i ++)
		b[i] = a[i] + C;
	pair <ld, ll> pans = proceed();

	if (pans.S > l)
		return false;
	
	calc();
	ll real_ans = 0;
	for (int i = 1; i <= n; i ++)
		real_ans += (ll)rans2[i] * a[i];
	cerr << "preceed: " << C << " : " << pans.F << " " << pans.S << " -- " << real_ans << endl;
	if (real_ans < rec) {
		rec = real_ans;
		for (int i = 1; i <= n; i ++)
			rans[i] = rans2[i];
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	while (cin >> n >> l) {
		rec = (1ll<<60); 
		if (n == 0 && l == 0)
			return 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		if (n == 1) {
			cout << a[1] << endl << 1 << endl;
			continue ;
		}

		if (process (0)) {
			cout << rec << endl;
			for (int i = 1; i <= n; i ++)
				cout << rans[i] << " ";
			cout << endl;
			continue ;
		}
		ld st = 0, ed = 1e12;
		while (ed - st >= 0.0000001) {
			ld mid = (st + ed) * 0.5;
			if (process(mid))
				ed = mid;
			else
				st = mid;
		}

		ll real_ans = 0;
		for (int i = 1; i <= n; i ++)
			real_ans += (ll)rans[i] * a[i];
		cout << real_ans << endl;
		for (int i = 1; i <= n; i ++)
			cout << rans[i] << " ";
		cout << endl;
	}
	
	return 0;
}