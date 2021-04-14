/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-30 08:57:38
* @description: 
* /Users/jackbai/Desktop/CCC/1.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 1.cpp
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

int n, m;
const int K = 32;

pair<int, int> sum[1000010];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		sum[i].S = -i;
		sum[i].F = 0;
	}

	int mx = -1e9, id = 0;

	for (int i = 1; i <= n; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ra, rb;
		ld Ea = 1 / (1 + pow(10, (rb - ra) / 400));
		
		if (b > mx) {
			
		}

		if (d > mx)		mx = d, id = c;
		else if (d == mx)	id = min (c, id);
	}

	cout << id << " " << mx << endl;
    return 0;
}