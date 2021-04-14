/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 * 
 * @author: Xingjian Bai 
 * @date: 2020-09-30 22:26:14
 * @description: 
 * 
 * @notes: 
 * g++ -O2 -fsanitize=address -ftrapv a.cpp 
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
const ll INF = 1e18;

int a[110], b[110], c[110], d[110];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		F0R(i, n)	cin >> a[i];
		F0R(i, n)	cin >> b[i];
		F0R(i, n)	cin >> c[i];
		d[0] = a[0];
		FOR(i, 1, n - 1) {
			if (a[i] == d[i - 1])
				d[i] = b[i];
			else
				d[i] = a[i];
		}
		if (a[n - 1] != d[0] && a[n - 1] != d[n - 2])	d[n - 1] = a[n - 1];
		if (b[n - 1] != d[0] && b[n - 1] != d[n - 2])	d[n - 1] = b[n - 1];
		if (c[n - 1] != d[0] && c[n - 1] != d[n - 2])	d[n - 1] = c[n - 1];
		F0R(i, n)
			cout << d[i] << " ";
		cout << endl;

	}


	return 0;
}