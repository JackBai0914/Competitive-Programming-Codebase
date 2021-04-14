/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-28 09:43:50
* @description: 
*  
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 
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
const int mod = 1000000007; 
const ll oo = 1e18;
const ld eps = 1e-8;
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

int n;

ll query (ll x, ll y) {
	cout << x << " " << y << endl;
	ll ans;
	cin >> ans;
	// cerr << "query " << x << " " << y << " and get " << ans << endl;

	return ans;
}
// void output(ll x, ll y) {
// 	cerr << "solution found: " << x << " " << y << endl;

// 	cout << x << " " << y << endl;
// 	ll ans;	cin >> ans;
// }

void proceed () {
	int ly = 0, ry = 1000000, y = 0;
	int lx = 0, rx = 1000000, x;
	while (lx != rx) {
		if (lx + 1 == rx) {
			ll a1 = query (lx, y);
			if (a1 == 0) 	return ;
			ll a2 = query (rx, y);
			if (a2 == 0) 	return ;
			if (a1 < a2)	rx = lx;
			if (a1 >= a2)	lx = rx;
		}
		else if (lx + 2 == rx) {
			ll a1 = query (lx, y);
			if (a1 == 0) 	return ;
			ll a2 = query (rx, y);
			if (a2 == 0) 	return ;
			if (a1 < a2)	rx = lx + 1;
			if (a1 >= a2)	lx = lx + 1;
		}
		else {
			int gp = (rx - lx) / 3;
			int m1 = lx + gp;
			int m2 = lx + gp + gp;
			// cerr << " ? " << lx << " " << rx << " " << m1 << " " << m2 << endl;
			ll a1 = query (m1, y);
			if (a1 == 0) 	return ;
			ll a2 = query (m2, y);
			if (a2 == 0) 	return ;
			if (a1 < a2)	rx = m2 - 1;
			if (a1 >= a2)	lx = m1;
		}
	}
	x = lx;
	ll mans = query (x, 0);
	if (mans == 0)	return ;
	ll y1 = sqrt(mans);
	query (x, y1);
	// while (ly != ry) {
	// 	if (ly + 1 == ry) {
	// 		ll a1 = query (x, ly);
	// 		if (a1 == 0) 	return ;
	// 		ll a2 = query (x, ry);
	// 		if (a2 == 0) 	return ;
	// 		if (a1 < a2)	ry = ly;
	// 		if (a1 >= a2)	ly = ry;
	// 	}
	// 	else if (ly + 2 == ry) {
	// 		ll a1 = query (x, ly);
	// 		if (a1 == 0) 	return ;
	// 		ll a2 = query (x, ry);
	// 		if (a2 == 0) 	return ;
	// 		if (a1 < a2)	ry = ly + 1;
	// 		if (a1 >= a2)	ly = ly + 1;
	// 	}
	// 	else {
	// 		int gp = (ry - ly) / 3;
	// 		int m1 = ly + gp;
	// 		int m2 = ly + gp + gp;
	// 		ll a1 = query (x, m1);
	// 		if (a1 == 0) 	return ;
	// 		ll a2 = query (x, m2);
	// 		if (a2 == 0) 	return ;
	// 		if (a1 < a2)	ry = m2 - 1;
	// 		if (a1 >= a2)	ly = m1;
	// 	}
	// }

	// y = ly;
	// ll ans = query(x, y);
	// cerr << "reached here " << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while (n --) {
    	// cerr << "preceeding! " << n << endl;
    	proceed();
    }
    return 0;
}