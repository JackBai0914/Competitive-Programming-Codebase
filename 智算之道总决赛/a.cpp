#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <map>
#define TIME (double)clock()/CLOCKS_PER_SEC
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int q;
string s, t;

ull inp[200020];
string in2[200020];
int st_pos[200020], found[200020];
map <ull, int> mp;

const ull fac = 2333;
const int BOUND = 1;
ull fa[400040], sum[400040];
void init() {
	//cerr << "? " << endl;
	sum[0] = s[0] * fa[0];
	for (int i = 1; i < s.size(); i ++)
		sum[i] = sum[i - 1] + fa[i] * s[i];
	//cerr << "? " << endl;
	for (int i = 0; i < s.size() / 2; i ++) {
		ull cur = 0;
		for (int j = 0; j < BOUND && i + j < s.size(); j ++) {
			cur += fa[j] * s[i + j];
			// cerr << "search " << cur << endl;
			if (mp[cur]) {
				int id = mp[cur];
				st_pos[id] = i;
				found[id] = 1;
				mp[cur] = 0;
				// cerr << "found: " << mp[cur] << endl;
			}
		}
	}
	//cerr << "? " << endl;
}
ull calc (string t) {
	ull ans = 0;
	for (int i = 0; i < t.size(); i ++)
		ans += fa[i] * t[i];
	return ans;
}



int main() {
	ios::sync_with_stdio(false);
	fa[0] = 1;
	for (int i = 1; i <= 400000; i ++)
		fa[i] = fa[i - 1] * fac;
	cin >> s >> q;

	int len = s.size();
	s = s + s;
	for (int tt = 1; tt <= q; tt ++) {
		st_pos[tt] = 2333333;
		cin >> t;
		inp[tt] = calc(t);
		in2[tt] = t;
		if (mp[inp[tt]])
			st_pos[tt] = -mp[inp[tt]];
		else
			mp[inp[tt]] = tt;
	}
	init();

	for (int tt = 1; tt <= q; tt ++) {
		string t = in2[tt];
		ull vt = inp[tt];
		//cerr << "vt " << " " << vt << endl;
		if (t.size() > BOUND) {
			for (int i = 0; i + t.size() <= s.size(); i ++)  {
				ull mat = (i? sum[i + t.size() - 1] - sum[i - 1] : sum[i + t.size() - 1]);
				if (vt * fa[i] == mat) {
					st_pos[tt] = i;
					break;
				}
			}
		}


		if (st_pos[tt] < 0)
			st_pos[tt] = st_pos[-st_pos[tt]];

		if (st_pos[tt] == 2333333) {
			cout << "-1 -1" << '\n';
		}
		else {
			int stx = 1, sty = st_pos[tt] + 1;
			if (sty + t.size() - 1 > len) {
				stx += sty + t.size() - 1 - len;
				sty -= sty + t.size() - 1 - len;
			}
			cout << stx << " " << sty << '\n';
		}
	}
	//cerr << "TIME: " << TIME << endl;
	return 0;
}