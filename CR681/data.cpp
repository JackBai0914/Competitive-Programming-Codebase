/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-02 16:16:30
* @description: 
* /Users/jackbai/Desktop/cf/data.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv data.cpp
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

ll get_s() {
	freopen("seed", "r", stdin);
	ll seed;
	cin >> seed;
	fclose(stdin);
	seed = seed * 23333 % MOD;
	freopen("seed", "w", stdout);
	cout << seed << endl;
	fclose(stdout);
	return seed;
}

int main() {
	ios::sync_with_stdio(false);
	srand(get_s());
	// cerr << "fine " << endl;
	const int n = 20;
	const int m = 40;
	freopen("inp2.in", "w", stdout);
	cout << n << " " << m << endl;
	// cerr << rand() << endl;
	for (int i = 1; i < n; i ++) {
		if (rand() % 2)
			cout << i << " " << i + 1 << '\n';
		else
			cout << i + 1 << " " << i << '\n';
	}

	for (int i = n; i <= m; i ++) {
		int a, b;
		do {
			a = rand() % n + 1;
			b = rand() % n + 1;
		} while (a == b);
		cout << a << " " << b << '\n';
	}
    return 0;
}