/*
*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
* 
* @author: Xingjian Bai 
* @date: 2020-11-16 15:57:31
* @description: 
* /Users/jackbai/Desktop/matrix_fast_power/matrix.cpp 
* 
* @notes: 
* g++ -fsanitize=address -ftrapv matrix.cpp
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

const int N = 7;
struct matrix {
	ld v[N][N];
	matrix () {memset(v, 0, sizeof v);}
	matrix operator * (const matrix x) const {
		matrix ans;
		F0R(i, N)
			F0R(j, N)
				F0R(k, N)
					ans.v[i][j] += v[i][k] * x.v[k][j];
		return ans;
	}
	void print() {
		F0R(i, N) {
			F0R(j, N)
				cout << v[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	void set_id() {
		memset(v, 0, sizeof v);
		F0R (i, N)
			v[i][i] = 1;
	}
};

matrix fast_power (matrix x, ll t) {
	matrix ans;
	ans.set_id();
	for (; t; t >>= 1, x = x * x)
		if (t & 1) {
			ans = ans * x;
			ans.print();
		}
	return ans;
}

int main() {
	cout << fixed << setprecision(20);
	matrix init;
	// init.v[0][0] = 1;
	matrix trans;
	// trans.v[0][1] = 1.0/3, trans.v[0][3] = 1;
	// trans.v[1][0] = 1.0/2, trans.v[1][2] = 1, trans.v[1][4] = 0.5;
	// trans.v[2][1] = 1.0/3;
	// trans.v[3][0] = 1.0/2;
	// trans.v[4][1] = 1.0/3;
	// trans.v[5][5] = 1;	   trans.v[5][6] = 1;
	// trans.v[6][4] = 1.0/2, trans.v[6][6] = 1;

	ll n;
	cin >> n;
	matrix ans = fast_power(trans, n) * init;
    return 0;
}