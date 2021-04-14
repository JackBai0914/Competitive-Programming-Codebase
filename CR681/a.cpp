/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-02 14:32:53
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

int t;
int n, a[1000010];

int main() {
	cin >> t;
	while (t --) {
		cin >> n;
		bool ok = true;
		int mn = 1e9, bk = 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		for (int i = 1; i <= n; i ++) {
			a[i] -= bk;
			if (a[i] < 0) {
				ok = false;
				break;
			}
			if (a[i] <= mn)	mn = a[i];
			else			bk += a[i] - mn;
		}
		if (!ok)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

    return 0;
}