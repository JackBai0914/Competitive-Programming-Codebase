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
ll mod = 998244353;
ll a = 10007;
ll b = 18980504;

struct matrix {
	ll v[2][2];
	matrix () {memset(v, 0, sizeof  v);}
	matrix operator * (const matrix x) const {
		matrix ans;
		for (int i = 0; i < 2; i ++)
			for (int j = 0; j < 2; j ++) 
				for (int k = 0; k < 2; k ++)
					(ans.v[i][j] += v[k][j] * x.v[i][k]) %= mod;
		return ans;
	}
};
matrix m[3030], ini;

ull ran(){
	static ull x=233;
	x^=x<<13;
	x^=x>>7;
	x^=x<<17;
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	m[0].v[0][0] = a, m[0].v[1][1] = 1;
	m[1].v[0][0] = 1, m[1].v[0][1] = b, m[1].v[1][1] = 1;
	ini.v[1][0] = 1;

	int a, b, c;
	for (int i = 2; i <= 21; i ++) {
		cin >> a >> b >> c;
		m[a] = m[b] * m[c];
	}
	ini = ini * m[21];
	cout << ini.v[0][0] << endl;
	// 
	// for (int i = 1; i <= 10; i ++) {
	// 	cout << ran() << endl;
	// }
	return 0;
}