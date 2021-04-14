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

int n, l;
int a[1000010];

ld s1[1000010], s2[1000010];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> l;
		s1[0] = s2[0] = 0;
		a[0] = 0;
		a[n + 1] = l;
		FOR (i, 1, n + 1)
			cin >> a[i];
		s1[0] = 0;
		FOR (i, 1, n + 2)
			s1[i] = s1[i - 1] + (ld)(a[i] - a[i - 1]) / i;
		s2[n+1] = 0;
		ROF (i, 0, n + 1)
			s2[i] = s2[i + 1] + (ld)(a[i + 1] - a[i]) / (n + 1 - i);
		int id;
		FOR (i, 0, n + 1) {
			if (s1[i] <= s2[i] + eps && s1[i + 1] + eps >= s2[i + 1])
				id = i;
		}
		ld ti = max (s1[id], s2[id + 1]);
		ld dis1 = (ti - s1[id]) * (id + 1);
		ld dis2 = (ti - s2[id + 1]) * (n + 1 - id);
		ld add = (ld)(a[id + 1] - a[id] - dis1 - dis2) / (n + 2);
		cout << fixed << setprecision(10) << ti + add << endl;
	}

	return 0;
}