/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-02 14:32:59
* @description: 
* /Users/jackbai/Desktop/cf/b.cpp 
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
const int mod = 998244353; 
const ll INF = 1e18;
const ld eps = 1e-8;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define F0R(i,a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i --)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a: x)
#define debug(x) cerr << "(debug mod) " << #x << " = " << x << endl

struct node {
	int v;
	int lid, rid;
	bool if_key;
} nd[1000010];
int n, m;
int a[1000010], b[1000010], pos[1000010];

int main() {
	int t;
	cin >> t;
	while (t --) {
		ll ans = 1;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			pos[a[i]] = i;
			nd[i].v = a[i];
			nd[i].lid = i - 1;
			nd[i].rid = i + 1;
			nd[i].if_key = false;
			if (i == 1)	nd[i].lid = -1;
			if (i == n)	nd[i].rid = -1;
		}	
		for (int i = 1; i <= m; i ++) {
			cin >> b[i];
			nd[pos[b[i]]].if_key = true;
		}
		for (int i = 1; i <= m; i ++) {
			int num = 0;
			node tg = nd[pos[b[i]]];
			if (tg.lid != -1 && nd[tg.lid].if_key == false)	num ++;
			if (tg.rid != -1 && nd[tg.rid].if_key == false)	num ++;
			(ans *= num) %= mod;

			if (tg.lid != -1)	nd[tg.lid].rid = tg.rid;
			if (tg.rid != -1)	nd[tg.rid].lid = tg.lid;
		}	
		cout << ans << '\n';
	}

    return 0;
}