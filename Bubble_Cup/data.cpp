/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @date: 2020-10-05 21:18:39
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv k.cpp
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pf push_front
#define pb push_back
#define TIME (double)clock()/CLOCKS_PER_SEC
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
const ll INF = 1e18;
const ld eps = 1e-7;

bool flag[10000010];
int s[1000010], pr[1000010], pst = 0;
void init() {
	flag[1] = true;
	FOR(i, 2, 1000001) {
		if (!flag[i])
			pr[++ pst] = i;
		for (int j = 1; j <= pst && i * pr[j] <= 1000000; j ++) {
			flag[i * pr[j]] = true;
			if (i % pr[j] == 0)
				break;
		}
	}
	FOR(i, 1, 1000001)
		s[i] = s[i - 1] + (flag[i] == 0);
}

int n;

int main() {
	ios::sync_with_stdio(false);
	freopen("input.in", "w", stdout);

	cout << 50 << endl;
	FOR(i, 1, 51)
		cout << (1ll<<62) << ' ';
	cout << endl;

	return 0;
}