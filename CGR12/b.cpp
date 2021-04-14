/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-12-06 14:33:33
* @description: 
* /Users/jackbai/Desktop/CGR12/b.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv b.cpp
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
pii pos[110];
int mp[110][110];

int main() {
	int t;
	cin >> t;
	while (t --) {
		cin >> n >> k;
		for (int i = 1; i <= n; i ++)
			cin >> pos[i].F >> pos[i].S;
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			pii p = pos[i];
			bool check = true;
			for (int j = 1; j <= n; j ++)
				if (abs(p.F - pos[j].F) + abs(p.S - pos[j].S) > k)
					check = false;
			if (check) {
				ans = i;
				break;
			}
		}
		if (ans)
			cout << 1 << endl;
		else
			cout << -1 << endl;
	}

    return 0;
}