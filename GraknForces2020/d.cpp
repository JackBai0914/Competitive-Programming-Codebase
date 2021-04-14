/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @date: 2020-09-30 22:26:14
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv a.cpp -o a 
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

//loops
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)

//debug
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

//constants
const int MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const ld eps = 1e-8;

int n, m;
int a[2020], b[2020], c[2020], d[2020];

vector<pii> cs;



int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	F0R(i, n)	cin >> a[i] >> b[i];
	F0R(i, m) {
		int mxa, mxb;
		cin >> c[i] >> d[i];
		F0R(j, n)
			cs.push_back(mp(max(0, c[i] - a[j] + 1), max(0, d[i] - b[j] + 1)));
	}
	sort(cs.begin(), cs.end());
	int mxb = 0, ans = cs[cs.size() - 1].f;
	// trav(a, cs)
		// cerr << a.f << " " << a.s << endl;
	R0F (i, cs.size()) {
		mxb = max (mxb, cs[i].s);
		if (i == 0 || cs[i].f != cs[i - 1].f) {
			ans = min (ans, max(0, (i ? cs[i - 1].f : 0) + mxb));
		}
	}
	cout << ans << endl;



	return 0;
}