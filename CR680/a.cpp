/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-01 11:10:43
* @description: 
* /Users/jackbai/Desktop/cf/a.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv a.cpp
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

ll p, q;

int main() {
	int t;
	cin >> t;
	while (t -- ) {
		cin >> p >> q;
		if (p % q) {
			cout << p << endl;
			continue;
		}
		ll mn = p;
		for (ll i = 1; i * i <= q; i ++)
			if (q % i == 0) {
				if (i != 1) {
					ll sac = 1, pp = p, qq = q;
					while (pp % i == 0) {
						pp /= i, sac *= i;
					}
					qq /= i;
					while (qq % i == 0) {
						qq /= i, sac /= i;
					}
					if (sac)
						mn = min (mn, sac);
				}
				if (i != q) {
					ll sac = 1, pp = p, qq = q;
					while (pp % (q / i) == 0) {
						// cerr << q/i << " " << pp << " " << sac << endl;
						pp /= (q / i), sac *= (q / i);
					}
					qq /= (q / i);
					while (qq % (q / i) == 0) {
						qq /= (q / i), sac /= (q / i);
					}
					if (sac)
						mn = min (mn, sac);
				}
			}
		cout << p / mn << endl;
	}

    return 0;
}