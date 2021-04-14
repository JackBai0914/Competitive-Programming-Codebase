/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-10 17:30:54
* @description: 
* /Users/jackbai/Desktop/OI/CGR_Codeforces/e.cpp 
* 
* @notes: 
* g++ -O2 -fsanitize=address -ftrapv e.cpp
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
#include <bits/stdc++.h>
#define F first
#define S second
#define MP make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

vector <pair<pair<long long, long long>, char> > rec;
ll x;
void mult(ll v, ll t) {
	for (ll n = 1; n * 2 <= t; n *= 2)
		rec.push_back(MP(MP(n*v, n*v), '+'));
	ll cur = 0;
	for (ll x = 1; t; x = x * 2, t /= 2)
		if (t & 1) {
			rec.push_back(MP(MP(cur, v*x), '+'));
			cur += v*x;
		}
}

ll gcd (ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}


ll exgcd(ll a , ll &x1 , ll b , ll &x2){
	if(!a){
		// cerr << "end: " << a << " " << b << endl;
		x1 = 0 , x2 = b / abs(b);
		return b;
	}
	ll y1 , y2;
	ll g = exgcd(b % a , y1 , a , y2);
	x2 = y1;
	x1 = y2 - (b / a) * x2;
	// cerr << a << " " << x1 << " " << a*x1 << " " << b << " " << x2 << " " << b*x2 << endl;
	return g;
}

void shuffle (vector <int> v, vector <int> x) {
	random_shuffle(v.begin(), v.end());

}


int mp[10][10];
ll work(ll v) {
	// cerr << "work: " << v << endl;
	vector <ll> cand0;
	vector <ll> cand;

	for (int n = 1; n <= 10; n ++) {
		rec.push_back(MP(MP(n*v, v), '+'));
		cand0.push_back(n*v);
	}

	for (int i = 0; i < 20; i ++) {
		int mul = rand() % (3 * v) + 1;
		cand0.push_back(mul * v);
		mult(v, mul);
	}
	for (int i = 0; i < cand0.size(); i ++)
		for (int j = i+1; j < cand0.size(); j ++) {
			if (cand0[i] == cand0[j])
				continue ;
			cand.push_back(cand0[i]^cand0[j]);
			rec.push_back(MP(MP(cand0[i], cand0[j]), '^'));
		}

	for (int i = 0; i < 50; i ++) {
		int a = rand() % cand.size();
		int b = rand() % cand.size();
		cand.push_back(cand[a]^cand[b]);
		rec.push_back(MP(MP(cand[a], cand[b]), '^'));
	}
	for (int i = 0; i < 50; i ++) {
		int a = rand() % cand.size();
		int b = rand() % cand.size();
		cand.push_back(cand[a]+cand[b]);
		rec.push_back(MP(MP(cand[a], cand[b]), '+'));
	}
	for (int i = 0; i < 50; i ++) {
		int a = rand() % cand.size();
		int b = rand() % cand.size();
		cand.push_back(cand[a]^cand[b]);
		rec.push_back(MP(MP(cand[a], cand[b]), '^'));
	}


	ll g = 1e18;
	ll x, y;

	for (int i = 0; i < cand.size(); i ++)
		for (int j = i+1; j < cand.size(); j ++) {
			if (cand[i] == cand[j])
				continue ;
			ll cg = gcd(cand[i], cand[j]);
			if (cg < g || (cg == g && max(cand[i], cand[j]) < max(x, y)))
				g = cg, x = cand[i], y = cand[j];
		}

	ll gx = x / g, gy = y / g;
	// cerr << "tg: " << g << " " << x << " " << y << " " << gx << " " << gy << endl;

	if (gx % 2 && gy % 2) {
		rec.push_back(MP(MP(y, y), '+'));
		gy *= 2;
		y *= 2;
	}
	if (gy % 2) {
		swap (x, y);
		swap (gx, gy);
	}

	ll c1 = 0, c2 = 0;
	exgcd(gx, c1, -gy, c2);
	if (c1 < 0 || c2 < 0)
		c1 += gy, c2 += gx;
	// cerr << "solution: " << c1 << " " << c2 << " : " << x * c1 << " " << y * c2 << endl;
	mult(x, c1);
	mult(y, c2);
	rec.push_back(MP(MP(x*c1, y*c2), '^'));
	return g;
}

int main() {
	srand(time(0));
	scanf("%lld", &x);
	// 0
	rec.push_back(MP(MP(x, x), '^'));
	while (x != 1) {
		x = work(x);
	}

	printf("%lu\n", rec.size());
	for (int i = 0; i < rec.size(); i ++) {
		printf("%lld %c %lld\n", rec[i].F.F, rec[i].S, rec[i].F.S);
	}
    return 0;
}