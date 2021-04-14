/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-28 14:31:34
* @description: 
* /Users/jackbai/Desktop/ECR101/a.cpp 
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

int n, k;
int h[1000010];

pii res[1000010];

int main() {
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> k;
		bool check = true;
		for (int i = 1; i <= n; i ++) {
			cin >> h[i];
			if (i == 1 || i == n)
				res[i] = MP(h[i], h[i]);
			else
				res[i] = MP(h[i], h[i] + k - 1);
			if (i == 1)	continue ;
			res[i].F = max(res[i].F, res[i - 1].F - (k - 1));
			res[i].S = min(res[i].S, res[i - 1].S + (k - 1));
			if (res[i].F > res[i].S) {
				check = false;
				}
		}
		cout << (check? "YES" : "NO") << endl;
	}

    return 0;
}