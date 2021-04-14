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
const ll INF = 1e18;

int n, k;
bool eq = 0;
int a[1000010];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		eq = true;
		cin >> n >> k;
		F0R(i, n) {
			cin >> a[i];
			eq &= (a[i] == a[0]);
		}
		if (!eq && k == 1) {
			cout << -1 << endl;
			continue ;
		}
		if (eq && k == 1) {
			cout << 1 << endl;
			continue ;
		}
		int cv = 1, lst = a[0], cnt = 1;
		FOR(i, 1, n) {
			if (a[i] != lst) {
				lst = a[i];
				cv ++;
			}
			if (cv == k + 1) {
				cnt ++;
				cv = 2;
				// cerr << "break st: " << a[i] << endl;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}