/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2021-03-26 19:33:30
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
#define PI 3.14159265358979
typedef pair <ld, ld> pll;

int n, par[1010];
vector <int> sons[1010];
pll pos[1010];

ld alpha, cur;
pll calc () {
	cur += alpha;
	return MP(cos(cur), sin(cur));
}
pll add (pll a, pll b) {
	return MP(a.F + b.F, a.S + b.S);
}
void dfs (int x) {
	for (int i = 0; i < sons[x].size(); i ++) {
		int s = sons[x][i];
		if (s == par[x])
			continue ;
		par[s] = x;
		pos[s] = add(calc(), pos[x]);
		dfs (s);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int a, b, i = 1; i < n; i ++) {
    	cin >> a >> b;
    	sons[a].push_back(b);
    	sons[b].push_back(a);
	}
	alpha = PI / n;
	cur = 0;

	pos[1] = MP(0, 0);
	dfs (1);

	cout << fixed << setprecision(10);
	for (int i = 1; i <= n; i ++)
		cout << pos[i].F << " " << pos[i].S << endl;

	// for (int i = 1; i <= n; i ++)
	// 	for (int j = 0; j < sons[i].size(); j ++)
	// 		cout << hypot(pos[i].F - pos[sons[i][j]].F, pos[i].S - pos[sons[i][j]].S) << endl;
    return 0;
}