#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair <ull, ull> puu;

namespace Hash {
	const ull mod1 = 1e9 + 7;
	const ull mod2 = 1e9 + 9;
	const ull q = 233;
	ull imod1;
	ull imod2;
	ull mi1[200020], mi2[200020], imi1[200020], imi2[200020];
	puu hash[200020];
	ull kmi (long long x, long long t, long long mod) {
		ull ans = 1;
		for (x %= mod; t; t >>= 1, (x *= x) %= mod)
			if (t % 2)
				(ans *= x) %= mod;
		return ans;
	}
	void ini () {
		imod1 = kmi (q, mod1 - 2, mod1);
		imod2 = kmi (q, mod2 - 2, mod2);
		// cerr << "sdf " << imod1 << " " << imod2 << endl;
		mi1[0] = mi2[0] = imi1[0] = imi2[0] = 1;
		for (int i = 1; i <= 200000; i ++) {
			mi1[i] = mi1[i - 1] * q % mod1;
			mi2[i] = mi2[i - 1] * q % mod2;
			imi1[i] = imi1[i - 1] * imod1 % mod1;
			imi2[i] = imi2[i - 1] * imod2 % mod2;
		}
	}
	void deal (string s) {
		
		hash[0] = MP(s[0], s[0]);
		for (int i = 1; i < s.size(); i ++)
			hash[i] = MP((hash[i - 1].F * q + s[i]) % mod1,
						 (hash[i - 1].S * q + s[i]) % mod2);
		for (int i = 0; i < s.size(); i ++) {
			// cout << hash[i].F << " " << hash[i].S << endl;
		}
	}
	puu add (puu a, puu b) {
		return MP (a.F + b.F, a.S + b.S);
	}
	puu sub(puu a, puu b) {
		return MP (a.F - b.F, a.S - b.S);
	}
	puu Mod (puu a, puu b) {
		return MP (a.F % b.F, a.S % b.S);
	}
	puu mul (puu a, puu b) {
		return MP (a.F * b.F, a.S * b.S);
	}
	puu extract (int st, int ed) {
		if (!st)
			return hash[ed];
		puu ans = sub(hash[ed], Mod(mul (hash[st - 1], MP(mi1[ed - st + 1], mi2[ed - st + 1])), MP(mod1, mod2)));
		ans = Mod(add(ans, MP(mod1, mod2)), MP(mod1, mod2));
		// cout << "ex : " << st << " " << ed << " " << ans.F << " " << ans.S << endl;
		return ans;
	}

} using namespace Hash;


int na, nb, m;
int al[400040], ar[400040], bl[400040], br[400040];

namespace Graph {
	int point[400040], val[400040], te = 0;
	int ind[400040];
	struct e {int fr, to, next;} edge[4000040];
	void add (int u, int v) {
		// cout << "add " << u << " " << v << endl;
		ind[v] ++;
		te ++;
		edge[te].fr = u;
		edge[te].to = v;
		edge[te].next = point[u];
		point[u] = te;
	}
	queue <int> q;
	int dis[400040];
	int topo () {
		for (int i = 1; i <= na + nb; i ++)
			dis[i] = val[i];
		for (int i = 1; i <= na + nb; i ++)
			if (ind[i] == 0)
				q.push(i);
		int cnt = 0;
		int fans = 0;
		while (!q.empty()) {
			int x = q.front();
			// cout << ": " << x << " " << dis[x] << endl;
			q.pop();
			cnt ++;
			fans = max(fans, dis[x]);
			for (int e = point[x]; e; e = edge[e].next) {
				int to = edge[e].to;
				// cout << "UPD: " << to << " " << dis[to] << " " << dis[x] + val[to] << endl;
				dis[to] = max(dis[to], dis[x] + val[to]);
				if ((-- ind[to]) == 0)
					q.push(to);
			}
		}
		if (cnt != na + nb)
			return -1;
		return fans;
	}

	
} using namespace Graph;


void work() {
	string s;
	cin >> s;
	deal(s);
	cin >> na;
	te = 0;
	for (int i = 1; i <= na; i ++) {
		cin >> al[i] >> ar[i];
		al[i] --;
		ar[i] --;
		val[i] = ar[i] - al[i] + 1;
		// cerr << "val : " << val[i] << endl;
	}
	cin >> nb;
	for (int i = 1; i <= nb; i ++) {
		cin >> bl[i] >> br[i];
		bl[i] --;
		br[i] --;
		val[na + i] = 0;
	}
	for (int i = 1; i <= na + nb; i ++)
		point[i] = ind[i] = 0;
	cin >> m;
	for (int a, b, i = 1; i <= m; i ++) {
		cin >> a >> b;
		add (a, na + b);
	}
	// cout << "------" << endl;
	for (int i = 1; i <= na; i ++)
		for (int j = 1; j <= nb; j ++)
			if (ar[i] - al[i] >= br[j] - bl[j] && 
				extract(al[i], al[i] + br[j] - bl[j]) ==
				extract(bl[j], br[j])) {
				add (j + na, i);
//				if (te / 4 > na + nb + 5) {
//					cout << -1 << endl;
//					return ;
//				}
			}
	cout << topo() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	ini ();
	int T;
	cin >> T;
	while (T --)
		work();

	return 0;
}