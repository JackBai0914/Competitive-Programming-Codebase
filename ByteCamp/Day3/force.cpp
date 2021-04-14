#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef unsigned long long ll;
typedef pair <ll, ll> pll;

int n, q;
ll a[100010];

namespace LinearBase {
	const int m = 63;
	const ll MX = (1ll << 62);
	struct LB {
		pll b[64], c[64];
		void init() {
			for (int i = 0; i <= m; i ++)
				b[i].F = b[i].S = c[i].F = c[i].S = 0;
		}
		LB() {init();}
		void insert (ll x, ll y) {
			// cerr << "insert : " << x << " " << y << endl;
			for (int i = m - 1; i >= 0 && x; i --)
				if (x >> i & 1) {
					if (c[i].F == 0 && c[i].S == 0) {
						c[i].F = x;
						c[i].S = y;
						for (int j = i - 1; j >= 0; j --)	if (c[i].F >> j & 1)	c[i].F ^= c[j].F, c[i].S ^= c[j].S;
						for (int j = m - 1; j >= 0; j --)	if (c[i].S >> j & 1)	c[i].F ^= b[j].F, c[i].S ^= b[j].S;
						for (int j = m - 1; j > i; j --)	if (c[j].F >> i & 1)	c[j].F ^= c[i].F, c[j].S ^= c[i].S;
						// cerr << "got c " << i << endl;
						return ;
					}
					else
						x ^= c[i].F, y ^= c[i].S;
				}
			// cerr << "reach mid " << endl;
			for (int i = m - 1; i >= 0 && y; i --) {
				// cerr << "prepre : " << y << " " << (y >> i) << endl;
				if (y >> i & 1) {
					if (b[i].F == 0 && b[i].S == 0) {
						b[i].F = x;
						b[i].S = y;
						for (int j = i - 1; j >= 0; j --)	if (b[i].S >> j & 1)	b[i].F ^= b[j].F, b[i].S ^= b[j].S;
						for (int j = m - 1; j > i; j --)	if (b[j].S >> i & 1)	b[j].F ^= b[i].F, b[j].S ^= b[i].S;
						return ;
					}
					else
						x ^= b[i].F, y ^= b[i].S;
				}
			}
		}
		void Insert (ll v) {
			// cerr << "Start Insert: " << v << endl;
			ll x, y, z, pv = (1ll<<(m-1));
			z = v; x = v, y = 0;
			while (z < MX) 	{insert (0, z);z <<= 1;}
			for (int i = 0; i <= m; i ++) {
				insert (y, x);
				y /= 2;
				y+=x%2*pv; 
				x >>= 1; 
			}
		}
		void init (ll v)	{Insert(v);}
		LB (ll v) 			{Insert(v);}
		LB combine (LB lb) {
			// cerr << "Com " << endl;
			LB ans = *this;
			for (int i = 0; i < m; i ++)	ans.insert (lb.b[i].F, lb.b[i].S);
			for (int i = 0; i < m; i ++)	ans.insert (lb.c[i].F, lb.c[i].S);
			return ans;
		// can opt
		}


		ll outp () {
			// cerr << "pre out " << endl;
			// for (int i = 0; i < m; i ++)
				// cerr << i << " : " << b[i].F << " " << b[i].S << endl;
			for (int i = 0; i < m; i ++)
				if (b[i].S != 0)
					return b[i].S;
			// cerr << "outp ABSELUTELY WRONG" << endl;
			// assert (0);
			return -1;
		}
	};
//ATTENTION: those two "for" must not be switched
}using namespace LinearBase;



int main() {
	ios::sync_with_stdio(false);
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];

	cin >> q;

	ll tp, b, c;
	LB pans;
	for (int i = 1; i <= q; i ++) {
		cin >> tp >> b >> c;
		if (tp == 1)
			a[b] = c;
		else {
			LB ans;
			for (int j = b; j <= c; j ++)
				ans.Insert (a[j]);
			cout << ans.outp() << endl;
		}
	}
	return 0;
}