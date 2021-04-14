#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <int, int> pii;
ull x = 233;

struct matrix {
	int v[128][128];
	matrix () {memset(v, 0, sizeof  v);}
	matrix operator * (const matrix x) const {
		matrix ans;
		for (int i = 0; i < 128; i ++)
			for (int j = 0; j < 128; j ++) 
				for (int k = 0; k < 128; k ++)
					ans.v[i][j] ^= v[k][j] * x.v[i][k];
		return ans;
	}
	void outp() {
		for (int i = 0; i < 128; i ++) {
			for (int j = 0; j < 128; j ++) 
				cerr << v[i][j];
			cerr << endl;
		}
	}
};
matrix m[3030], ini, t13, t7, t17, R, X;

ull ran(){
	static ull x=233;
	x^=x<<13;
	cerr << "p1: " << x << endl;
	x^=x>>7;
	cerr << "p2: " << x << endl;
	x^=x<<17;
	cerr << "p3 : " << x << endl;
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	for (int i = 64; i < 128; i ++) {
		t13.v[i][i] = t7.v[i][i] = t17.v[i][i] = 1;
		if (i - 64 >= 13)	t13.v[i][i-13] = 1;
		if (i - 64 >= 17)	t17.v[i][i-17] = 1;
		if (i - 64 + 7 < 64)t7.v[i][i+7] = 1;
	}
	R = t13 * t7 * t17;
	for (int i = 0; i < 64; i ++) {
		X.v[64+i][0] = x % 2;
		x /= 2;
	}

	for (int i = 0; i < 128; i ++)
		for (int j = 0; j < 128; j ++) {
			if (R.v[i][j] == 1)	m[1].v[i][j] = m[0].v[i][j] = 1;
			else if (i == j)	m[1].v[i][j] = m[0].v[i][j] = 1;
			if (i >= 64 && j >= 64)
				m[0].v[i-64][j] = R.v[i][j];
		}

	int a, b, c;
	for (int i = 2; i <= 3000; i ++) {
		cin >> a >> b >> c;
		m[a] = m[b] * m[c];
	}

	matrix ans = X * m[3000];
	
	ull y = 0;
	for (int i = 63; i >= 0; i --) {
		y *= 2;
		y += ans.v[i][0];
	}
	cout << y << endl;



	// int a, b, c;
	// for (int i = 2; i <= 21; i ++) {
	// 	cin >> a >> b >> c;
	// 	m[a] = m[b] * m[c];
	// }
	// ini = ini * m[21];
	// cout << ini.v[0][0] << endl;
	// // 
	// // for (int i = 1; i <= 10; i ++) {
	// // 	cout << ran() << endl;
	// // }
	return 0;
}