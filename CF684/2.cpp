/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-17 14:27:49
* @description: 
* /Users/jackbai/Desktop/OI/CF684/2.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv 2.cpp
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


const int maxn = 1e5;
const int maxk = 1000;

ll n, m, k, ans = 0;
int point[100010], te = 1;
struct e {int to, next};
void add (int u, int v) {edge[++ te].to = v, edge[te].next = point[u]; point[u] = te;}


vector <int> some[maxk], none[maxk], all[maxk];

void dfs(int d, int an, int sn, int nn)
{
	if (an)
	if(!sn && !nn) ans = max(ans, an);
	int u = some[d][0];
	for(int i = 0; i < sn; ++i)
	{
		int v = some[d][i];
		if(mp[u][v]) continue;
		for(int j = 0; j < an; ++j)
		all[d+1][j] = all[d][j];
		all[d+1][an] = v;
		int tsn = 0, tnn = 0;
		for(int j = 0; j < sn; ++j)
		if(mp[v][some[d][j]])
		some[d+1][tsn++] = some[d][j];
		for(int j = 0; j < nn; ++j)
		if(mp[v][none[d][j]])
		none[d+1][tnn++] = none[d][j];
		dfs(d+1, an+1, tsn, tnn);
		some[d][i] = 0, none[d][nn++] = v;
	}
}
int work()
{
	for(int i = 1; i <= n; i ++)
		some[1].push_back(i);
	dfs(1, 0, n, 0);
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t --)
	{
		cin >> n >> m >> k;
		for (int i = 0; i <= n; i ++)
			point[i] = 0;
		te = 1;

		for(int a, b, j = 1; j <= m; ++j) {
			cin >> a >> b;
			add (a, b);
			add (b, a);
		}

		if (k * (k - 1) / 2 > m) {
			cout << -1 << '\n';
			continue ;
		}

	}
	return 0;
}