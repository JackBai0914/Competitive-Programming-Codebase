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

vector <pii> ans;
int n;

int rt[1000010];
void dc (int st, int ed) {
	if (ed - st == 0)
		return ;
	if (ed - st == 1) {
		ans.push_back(mp(rt[st], rt[ed]));
		return ;
	}
	dc (st, st + (ed - st + 1) / 2 - 1);
	dc (st + (ed - st + 1) / 2, ed);
	for (int i = st; i < st + (ed - st + 1) / 2; i ++)
		ans.push_back(mp(rt[i], rt[i + (ed - st + 1) / 2]));
}


int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	int mx = 1;
	for(; mx * 2 <= n; mx *= 2);

	for (int i = 1; i <= mx; i ++)
		rt[i] = i;
	dc(1, mx);

	if (mx!=n) {
		for (int i = mx + 1; i <= n; i ++)
			rt[i - mx] = i;
		dc(1, mx);
	}

	cerr << ans.size() << endl;
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i ++)
		cout << ans[i].f << ' ' << ans[i].s << '\n';
	cout << endl;

	return 0;
}