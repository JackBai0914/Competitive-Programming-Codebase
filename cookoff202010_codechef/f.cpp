/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-18 18:15:50
* @description: 
* /Users/jackbai/Desktop/OI/cookoff202010_codechef/f.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv f.cpp
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

int dp[300030];
int mn[300030];

pii de(int x) {
	for (int i = sqrt(x)+eps; i >= 1; i --)
		if (x % i == 0)
			return MP(i, x / i);
	return MP(1, x);
}

void update (int x) {
	int mx = mn[x], co = dp[x];
	for (int i = 1; i <= mn[x]; i ++) {
		for (int j = i; j <= (300000 - x) / i && (j + i) <= sqrt(i * j) + 10; j ++)
			if (i + j + co < dp[x + i*j]) {
				dp[x + i*j] = i + j + co;
				mn[x + i*j] = i;
			}
	}
}

int main() {
	for (int i = 1; i <= 300000; i ++)
		dp[i] = 1e9;
	dp[1] = 2, mn[1] = 1;
	update (1);
	
	for (int i = 2; i <= 300000; i ++) {
		pii ini = de(i);
		if (ini.F + ini.S < dp[i]) {
			dp[i] = ini.F + ini.S;
			mn[i] = min (ini.F, ini.S);
		}
		update(i);
		// cout << i << " : " << dp[i] << '\n';
	}
	int n, k, x;
	// cerr << TIME << endl;
	int T;
	cin >> T;
	while (T --) {
		cin >> n >> k >> x;
		cout << (dp[k] <= n ? "YES" : "NO") << '\n';
	}


    return 0;
}