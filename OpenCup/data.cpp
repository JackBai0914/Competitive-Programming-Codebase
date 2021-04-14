/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-10-11 12:20:04
* @description: 
* /Users/jackbai/Desktop/OI/OpenCup/data.cpp 
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


int mp[5110][5110];

int seed() {
	ll seed;
	freopen("seed.in", "r", stdin);
	cin >> seed;
	fclose(stdin);
	seed = seed = seed * 233 % 1000000009;
	freopen("seed.in", "w", stdout);
	cout << seed;
	fclose(stdout);
	return seed;
}

int main() {
	int sd = seed();
	freopen("inp.in", "w", stdout);
	srand(sd);
	int n = rand() % 100 + 50;
	int m = rand() % 100 + rand() % n * (rand() % 50 + 1) / 2 + 1;
	// cerr << "here " << n << " " << m << endl;
	// cout << 1 << endl;

	// int n = 8;
	// int m = 8*7/2;
	cout << n << " " << m << '\n';
	FOR(i, 0, m) {
		// cout << i + 1 << " " << i + 2 << '\n';
		int x, y;
		do {
			x = rand() % n + 1;
			y = rand() % n + 1;
		} while (x == y || mp[x][y] == 1);
		mp[x][y] = mp[y][x] = 1;
		cout << x << " " << y << '\n';
	}

	// FOR(i, 1, n + 1)
	// 	FOR(j, i + 1, n + 1)
	// 		cout << i << " " << j << '\n';

    return 0;
}